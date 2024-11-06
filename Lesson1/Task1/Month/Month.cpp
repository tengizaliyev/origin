#include <iostream>
#include <windows.h> // ��� ������������� SetConsoleCP � SetConsoleOutputCP

// ������������ ��� �������
enum Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    // ��������� ��������� ��� ����� � ������ ������� ��������
    SetConsoleCP(1251); // ���� � ������� � ��������� 1251
    SetConsoleOutputCP(1251); // ����� � ������� � ��������� 1251

    int monthNumber;

    while (true) {
        std::cout << "������� ����� ������: ";
        std::cin >> monthNumber;

        // �������� �� ���������� ���������
        if (monthNumber == 0) {
            std::cout << "�� ��������\n";
            break;
        }

        // ���������� � ������������ � ��������� ��������
        switch (static_cast<Months>(monthNumber)) {
        case January:
            std::cout << "������\n";
            break;
        case February:
            std::cout << "�������\n";
            break;
        case March:
            std::cout << "����\n";
            break;
        case April:
            std::cout << "������\n";
            break;
        case May:
            std::cout << "���\n";
            break;
        case June:
            std::cout << "����\n";
            break;
        case July:
            std::cout << "����\n";
            break;
        case August:
            std::cout << "������\n";
            break;
        case September:
            std::cout << "��������\n";
            break;
        case October:
            std::cout << "�������\n";
            break;
        case November:
            std::cout << "������\n";
            break;
        case December:
            std::cout << "�������\n";
            break;
        default:
            std::cout << "������������ �����!\n";
            break;
        }
    }

    return 0;
}
