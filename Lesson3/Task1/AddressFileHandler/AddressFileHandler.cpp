#include <iostream>
#include <fstream>  // ��� ������ � �������
#include <string>   // ��� ������ � ����� std::string
#include <vector>   // ��� ������������� ������������� ������� (std::vector)
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
};

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

    // �������� ����� ��� ������
    std::ofstream outputFile("out.txt");
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� out.txt ��� ������!" << std::endl;
        return 1;
    }

    // ������ ���������� ������� � ����
    outputFile << addressCount << std::endl;

    // ������ ������� � �������� �������
    for (int i = addressCount - 1; i >= 0; --i) {
        outputFile << addresses[i].get_output_address() << std::endl;
    }

    // ��������� ���� ������
    outputFile.close();

    std::cout << "������ ������� �������� � ���� out.txt!" << std::endl;

    return 0;
}
