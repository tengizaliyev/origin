#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

// Функция для вычисления частичной суммы
long long computePartialSum(const vector<int>& v1, const vector<int>& v2, int start, int end, long long& result) {
    long long sum = 0;
    for (int i = start; i < end; i++) {
        sum += v1[i] + v2[i];
    }
    result = sum; // Сохраняем результат в переданную ссылку
    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Вывод количества ядер
    cout << "Доступное количество ядер: " << thread::hardware_concurrency() << endl;

    // Размеры векторов из задания
    vector<int> sizes = { 1000, 10000, 100000, 1000000 };

    // Таблица результатов
    cout << "\nВремя выполнения (в секундах):\n";
    cout << "Размер\t2 потока\t4 потока\t8 потоков\t16 потоков\n";

    for (int size : sizes) {
        // Инициализация векторов единицами для простоты
        vector<int> v1(size, 1); // Первый вектор
        vector<int> v2(size, 1); // Второй вектор

        for (int threadCount : {2, 4, 8, 16}) {
            vector<thread> threads;
            vector<long long> partialSums(threadCount, 0); // Массив для частичных сумм
            int chunkSize = size / threadCount; // Размер части для каждого потока

            auto start = chrono::high_resolution_clock::now(); // Начало измерения времени

            // Создание потоков
            for (int i = 0; i < threadCount; i++) {
                int startIdx = i * chunkSize;
                int endIdx = (i == threadCount - 1) ? size : (startIdx + chunkSize); // Последний поток до конца
                threads.emplace_back(computePartialSum, ref(v1), ref(v2), startIdx, endIdx, ref(partialSums[i]));
            }

            // Ожидание завершения всех потоков
            for (auto& t : threads) {
                t.join();
            }

            // Суммирование всех частичных сумм
            long long totalSum = 0;
            for (long long sum : partialSums) {
                totalSum += sum;
            }

            auto end = chrono::high_resolution_clock::now(); // Конец измерения времени
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0; // В секундах

            // Вывод времени только для соответствующего числа потоков
            cout << size << "\t" << (threadCount == 2 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 4 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 8 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 16 ? to_string(duration) + "s" : "") << "\t";
        }
        cout << endl;
    }

    return 0;
}