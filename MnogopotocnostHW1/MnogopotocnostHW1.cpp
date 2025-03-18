#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

int clientCount = 0; // Общая переменная для счётчика
const int MAX_CLIENTS = 10; // Параметризованный максимум

// Поток клиента
void client() {
    while (clientCount < MAX_CLIENTS) {
        this_thread::sleep_for(chrono::seconds(1)); // Ждём 1 секунду
        clientCount++; // Увеличиваем счётчик
        cout << "Клиент пришёл. Счётчик: " << clientCount << endl;
    }
    cout << "Очередь полна. Счётчик: " << clientCount << endl;
}

// Поток операциониста
void operatorThread() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(2)); // Ждём 2 секунды
        if (clientCount > 0) {
            clientCount--; // Уменьшаем счётчик
            cout << "Операционист обслужил клиента. Счётчик: " << clientCount << endl;
        }
        else {
            cout << "Все клиенты обслужены. Счётчик: " << clientCount << endl;
            break; // Выходим, если клиентов нет
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    thread clientThread(client); // Запускаем поток клиента
    thread operatorThreadThread(operatorThread); // Запускаем поток операциониста

    clientThread.join(); // Ждём завершения клиента
    operatorThreadThread.join(); // Ждём завершения операциониста

    return 0;
}