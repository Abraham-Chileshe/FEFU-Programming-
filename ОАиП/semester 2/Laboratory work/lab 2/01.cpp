/*
С помощью хеширования проверить является ли строка палиндромом (с помощью прямого и обратного хеширования).
*/

#include <stdio.h>
#include <string.h>

// Функция для вычисления хеша строки в прямом направлении
unsigned long long computeHash(const char* str) {
    unsigned long long hash = 0;
    unsigned long long prime = 31;  // Простое число для хеширования

    for (int i = 0; str[i] != '\0'; i++) {
        hash = hash * prime + str[i];
    }

    return hash;
}

// Функция для вычисления хеша строки в обратном направлении
unsigned long long computeReverseHash(const char* str) {
    unsigned long long hash = 0;
    unsigned long long prime = 31;  // Простое число для хеширования
    int length = strlen(str);

    for (int i = length - 1; i >= 0; i--) {
        hash = hash * prime + str[i];
    }

    return hash;
}

// Функция для проверки, является ли строка палиндромом с помощью хешей
int isPalindrome(const char* str) {
    return computeHash(str) == computeReverseHash(str);
}

int main() {
    char str[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    // Удаление символа новой строки, если он присутствует
    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is NOT palindrome.\n");
    }

    return 0;
}
