/*
Заполнить числовой массив, содержащий N () элементов, с клавиатуры. Осуществить упорядочение числового массива по возрастанию и убыванию *методом поразрядной сортировки*.
Программа должна обеспечить вывод исходного массива на экран, сортировку массива, вывод результата сортировки на экран. Оценить асимптотику и объяснить.
*/

#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    const int radix = 10;  // Основание системы счисления

    int output[n];
    int count[radix] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % radix]++;

    for (int i = 1; i < radix; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % radix] - 1] = arr[i];
        count[(arr[i] / exp) % radix]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max_value = arr[0];

    // Находим максимальное значение в массиве
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Производим сортировку по разрядам
    for (int exp = 1; max_value / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array (N >= 6): ";
    cin >> n;

    if (n < 6) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int arr[n];

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Source array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортируем массив по возрастанию
    radixSort(arr, n);

    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортируем массив по убыванию
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }

    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
