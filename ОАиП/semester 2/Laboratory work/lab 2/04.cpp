/*
Найдите в строке s первую подстроку, являющуюся анаграммой (перестановкой символов) строки t.
*/

#include <stdio.h>
#include <string.h>

// Функция для проверки, являются ли две строки анаграммами
int areAnagrams(const char* str1, const char* str2) {
    int count[256] = {0}; // Массив для подсчета количества символов

    // Подсчет символов в первой строке
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i]]++;
    }

    // Уменьшение количества символов во второй строке
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i]]--;
    }

    // Проверка, все ли символы были учтены
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0; // Строки не являются анаграммами
        }
    }

    return 1; // Строки являются анаграммами
}

// Функция для поиска первой анаграмматической подстроки
const char* findAnagramSubstring(const char* str, const char* pattern) {
    int patternLength = strlen(pattern);

    // Перебор всех подстрок и проверка, являются ли они анаграммами
    for (int i = 0; str[i] != '\0'; i++) {
        if (i + patternLength > strlen(str)) {
            break; // Достигнут конец строки
        }

        // Проверка текущей подстроки на анаграмму
        if (areAnagrams(pattern, &str[i])) {
            return &str[i]; // Найдена анаграмматическая подстрока
        }
    }

    return NULL; // Анаграмматическая подстрока не найдена
}

int main() {
    const int maxLength = 100;
    char str[maxLength];
    char pattern[maxLength];

    printf("Enter the string: ");
    fgets(str, maxLength, stdin);
    str[strcspn(str, "\n")] = '\0'; // Удаление символа новой строки

    printf("Enter a sample string: ");
    fgets(pattern, maxLength, stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Удаление символа новой строки

    const char* result = findAnagramSubstring(str, pattern);

    if (result != NULL) {
        printf("\n"
               "First anagrammatic substring: %s\n", result);
    } else {
        printf("Anagrammatic substring not found\n");
    }

    return 0;
}
