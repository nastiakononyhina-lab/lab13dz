#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Лабораторная 13, задание 3 (ДЗ), вариант 11:
// проверить, есть ли в заданной строке слова, начинающиеся на букву 'a'.
// Слова разделены пробелами. Строку вводим через fgets (можно с пробелами).

int main()
{
    setlocale(LC_ALL, "Rus");
    char s[200];
    int i, j;
    int count = 0;

    puts("Введите строку (слова на латинице): ");
    fgets(s, 200, stdin);

    for (i = 0; i < strlen(s); i++)
    {
        // слово начинается там, где символ не пробел, а перед ним пробел (или начало строки)
        if (s[i] != ' ' && s[i] != '\n' && (i == 0 || s[i - 1] == ' '))
        {
            if (tolower((unsigned char)s[i]) == 'a')
            {
                count++;
                printf("Слово на 'a': ");
                for (j = i; s[j] != ' ' && s[j] != '\n' && s[j] != '\0'; j++)
                    printf("%c", s[j]);
                printf("\n");
            }
        }
    }

    if (count > 0)
        printf("Да, слов, начинающихся на 'a': %d\n", count);
    else
        printf("Нет, таких слов в строке нет\n");

    return 0;
}
