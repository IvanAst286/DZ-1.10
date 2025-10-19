#include <iostream>
#include <iomanip>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);




    // ������ 1

    const int SIZE = 10;
    int array[SIZE];

    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 101 - 50;
    }

    std::cout << "������: ";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << "\n";
    int minValue = array[0];
    int maxValue = array[0];

    for (int i = 1; i < SIZE; ++i)
    {
        if (array[i] > maxValue)
        {
            maxValue = array[i];
        }
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
    }

    std::cout << "����������� �������: " << minValue << "\n";
    std::cout << "������������ �������: " << maxValue;





    // ������ 2

    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    int lowerBound;
    int upperBound;
    int threshold;
    long sum = 0;


    std::cout << "������� ������ �������: ";
    std::cin >> n;

    std::cout << "������� ������ ������� ��������� ��������� �����: ";
    std::cin >> lowerBound;

    std::cout << "������� ������� ������� ��������� ��������� �����: ";
    std::cin >> upperBound;

    std::cout << "������� ��������� ��������: ";
    std::cin >> threshold;


    int* array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        array[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }

    for (int i = 0; i < n; ++i)
    {
        if (array[i] < threshold)
        {
            sum += array[i];
        }
    }


    std::cout << "����� ���������, ������� " << threshold << ": " << sum;





    // ������ 3

    int profit[12];

    for (int i = 0; i < 12; ++i)
    {
        std::cout << "������� ������� ����� �� ������ ����� (�� ������ �� �������): ";
        std::cin >> profit[i];
    }

    int startMonth, endMonth;
    std::cout << "\n������� ��������� ����� ��������� (�� 1 �� 12): ";
    std::cin >> startMonth;
    std::cout << "������� �������� ����� ��������� (�� 1 �� 12): ";
    std::cin >> endMonth;

    if (startMonth > endMonth || startMonth <= 0 || endMonth > 12)
    {
        std::cout << "������ ����� ���������.";
    }
    else
    {

        int maxProfitIndex = startMonth;
        int minProfitIndex = startMonth;

        for (int i = startMonth + 1; i <= endMonth; ++i)
        {
            if (profit[maxProfitIndex] < profit[i])
                maxProfitIndex = i;

            if (profit[minProfitIndex] > profit[i])
                minProfitIndex = i;
        }

        std::cout << "\n������������ ������� ���� � ������ �" << maxProfitIndex + 1 << ": " << profit[maxProfitIndex] << "\n";
        std::cout << "����������� ������� ���� � ������ �" << minProfitIndex + 1 << ": " << profit[minProfitIndex];
    }

    return 0;
}