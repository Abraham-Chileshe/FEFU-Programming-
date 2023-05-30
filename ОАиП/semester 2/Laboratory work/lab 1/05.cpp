/*
Требуется отсортировать по возрастанию с помощью *пирамидальной сортировки* целочисленный массив размера N (), заполненный с клавиатуры, выводя также некоторые промежуточные результаты работы:

- первоначальная куча
- куча после каждой итерации
- отсортированный массив

Оценить асимптотику и объяснить.
*/

#include <stdio.h>

// Функция для создания максимальной кучи
void heapify(int arr[], int n, int i)
{
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если самый большой элемент не является корнем
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Рекурсивно приводим кучу к виду max heap
        heapify(arr, n, largest);
    }
}

// Основная функция для выполения пирамидальной сортировки
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Вызываем функцию heapify на уменьшенной куче
        heapify(arr, i, 0);

        // Выводим текущий массив после каждой итерации
        printf("Heap after iteration %d: ", n - i);
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

int main()
{
    int N;
    printf("Enter the size of the array N: ");
    scanf("%d", &N);

    if (N < 6) {
        printf("The size of the array must be greater than or equal to 6.\n");
        return 0;
    }

    int arr[N];
    printf("Enter the array elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    printf("Initial heap: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heapSort(arr, N);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
