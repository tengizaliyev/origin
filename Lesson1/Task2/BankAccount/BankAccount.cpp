#include <iostream>
#include <windows.h> 
#include <string>

// ��������� ��� �������� ���������� � ���������� �����
struct BankAccount {
    int accountNumber;    // ����� �����
    std::string ownerName; // ��� ���������
    double balance;       // ������ �� �����
};

// ������� ��� ��������� ������� �����
void updateBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    // ��������� ��������� ��� ����������� ����������� ������� ��������
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    BankAccount account;

    // ���� ������ ��� �����
    std::cout << "������� ����� �����: ";
    std::cin >> account.accountNumber;

    std::cout << "������� ��� ���������: ";
    std::cin.ignore(); 
    std::getline(std::cin, account.ownerName);

    std::cout << "������� ������: ";
    std::cin >> account.balance;

    // ���� ������ �������
    double newBalance;
    std::cout << "������� ����� ������: ";
    std::cin >> newBalance;

    // ���������� ������� � ������� �������
    updateBalance(account, newBalance);

    // ����� ����������� ���������� � �����
    std::cout << "��� ����: " << account.ownerName << ", " << account.accountNumber << ", " << account.balance << std::endl;

    return 0;
}
