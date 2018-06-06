#include <stdio.h>
#include <stdlib.h>

    /*Функция перестановок. Permutations function.*/
    int permute(int * argv) {

        int k = 0;
        int i = 0;
        int j = 0;
        int x = 0; //Хранит длину строки. Var to let know length of a string
        int c = 0; //Для обмена. Buffer
		int reverse_argv[100] = {};

        /*Buble sort the array. Упорядочим алфавит*/
        for (x; argv[x]!=0; x++);

        for (i = 0; i < x; i++) {
            for (j = x - 1; j > i; j--) {
                if (argv[j - 1] > argv[j]) {
                    c = argv[j - 1];
                    argv[j - 1] = argv[j];
                    argv[j] = c;
                }
            }
        }
        /*Here we reverse an array to stop the alorithm later.
         *Перевернем массив, чтобы остановить его позже в цикле*/

        i = x - 1;
        while (k < x) {
            reverse_argv[k] = argv[i];
            i--;
            k++;
        }

        /*Main part: here we permute. Порождаем перестановки*/

        while (1) {

            for (j = 0; argv[j] != 0; j++) printf("%d ", argv[j]);
            printf("\n");

            for (k = 0; k != x + 1; k++) {
                if (reverse_argv[k] == argv[k] && argv[k] == 0) return 0;
                if (reverse_argv[k] != argv[k]) break;
            }

            i = x - 2;
            /*Here we search next. Ищем новую перестановку*/
            while (argv[i] >= argv[i + 1]) i--;
            j = x - 1;
            while (argv[j] <= argv[i]) j--;

            /*Change. Обмен*/
            c = argv[j];
            argv[j] = argv[i];
            argv[i] = c;
            i++;
            /*Tail reverse. Оборачиваем хвост*/
            for (j = x - 1; j > i; i++, j--) {
                c = argv[i];
                argv[i] = argv[j];
                argv[j] = c;
            }

        }
    }

int main(int argc, char * argv[]) {

	int k = 0;
    int i = 0;
    int j = 0;

	int a[100] = {};

    /*Проверим число аргументов. Here we check a number
     * of arguments*/
    if (argc != 2) {
        printf("Restart it with an argument\n");
        return 0;
    }

    /*String (argument) to integer conversion.
     * Конвертируем аргумент (строку) в целое число*/
    i = atoi(argv[1]);
    if (i > 99) return 0;


    /*Массив целых. This is an array of integers*/
    for (j = 1; j < i; j++) a[k++] = j;
    a[k] = j;
    a[k+1] = 0;

		/*Permutation function. Функция перестановок.*/
        permute(a);
}
