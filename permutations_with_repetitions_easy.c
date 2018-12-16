/*Порождение перестановок с повторением вида 1244*/
#include <stdio.h>
int main() {
        char a[] = "4421";  //array
           int i, j;
           int f=24/(2*1*1); /*factorial n / op. of repeated permutations. Делим n! на произведение факториалов повторяющихся
           элементов  по формуле 4!/(2!*1*1)*/
           char c;           //buffer
          while (f--) {
          printf("%s\n", a);
          i=1;
          while(a[i] >= a[i-1]) i++; /* Добавим знак = для пропуска равных*/
          j=0;
          while(a[j] <= a[i])j++; /* Добавим знак = для пропуска равных*/
      c=a[j];
      a[j]=a[i];
      a[i]=c;
i--;
for (j = 0; j < i; i--, j++) {
  c = a[i];
  a[i] = a[j];
  a[j] = c;
      }
   }
}
