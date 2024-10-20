#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // Для std::sort
#include <windows.h>

// Класс для хранения адреса
class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор с параметрами
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    // Метод для форматированного вывода адреса в строку
    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    // Метод для получения названия города
    std::string get_city() const {
        return city;
    }
};

// Функция для сортировки адресов по названию города
void sort_addresses(std::vector<Address>& addresses) {
    std::sort(addresses.begin(), addresses.end(), [](const Address& a, const Address& b) {
        return a.get_city() < b.get_city(); // Сравнение по названию города
        });
}

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Открытие файла для чтения
    std::ifstream inputFile("in.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл in.txt для чтения!" << std::endl;
        return 1;
    }

    // Чтение количества адресов
    int addressCount;
    inputFile >> addressCount;
    inputFile.ignore(); // Игнорируем символ новой строки после числа

    // Создаём вектор для хранения адресов
    std::vector<Address> addresses;

    // Чтение адресов из файла
    for (int i = 0; i < addressCount; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        // Чтение данных для одного адреса
        std::getline(inputFile, city);
        std::getline(inputFile, street);
        inputFile >> houseNumber >> apartmentNumber;
        inputFile.ignore(); // Игнорируем символ новой строки после ввода чисел

        // Создаём экземпляр класса Address и добавляем его в вектор
        addresses.emplace_back(city, street, houseNumber, apartmentNumber);
    }

    // Закрываем файл ввода
    inputFile.close();

    // Сортировка адресов по названию города
    sort_addresses(addresses);

    // Открытие файла для записи
    std::ofstream outputFile("out.txt");
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл out.txt для записи!" << std::endl;
        return 1;
    }

    // Запись количества адресов в файл
    outputFile << addressCount << std::endl;

    // Запись отсортированных адресов
    for (const auto& address : addresses) {
        outputFile << address.get_output_address() << std::endl;
    }

    // Закрываем файл вывода
    outputFile.close();

    std::cout << "Адреса успешно отсортированы и записаны в файл out.txt!" << std::endl;

    return 0;
}
