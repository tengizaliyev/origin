#include <iostream>
#include <string>
#include <windows.h> 

// ��������� ��� �������� ������
struct Address {
    std::string city;       // �����
    std::string street;     // �����
    int houseNumber;        // ����� ����
    int apartmentNumber;    // ����� ��������
    int postalCode;         // ������
};

// ������� ��� ������ ������ �� �������
void printAddress(const Address& address) {
    std::cout << "�����: " << address.city << std::endl;
    std::cout << "�����: " << address.street << std::endl;
    std::cout << "����� ����: " << address.houseNumber << std::endl;
    std::cout << "����� ��������: " << address.apartmentNumber << std::endl;
    std::cout << "������: " << address.postalCode << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������ ��� ���������� ��������� Address
    Address address1;
    Address address2;

    // ���� ������ ��� ������� ������
    std::cout << "������� �����: ";
    std::getline(std::cin, address1.city);

    std::cout << "������� �����: ";
    std::getline(std::cin, address1.street);

    std::cout << "������� ����� ����: ";
    std::cin >> address1.houseNumber;

    std::cout << "������� ����� ��������: ";
    std::cin >> address1.apartmentNumber;

    std::cout << "������� ������: ";
    std::cin >> address1.postalCode;

    std::cin.ignore(); 

    // ���� ������ ��� ������� ������
    std::cout << "\n������� �����: ";
    std::getline(std::cin, address2.city);

    std::cout << "������� �����: ";
    std::getline(std::cin, address2.street);

    std::cout << "������� ����� ����: ";
    std::cin >> address2.houseNumber;

    std::cout << "������� ����� ��������: ";
    std::cin >> address2.apartmentNumber;

    std::cout << "������� ������: ";
    std::cin >> address2.postalCode;

    // ����� �������
    std::cout << "\n����� 1:\n";
    printAddress(address1);

    std::cout << "\n����� 2:\n";
    printAddress(address2);

    return 0;
}
