#include <stdio.h>
int main (int argc, char *argv[]) {

	int i = 0;
    int j = 0;
    int fact = 1;//Факториал. Factorial
    int x = 0;   //Хранит длину строки. Var to let know length of a string
    int y = 0;   //Считаем число перестановок. It  calculates factorial
    char c;      //Для обмена. Buffer

    /*Here we check arguments. Проверим аргументы*/
    if (argc < 2) {
        printf("Enter an argument. Example 1234 or dcba:\n");
        return 0;
    }
/*It calculates an array's length. Вычислим длину строки*/

    for (x; argv[1][x]; x++);

/*Buble sort the array. Упорядочим алфавит*/

    for(i=0; i < x; i++) {
        for(j = x-1; j > i; j-- ) {
            if (argv[1][j-1] > argv[1][j]) {
                c=argv[1][j-1];
                argv[1][j-1]=argv[1][j];
                argv[1][j]=c;
            }
        }
    }

/*It calculates a factorial to stop the algorithm*. Вычислим факториал
  для остановки алгоритма*/

    while ( y!=x ) {
		  y++;
		  fact = y*fact;
}

/*Main part: here we permutate. Порождаем перестановки
 до тех пор пока не дойдем до факториал - переменная fact*/

    y=0;

    while (y != fact) {

        printf("%s\n", argv[1]);

        i=x-2;
        /*Here we search next. Ищем новую перестановку*/
        while(argv[1][i] > argv[1][i+1] ) i--;
        j=x-1;
        while(argv[1][j] < argv[1][i] ) j--;

        /*Change. Обмен*/
        c=argv[1][j];
        argv[1][j]=argv[1][i];
        argv[1][i]=c;
        i++;
        /*Tail reverse. Оборачиваем хвост*/
        for (j = x-1; j > i; i++, j--) {
            c = argv[1][i];
            argv[1][i] = argv[1][j];
            argv[1][j] = c;
        }
        y++;
    }
     printf("\nNumber of permutations = %d\n", fact);
}
