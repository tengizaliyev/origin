#include <iostream>
#include <fstream>  // Для работы с файлами
#include <string>   // Для работы с типом std::string
#include <vector>   // Для использования динамического массива (std::vector)
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
};

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

    // Открытие файла для записи
    std::ofstream outputFile("out.txt");
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл out.txt для записи!" << std::endl;
        return 1;
    }

    // Запись количества адресов в файл
    outputFile << addressCount << std::endl;

    // Запись адресов в обратном порядке
    for (int i = addressCount - 1; i >= 0; --i) {
        outputFile << addresses[i].get_output_address() << std::endl;
    }

    // Закрываем файл вывода
    outputFile.close();

    std::cout << "Адреса успешно записаны в файл out.txt!" << std::endl;

    return 0;
}
