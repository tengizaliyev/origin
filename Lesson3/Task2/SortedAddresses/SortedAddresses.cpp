#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // ��� std::sort
#include <windows.h>

// ����� ��� �������� ������
class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    // ����������� � �����������
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // ����� ��� ���������������� ������ ������ � ������
    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    // ����� ��� ��������� �������� ������
    std::string get_city() const {
        return city;
    }
};

// ������� ��� ���������� ������� �� �������� ������
void sort_addresses(std::vector<Address>& addresses) {
    std::sort(addresses.begin(), addresses.end(), [](const Address& a, const Address& b) {
        return a.get_city() < b.get_city(); // ��������� �� �������� ������
        });
}

int main() {
    // ��������� ��������� ��� ����������� ����������� ������� ��������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // �������� ����� ��� ������
    std::ifstream inputFile("in.txt");
    if (!inputFile) {
        std::cerr << "�� ������� ������� ���� in.txt ��� ������!" << std::endl;
        return 1;
    }

    // ������ ���������� �������
    int addressCount;
    inputFile >> addressCount;
    inputFile.ignore(); // ���������� ������ ����� ������ ����� �����

    // ������ ������ ��� �������� �������
    std::vector<Address> addresses;

    // ������ ������� �� �����
    for (int i = 0; i < addressCount; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        // ������ ������ ��� ������ ������
        std::getline(inputFile, city);
        std::getline(inputFile, street);
        inputFile >> houseNumber >> apartmentNumber;
        inputFile.ignore(); // ���������� ������ ����� ������ ����� ����� �����

        // ������ ��������� ������ Address � ��������� ��� � ������
        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    // ��������� ���� �����
    inputFile.close();

    // ���������� ������� �� �������� ������
    sort_addresses(addresses);

    // �������� ����� ��� ������
    std::ofstream outputFile("out.txt");
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� out.txt ��� ������!" << std::endl;
        return 1;
    }

    // ������ ���������� ������� � ����
    outputFile << addressCount << std::endl;

    // ������ ��������������� �������
    for (const auto& address : addresses) {
        outputFile << address.get_output_address() << std::endl;
    }

    // ��������� ���� ������
    outputFile.close();

    std::cout << "������ ������� ������������� � �������� � ���� out.txt!" << std::endl;

    return 0;
}
