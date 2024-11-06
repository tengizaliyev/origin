#ifndef LAB_1_SRC_MATRIX_OPERATIONS_H_
#define LAB_1_SRC_MATRIX_OPERATIONS_H_
#include <iostream>
#include <vector>
#include <utility>
template <typename T>
std::vector<std::vector<T>>* inverse(const std::vector<std::vector<T>>& A) {
    size_t n = A.size();
    std::vector<std::vector<T>> identity(n, std::vector<T>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        identity[i][i] = 1;
    }
    std::vector<T> solution(n);
    auto* inverse = new std::vector<std::vector<T>>(n, std::vector<T>(n));
    for (size_t i = 0; i < n; ++i) {
        std::pair<std::vector<std::vector<T>>, std::vector<T>> data(A, identity[i]);
        solution = Gauss(data);
        for (size_t j = 0; j < n; ++j) {
            (*inverse)[j][i] = solution[j];
        }
    }
    return inverse;
}

template <typename T>
void transpose(std::vector<std::vector<T>>& A) {
    size_t n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(A[i][j], A[j][i]);
        }
    }
}
template <typename T>
void multiply(const std::vector<std::vector<T>>& A, const std::vector<std::vector<T>>& B, std::vector<std::vector<T>>& res) {
    size_t n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template <typename T>
std::vector<T> multiplyVectorByConstant(const std::vector<T>& vec, T constant) {
    size_t n{ vec.size() };
    std::vector<T> result(n);
    for (size_t i = 0; i < n; ++i)
    {
        result[i] = vec[i] * constant;
    }
    return result;
}

template <typename T>
std::vector<T> operator*(const std::vector<T>& vec, T constant) {
    return multiplyVectorByConstant(vec, constant);
}

template <typename T>
std::vector<T> operator*(T constant, const std::vector<T>& vec) {
    return vec * constant;
}


template <typename T>
std::vector<T> multiplyMatrixByVector(const std::vector<std::vector<T>>& matrix, const std::vector<T>& vec) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    if (vec.size() != n) {
        throw std::invalid_argument("����������� ������� ������ ��������� � ����������� �������� � �������.");
    }
    std::vector<T> result(m, 0.0);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

template <typename T>
std::vector<T> operator*(const std::vector<std::vector<T>>& matrix, const std::vector<T>& vec) {
    return multiplyMatrixByVector(matrix, vec);
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("������� ������ ����� ���������� ����� ��� ��������.");
    }
    std::vector<T> result(vec1.size());
    for (size_t i = 0; i < vec1.size(); ++i) {
        result[i] = vec1[i] + vec2[i];
    }
    return result;
}

template <typename T>
std::vector<T> operator-(const std::vector<T>& vec1, const std::vector<T>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("������� ������ ����� ���������� ����� ��� ���������.");
    }
    std::vector<T> result(vec1.size());
    for (size_t i = 0; i < vec1.size(); ++i) {
        result[i] = vec1[i] - vec2[i];
    }
    return result;
}

template <typename T>
T octahedralNorm(const std::vector<std::vector<T>>& A) {
    size_t n = A.size();
    if (n == 0) return 0;
    T maxColSum = 0;
    for (size_t j = 0; j < n; ++j) {
        T colSum = 0;
        for (size_t i = 0; i < n; ++i) {
            colSum += std::abs(A[i][j]);
        }
        if (colSum > maxColSum) {
            maxColSum = colSum;
        }
    }
    return maxColSum;
}

template <typename T>
T cubicNorm(const std::vector<std::vector<T>>& A) {
    size_t n = A.size();
    if (n == 0) return 0;
    T maxRowSum = 0;
    for (size_t i = 0; i < n; ++i) {
        T rowSum = 0;
        for (size_t j = 0; j < n; ++j) {
            rowSum += std::abs(A[i][j]);
        }
        if (rowSum > maxRowSum) {
            maxRowSum = rowSum;
        }
    }
    return maxRowSum;
}

template <typename T>
std::vector<std::vector<T>> operator*(const std::vector<std::vector<T>>& matrix, T scalar) {
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> operator*(T scalar, const std::vector<std::vector<T>>& matrix) {
    return matrix * scalar;
}

template <typename T>
T operator*(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("������� ������ ���� ���������� ����� ��� ���������� ���������");
    }
    T dotProduct{ 0 };
    for (size_t i = 0; i < v1.size(); ++i) {
        dotProduct += v1[i] * v2[i];
    }
    return dotProduct;
}

template <typename T>
std::vector<std::vector<T>> operator+(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        throw std::invalid_argument("������� ������ ������ ��������� ��� ��������.");
    }
    std::vector<std::vector<T>> result(matrix1.size(), std::vector<T>(matrix1[0].size()));
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

template <typename T>
std::vector<std::vector<T>> identityMatrix(size_t size) {
    std::vector<std::vector<T>> identityMatrix(size, std::vector<T>(size, 0));
    for (size_t i = 0; i < size; ++i) {
        identityMatrix[i][i] = 1;
    }
    return identityMatrix;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
#endif //LAB_1_SRC_MATRIX_OPERATIONS_H_
