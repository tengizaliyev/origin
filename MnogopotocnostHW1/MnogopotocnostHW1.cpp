#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

int clientCount = 0; // ����� ���������� ��� ��������
const int MAX_CLIENTS = 10; // ����������������� ��������

// ����� �������
void client() {
    while (clientCount < MAX_CLIENTS) {
        this_thread::sleep_for(chrono::seconds(1)); // ��� 1 �������
        clientCount++; // ����������� �������
        cout << "������ ������. �������: " << clientCount << endl;
    }
    cout << "������� �����. �������: " << clientCount << endl;
}

// ����� �������������
void operatorThread() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(2)); // ��� 2 �������
        if (clientCount > 0) {
            clientCount--; // ��������� �������
            cout << "������������ �������� �������. �������: " << clientCount << endl;
        }
        else {
            cout << "��� ������� ���������. �������: " << clientCount << endl;
            break; // �������, ���� �������� ���
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    thread clientThread(client); // ��������� ����� �������
    thread operatorThreadThread(operatorThread); // ��������� ����� �������������

    clientThread.join(); // ��� ���������� �������
    operatorThreadThread.join(); // ��� ���������� �������������

    return 0;
}