/*Программа порождает перестановки циклическим сдвигом - спиральная геометрия*/
#include <stdio.h>

	int main () {

		/*Определить: строку, факториал и n.*/
		char str[7]="1234567";
		int fact = 5040;
		int n = 7;
		/*Размер swap должен быть равен str*/
		char swap[7];
		int a, i, j, m, mm;


    for (a = 1; a != fact + 1; a++) {

		mm = a;
		m = n;

		printf("%s\n", str);

	while (m > 0)
			{
		/*Проверка на делимость по модулю. Уменьшаем m*/	
			if (mm % m == 0) {
			mm/= m--;
			}
			else
			{

		j = 0;
	for (i =  n - m + 1; i <= n-1; i++, j++)
		swap[j]=str[i];
		swap[j]='\0';

	for (i =  n - m; i >= 0; i--, j++)
		swap[j]=str[i];
		swap[j]='\0';

	for (i = 0; i <= n-1; i++)
		str[i]=swap[i];

		break;
			}
		}
	}
}
