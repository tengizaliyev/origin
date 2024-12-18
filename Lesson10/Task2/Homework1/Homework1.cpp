#include <iostream>
#include <string>
#include <windows.h>

// ����������� ������������ ����������
class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "�� ����� ����� ��������� �����!";
    }
};

// ������� ��� �������� ����� ������
int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length(); // ����������� ����������, ���� ����� ������ ��������� � ���������
    }
    return str.length();
}

int main() {
    SetConsoleOutputCP(1251); // ������������� ��������� ��� �������� �����
    SetConsoleCP(1251);

    int forbidden_length;
    std::string input;

    std::cout << "������� ��������� �����: ";
    std::cin >> forbidden_length;
    std::cin.ignore(); // ������� ������ ����� ����� �����

    try {
        while (true) {
            std::cout << "������� �����: ";
            std::getline(std::cin, input);

            int length = function(input, forbidden_length);
            std::cout << "����� ����� \"" << input << "\" ����� " << length << std::endl;
        }
    }
    catch (const bad_length& e) {
        std::cout << e.what() << std::endl;
        std::cout << "�� ��������!" << std::endl;
    }

    return 0;
}
