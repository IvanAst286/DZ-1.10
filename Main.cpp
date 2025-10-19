#include <iostream>
#include <iomanip>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);




    // Задача 1

    const int SIZE = 10;
    int array[SIZE];

    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        array[i] = rand() % 101 - 50;
    }

    std::cout << "Массив: ";
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

    std::cout << "Минимальный элемент: " << minValue << "\n";
    std::cout << "Максимальный элемент: " << maxValue;





    // Задача 2

    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    int lowerBound;
    int upperBound;
    int threshold;
    long sum = 0;


    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::cout << "Введите нижнюю границу диапазона случайных чисел: ";
    std::cin >> lowerBound;

    std::cout << "Введите верхнюю границу диапазона случайных чисел: ";
    std::cin >> upperBound;

    std::cout << "Введите пороговое значение: ";
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


    std::cout << "Сумма элементов, меньших " << threshold << ": " << sum;





    // Задача 3

    int profit[12];

    for (int i = 0; i < 12; ++i)
    {
        std::cout << "Введите прибыль фирмы за каждый месяц (от января до декабря): ";
        std::cin >> profit[i];
    }

    int startMonth, endMonth;
    std::cout << "\nВведите начальный месяц диапазона (от 1 до 12): ";
    std::cin >> startMonth;
    std::cout << "Введите конечный месяц диапазона (от 1 до 12): ";
    std::cin >> endMonth;

    if (startMonth > endMonth || startMonth <= 0 || endMonth > 12)
    {
        std::cout << "Ошибка ввода диапазона.";
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

        std::cout << "\nМаксимальная прибыль была в месяце №" << maxProfitIndex + 1 << ": " << profit[maxProfitIndex] << "\n";
        std::cout << "Минимальная прибыль была в месяце №" << minProfitIndex + 1 << ": " << profit[minProfitIndex];
    }

    return 0;
}