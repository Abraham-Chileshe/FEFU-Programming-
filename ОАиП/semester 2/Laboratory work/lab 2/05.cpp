/*
Необходимо найти в строке указанную подстроку и заменить ее на новую. Если такой подстроки не существует, то выводится соответствующее сообщение. Строку, подстроку для замены и новую подстроку вводит пользователь. (Использовать любой из алгоритмов поиска подстроки в строке).
*/

#include <stdio.h>
#include <string.h>

// Функция для замены подстроки
void replaceSubstring(char* str, const char* oldSubstring, const char* newSubstring) {
    int strLength = strlen(str);
    int oldSubLength = strlen(oldSubstring);
    int newSubLength = strlen(newSubstring);

    // Проверка, если старая подстрока пустая или новая подстрока пустая
    if (oldSubLength == 0 || newSubLength == 0) {
        printf("Error: Invalid substrings specified\n");
        return;
    }

    // Проверка, если новая подстрока длиннее старой подстроки
    if (newSubLength > oldSubLength) {
        printf("Error: The new substring is longer than the old substring.\n");
        return;
    }

    // Поиск подстроки в строке и замена ее на новую подстроку
    char* pos = strstr(str, oldSubstring);
    if (pos != NULL) {
        memmove(pos + newSubLength, pos + oldSubLength, strLength - (pos - str) - oldSubLength + 1);
        memcpy(pos, newSubstring, newSubLength);
        printf("The substring was successfully replaced.\n");
    } else {
        printf("Substring not found.\n");
    }
}

int main() {
    char str[100];
    char oldSubstring[50];
    char newSubstring[50];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Удаление символа новой строки

    printf("Enter a substring to replace: ");
    fgets(oldSubstring, sizeof(oldSubstring), stdin);
    oldSubstring[strcspn(oldSubstring, "\n")] = '\0'; // Удаление символа новой строки

    printf("Enter a new substring: ");
    fgets(newSubstring, sizeof(newSubstring), stdin);
    newSubstring[strcspn(newSubstring, "\n")] = '\0'; // Удаление символа новой строки

    replaceSubstring(str, oldSubstring, newSubstring);

    printf("Final line: %s\n", str);

    return 0;
}
