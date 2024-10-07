#include <iostream>
#include <windows.h> // ��� SetConsoleCP � SetConsoleOutputCP

// �����-�������
class Counter {
private:
    int count; // ������� �������� ��������

public:
    // ����������� �� ��������� (��������� �������� 1)
    Counter() : count(1) {}

    // ����������� � �������������� ���������� ��������
    Counter(int initial) : count(initial) {}

    // ����� ���������� ��������
    void increment() {
        count++;
    }

    // ����� ���������� ��������
    void decrement() {
        count--;
    }

    // ����� ��������� �������� �������� ��������
    int getCount() const {
        return count;
    }
};

int main() {
    // ��������� ��������� ��� ����������� ����������� ������� ��������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userInput;
    int initialCount;
    Counter counter;

    // ������ � ������������ ���������� ��������
    std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
    std::cin >> userInput;

    // ���� ������������ ����� ������� ��������� ��������
    if (userInput == "��") {
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> initialCount;
        counter = Counter(initialCount);
    }

    // ���� ��������� ������
    char command;
    while (true) {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getCount() << std::endl;
            break;
        case 'x':
            std::cout << "�� ��������!\n";
            return 0;
        default:
            std::cout << "����������� �������, ���������� �����.\n";
            break;
        }
    }

    return 0;
}
