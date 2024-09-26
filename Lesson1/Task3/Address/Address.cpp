#include <iostream>
#include <string>
#include <windows.h> 

// Структура для хранения адреса
struct Address {
    std::string city;       // Город
    std::string street;     // Улица
    int houseNumber;        // Номер дома
    int apartmentNumber;    // Номер квартиры
    int postalCode;         // Индекс
};

// Функция для вывода адреса на консоль
void printAddress(const Address& address) {
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.houseNumber << std::endl;
    std::cout << "Номер квартиры: " << address.apartmentNumber << std::endl;
    std::cout << "Индекс: " << address.postalCode << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаём два экземпляра структуры Address
    Address address1;
    Address address2;

    // Ввод данных для первого адреса
    std::cout << "Введите город: ";
    std::getline(std::cin, address1.city);

    std::cout << "Введите улицу: ";
    std::getline(std::cin, address1.street);

    std::cout << "Введите номер дома: ";
    std::cin >> address1.houseNumber;

    std::cout << "Введите номер квартиры: ";
    std::cin >> address1.apartmentNumber;

    std::cout << "Введите индекс: ";
    std::cin >> address1.postalCode;

    std::cin.ignore(); 

    // Ввод данных для второго адреса
    std::cout << "\nВведите город: ";
    std::getline(std::cin, address2.city);

    std::cout << "Введите улицу: ";
    std::getline(std::cin, address2.street);

    std::cout << "Введите номер дома: ";
    std::cin >> address2.houseNumber;

    std::cout << "Введите номер квартиры: ";
    std::cin >> address2.apartmentNumber;

    std::cout << "Введите индекс: ";
    std::cin >> address2.postalCode;

    // Вывод адресов
    std::cout << "\nАдрес 1:\n";
    printAddress(address1);

    std::cout << "\nАдрес 2:\n";
    printAddress(address2);

    return 0;
}
