#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <windows.h>
using namespace std;

// Чтение данных из файла
void readInput(const string& filename, int& n, string& matrixFile, string& resultFile) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }
    input >> n;
    input >> matrixFile;
    input >> resultFile;
    input.close();
}

// Чтение матрицы из файла
void readMatrix(const string& filename, int n, vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }
    for (int i = 0; i < n - 1; ++i) {
        input >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        input >> b[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        input >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        input >> d[i];
    }
    input.close();

    // Проверка на трехдиагональность
    if (any_of(a.begin(), a.end(), [](double val) { return val == 0; }) ||
        any_of(c.begin(), c.end(), [](double val) { return val == 0; })) {
        cerr << "Ошибка: Матрица не является трехдиагональной." << endl;
        exit(1);
    }
}

// Преобразование системы к виду x^{k+1} = Cx^k + y
void convertSystem(int n, const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<vector<double>>& C, vector<double>& y) {
    C.assign(n, vector<double>(n, 0.0));
    y.assign(n, 0.0);
    for (int i = 0; i < n; ++i) {
        y[i] = d[i] / b[i];
        if (i > 0) {
            C[i][i - 1] = -a[i - 1] / b[i];
        }
        C[i][i] = 0.0; // Диагональные элементы равны 0
        if (i < n - 1) {
            C[i][i + 1] = -c[i] / b[i];
        }
    }
}

// Разбиение матрицы C на CL, CD и CU
void decomposeMatrix(int n, const vector<vector<double>>& C, vector<vector<double>>& CL, vector<vector<double>>& CD, vector<vector<double>>& CU) {
    CL.assign(n, vector<double>(n, 0.0));
    CD.assign(n, vector<double>(n, 0.0));
    CU.assign(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j) {
                CL[i][j] = C[i][j];
            }
            else if (i == j) {
                CD[i][j] = C[i][j];
            }
            else {
                CU[i][j] = C[i][j];
            }
        }
    }
}

// Вычисление нормы 1 и нормы бесконечность матрицы C
double matrixNorm1(const vector<vector<double>>& C) {
    double maxSum = 0.0;
    for (int j = 0; j < C.size(); ++j) {
        double sum = 0.0;
        for (int i = 0; i < C.size(); ++i) {
            sum += fabs(C[i][j]);
        }
        maxSum = max(maxSum, sum);
    }
    cout << "Норма 1 матрицы C: " << maxSum << endl;
    return maxSum;
}

double matrixNormInfinity(const vector<vector<double>>& C) {
    double maxSum = 0.0;
    for (const auto& row : C) {
        double sum = 0.0;
        for (double val : row) {
            sum += fabs(val);
        }
        maxSum = max(maxSum, sum);
    }
    cout << "Норма бесконечность матрицы C: " << maxSum << endl;
    return maxSum;
}

// Метод простой итерации с экспериментальным подбором tau
void simpleIterationMethod(int n, const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x, double epsilon) {
    vector<double> prevX(n, 0.0);
    int iteration = 0;
    bool converge;
    double tau = 0.1;  // Начальное значение tau

    do {
        converge = true;
        for (int i = 0; i < n; ++i) {
            double sum = d[i];
            if (i > 0) {
                sum -= a[i - 1] * prevX[i - 1];
            }
            if (i < n - 1) {
                sum -= c[i] * prevX[i + 1];
            }
            double newX = prevX[i] + tau * (sum - b[i] * prevX[i]);
            if (fabs(newX - prevX[i]) > epsilon) {
                converge = false;
            }
            x[i] = newX;
        }
        prevX = x;
        iteration++;
        tau += 0.1;  // Изменение tau для экспериментального подбора
    } while (!converge);

    cout << "Метод простой итерации завершен за " << iteration << " итераций с tau = " << tau << "." << endl;
}

// Метод Якоби
void jacobiMethod(int n, const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x, double epsilon) {
    vector<double> prevX(n, 0.0);
    int iteration = 0;
    bool converge;

    do {
        converge = true;
        for (int i = 0; i < n; ++i) {
            double sum = d[i];
            if (i > 0) {
                sum -= a[i - 1] * prevX[i - 1];
            }
            if (i < n - 1) {
                sum -= c[i] * prevX[i + 1];
            }
            x[i] = sum / b[i];
            if (fabs(x[i] - prevX[i]) > epsilon) {
                converge = false;
            }
        }
        prevX = x;
        iteration++;
    } while (!converge);

    cout << "Метод Якоби завершен за " << iteration << " итераций." << endl;
}

// Метод Зейделя
void seidelMethod(int n, const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x, double epsilon) {
    vector<double> prevX(n, 0.0);
    int iteration = 0;
    bool converge;

    do {
        converge = true;
        for (int i = 0; i < n; ++i) {
            double sum = d[i];
            if (i > 0) {
                sum -= a[i - 1] * x[i - 1];
            }
            if (i < n - 1) {
                sum -= c[i] * prevX[i + 1];
            }
            x[i] = sum / b[i];
            if (fabs(x[i] - prevX[i]) > epsilon) {
                converge = false;
            }
            prevX[i] = x[i];
        }
        iteration++;
    } while (!converge);

    cout << "Метод Зейделя завершен за " << iteration << " итераций." << endl;
}

// Метод релаксации с экспериментальным подбором omega
void relaxationMethod(int n, const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x, double epsilon) {
    vector<double> prevX(n, 0.0);
    int iteration = 0;
    bool converge;
    double omega = 1.0;  // Начальное значение omega

    do {
        converge = true;
        for (int i = 0; i < n; ++i) {
            double sum = d[i];
            if (i > 0) {
                sum -= a[i - 1] * x[i - 1];
            }
            if (i < n - 1) {
                sum -= c[i] * prevX[i + 1];
            }
            double newX = (1 - omega) * prevX[i] + omega * (sum / b[i]);
            if (fabs(newX - prevX[i]) > epsilon) {
                converge = false;
            }
            x[i] = newX;
            prevX[i] = x[i];
        }
        iteration++;
        omega += 0.1;  // Изменение omega для экспериментального подбора
    } while (!converge);

    cout << "Метод релаксации завершен за " << iteration << " итераций с omega = " << omega << "." << endl;
}

// Запись результата в файл
void writeResult(const string& filename, const vector<double>& x) {
    ofstream output(filename);
    if (!output.is_open()) {
        cerr << "Не удалось открыть файл: " << filename << endl;
        exit(1);
    }
    for (const auto& value : x) {
        output << value << endl;
    }
    output.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFilename;
    cout << "Введите имя файла с входными данными: ";
    cin >> inputFilename;

    int n;
    string matrixFile, resultFile;
    readInput(inputFilename, n, matrixFile, resultFile);

    vector<double> a(n - 1), b(n), c(n - 1), d(n);
    readMatrix(matrixFile, n, a, b, c, d);

    vector<vector<double>> C;
    vector<double> y;
    convertSystem(n, a, b, c, d, C, y);
    double normC1 = matrixNorm1(C);
    double normCInfinity = matrixNormInfinity(C);
    if (normC1 >= 1 || normCInfinity >= 1) {
        cerr << "Матрица C не удовлетворяет условию сходимости." << endl;
        exit(1);
    }

    vector<vector<double>> CL, CD, CU;
    decomposeMatrix(n, C, CL, CD, CU);

    vector<double> x(n, 0.0);
    double epsilon1 = 1e-4;
    double epsilon2 = 1e-7;

    // Выполнение всех методов для двух значений epsilon
    simpleIterationMethod(n, a, b, c, d, x, epsilon1);
    jacobiMethod(n, a, b, c, d, x, epsilon1);
    seidelMethod(n, a, b, c, d, x, epsilon1);
    relaxationMethod(n, a, b, c, d, x, epsilon1);

    simpleIterationMethod(n, a, b, c, d, x, epsilon2);
    jacobiMethod(n, a, b, c, d, x, epsilon2);
    seidelMethod(n, a, b, c, d, x, epsilon2);
    relaxationMethod(n, a, b, c, d, x, epsilon2);

    writeResult(resultFile, x);

    return 0;
}