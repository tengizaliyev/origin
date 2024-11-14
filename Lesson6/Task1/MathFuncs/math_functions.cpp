// math_functions.cpp
#include "math_functions.h"
#include <stdexcept> // для обработки исключения при делении на ноль

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Ошибка: деление на ноль.");
    }
    return a / b;
}

double power(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}
