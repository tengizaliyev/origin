#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

// ������� ��� ���������� ��������� �����
long long computePartialSum(const vector<int>& v1, const vector<int>& v2, int start, int end, long long& result) {
    long long sum = 0;
    for (int i = start; i < end; i++) {
        sum += v1[i] + v2[i];
    }
    result = sum; // ��������� ��������� � ���������� ������
    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ����� ���������� ����
    cout << "��������� ���������� ����: " << thread::hardware_concurrency() << endl;

    // ������� �������� �� �������
    vector<int> sizes = { 1000, 10000, 100000, 1000000 };

    // ������� �����������
    cout << "\n����� ���������� (� ��������):\n";
    cout << "������\t2 ������\t4 ������\t8 �������\t16 �������\n";

    for (int size : sizes) {
        // ������������� �������� ��������� ��� ��������
        vector<int> v1(size, 1); // ������ ������
        vector<int> v2(size, 1); // ������ ������

        for (int threadCount : {2, 4, 8, 16}) {
            vector<thread> threads;
            vector<long long> partialSums(threadCount, 0); // ������ ��� ��������� ����
            int chunkSize = size / threadCount; // ������ ����� ��� ������� ������

            auto start = chrono::high_resolution_clock::now(); // ������ ��������� �������

            // �������� �������
            for (int i = 0; i < threadCount; i++) {
                int startIdx = i * chunkSize;
                int endIdx = (i == threadCount - 1) ? size : (startIdx + chunkSize); // ��������� ����� �� �����
                threads.emplace_back(computePartialSum, ref(v1), ref(v2), startIdx, endIdx, ref(partialSums[i]));
            }

            // �������� ���������� ���� �������
            for (auto& t : threads) {
                t.join();
            }

            // ������������ ���� ��������� ����
            long long totalSum = 0;
            for (long long sum : partialSums) {
                totalSum += sum;
            }

            auto end = chrono::high_resolution_clock::now(); // ����� ��������� �������
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0; // � ��������

            // ����� ������� ������ ��� ���������������� ����� �������
            cout << size << "\t" << (threadCount == 2 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 4 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 8 ? to_string(duration) + "s" : "") << "\t"
                << (threadCount == 16 ? to_string(duration) + "s" : "") << "\t";
        }
        cout << endl;
    }

    return 0;
}