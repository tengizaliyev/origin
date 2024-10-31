#include <iostream>
#include <string>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP

// Базовый класс для всех фигур
class Figure {
protected:
    int sides_count;         // Количество сторон
    std::string name;        // Название фигуры

    // Защищённый конструктор для инициализации с параметрами (только для наследников)
    Figure(int sides, const std::string& name) : sides_count(sides), name(name) {}

public:
    // Публичный конструктор по умолчанию для неизвестной фигуры
    Figure() : sides_count(0), name("Фигура") {}

    // Метод для получения количества сторон
    int get_sides_count() const {
        return sides_count;
    }

    // Метод для получения названия фигуры
    std::string get_name() const {
        return name;
    }
};

// Класс для треугольника
class Triangle : public Figure {
public:
    // Конструктор по умолчанию устанавливает 3 стороны и название "Треугольник"
    Triangle() : Figure(3, "Треугольник") {}
};

// Класс для четырёхугольника
class Quadrangle : public Figure {
public:
    // Конструктор по умолчанию устанавливает 4 стороны и название "Четырёхугольник"
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаём экземпляры каждой фигуры
    Figure unknownFigure; // Экземпляр для неизвестной фигуры
    Triangle triangle; // Экземпляр треугольника
    Quadrangle quadrangle; // Экземпляр четырёхугольника

    // Выводим количество сторон каждой фигуры
    std::cout << unknownFigure.get_name() << ": " << unknownFigure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}
