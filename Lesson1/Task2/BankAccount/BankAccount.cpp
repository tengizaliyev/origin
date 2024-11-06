#include <iostream>
#include <windows.h> 
#include <string>

// Структура для хранения информации о банковском счёте
struct BankAccount {
    int accountNumber;    // Номер счёта
    std::string ownerName; // Имя владельца
    double balance;       // Баланс на счету
};

// Функция для изменения баланса счёта
void updateBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    BankAccount account;

    // Ввод данных для счёта
    std::cout << "Введите номер счёта: ";
    std::cin >> account.accountNumber;

    std::cout << "Введите имя владельца: ";
    std::cin.ignore(); 
    std::getline(std::cin, account.ownerName);

    std::cout << "Введите баланс: ";
    std::cin >> account.balance;

    // Ввод нового баланса
    double newBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    // Обновление баланса с помощью функции
    updateBalance(account, newBalance);

    // Вывод обновленной информации о счёте
    std::cout << "Ваш счёт: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;
}
