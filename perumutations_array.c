#include <stdio.h>
int main () {

	int i = 0;
    int j = 0;
    int fact = 1;//Факториал. Factorial
    int x = 0;   //Хранит длину строки. Var to let know length of a string
    int y = 0;   //Считаем число перестановок. It  calculates factorial
    int c;      //Для обмена. Buffer


	int argv[8]={1,2,3,4,5,6,7,0};

	/*It calculates an array's length. Вычислим длину строки*/
    for (x; argv[x]; x++);

/*Buble sort the array. Упорядочим алфавит*/

    for(i=0; i < x; i++) {
        for(j = x-1; j > i; j-- ) {
            if (argv[j-1] > argv[j]) {
                c=argv[j-1];
                argv[j-1]=argv[j];
                argv[j]=c;
            }
        }
    }

/*It calculates a factorial to stop the algorithm*. Вычислим факториал
  для остановки алгоритма*/

    while ( y!=x ) {
		  y++;
		  fact = y*fact;
}

/*Main part: here we permute. Порождаем перестановки
 до тех пор пока не дойдем до факториал - переменная fact*/

    y=0;

    while (y != fact) {

        for (j=0; argv[j] != 0; j++) printf("%d", argv[j]);
		printf("\n");


        i=x-2;
        /*Here we search next. Ищем новую перестановку*/
        while(argv[i] > argv[i+1] ) i--;
        j=x-1;
        while(argv[j] < argv[i] ) j--;

        /*Change. Обмен*/
        c=argv[j];
        argv[j]=argv[i];
        argv[i]=c;
        i++;
        /*Tail reverse. Оборачиваем хвост*/
        for (j = x-1; j > i; i++, j--) {
            c = argv[i];
            argv[i] = argv[j];
            argv[j] = c;
        }
        y++;
    }
}
