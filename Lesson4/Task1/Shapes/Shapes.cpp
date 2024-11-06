#include <iostream>
#include <string>
#include <windows.h> // ��� SetConsoleCP � SetConsoleOutputCP

// ������� ����� ��� ���� �����
class Figure {
protected:
    int sides_count;         // ���������� ������
    std::string name;        // �������� ������

    // ���������� ����������� ��� ������������� � ����������� (������ ��� �����������)
    Figure(int sides, const std::string& name) : sides_count(sides), name(name) {}

public:
    // ��������� ����������� �� ��������� ��� ����������� ������
    Figure() : sides_count(0), name("������") {}

    // ����� ��� ��������� ���������� ������
    int get_sides_count() const {
        return sides_count;
    }

    // ����� ��� ��������� �������� ������
    std::string get_name() const {
        return name;
    }
};

// ����� ��� ������������
class Triangle : public Figure {
public:
    // ����������� �� ��������� ������������� 3 ������� � �������� "�����������"
    Triangle() : Figure(3, "�����������") {}
};

// ����� ��� ���������������
class Quadrangle : public Figure {
public:
    // ����������� �� ��������� ������������� 4 ������� � �������� "��������������"
    Quadrangle() : Figure(4, "��������������") {}
};

int main() {
    // ��������� ��������� ��� ����������� ����������� ������� ��������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������ ���������� ������ ������
    Figure unknownFigure; // ��������� ��� ����������� ������
    Triangle triangle; // ��������� ������������
    Quadrangle quadrangle; // ��������� ���������������

    // ������� ���������� ������ ������ ������
    std::cout << unknownFigure.get_name() << ": " << unknownFigure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}
