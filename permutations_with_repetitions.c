#include < stdio.h > 
#include < string.h >

  int main(int argc, char * argv[]) {

    int i = 0;
    int j = 0;
    int x = 0; //Хранит длину строки. Var to let know length of a string
    int y = 0; //Считаем число перестановок. It counts number.
    char c; //Для обмена. Buffer
    char ch[33]; //Хранит перевернутую копию аргумента. Reversed copy of an argument

    /*Here we check arguments. Проверим аргументы*/
    if (argc < 2) {
      printf("Enter an argument. Example 12233 or 1234:\n");
      return 0;
    }

    /*It calculates an array's length. Вычислим длину строки*/
    for (x; argv[1][x]; x++);

    /*Buble sort an array. Упорядочим алфавит*/
    for (i = 0; i < x; i++) {
      for (j = x - 1; j > i; j--) {
        if (argv[1][j - 1] > argv[1][j]) {
          c = argv[1][j - 1];
          argv[1][j - 1] = argv[1][j];
          argv[1][j] = c;
        }
      }
    }

    /*Копируем аргумент в переменную ch
     Copy argument to ch variable*/
    strcpy(ch, argv[1]);

    i = x;
    j = 0;

    /*Перевернем переменную ch - нужна для остановки алгоритма.
     Reverse ch. It's needed to stop the algorithm*/
    while (i > j) {
      i--;
      c = ch[j];
      ch[j] = ch[i];
      ch[i] = c;
      j++;

    }

    /*Main part: here we permute. Порождаем перестановки*/
    y = 0;

    while (1) {
      y++;
      printf("%s\n", argv[1]);
      if (strcmp(argv[1], ch) == 0) break;
      i = x - 2;

      /*Here we search next. Ищем новую перестановку*/
      while (argv[1][i] >= argv[1][i + 1]) i--;
      j = x - 1;
      while (argv[1][j] <= argv[1][i]) j--;

      /*Change. Обмен*/
      c = argv[1][j];
      argv[1][j] = argv[1][i];
      argv[1][i] = c;
      i++;

      /*Tail reverse. Оборачиваем хвост*/
      for (j = x - 1; j > i; i++, j--) {
        c = argv[1][i];
        argv[1][i] = argv[1][j];
        argv[1][j] = c;
      }

    }
    printf("\nNumber of permutations = %d\n", y);
  }
