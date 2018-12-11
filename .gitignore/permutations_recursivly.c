	/*Рекурсивный алгоритм порождения перестановок. Взят со stackoverflow. Авторы неизвестены*/ 
	
  #include <stdio.h>
		/*Функция перестановок*/
		  int permute(int * a, int i, int n) {
		
		    int b = 0;
		
		    if (i == n) {
		      for (b; b < n; b++)
		        printf("%d", a[b]);
		      printf("\n");
		
		    } else {
		
		      for (b = i; b < n; b++) {
		        swap(a, i, b);
		        permute(a, i + 1, n);
		        swap(a, i, b);
		
		      }
		    }
		  }
		
	  //Функция обмена
		int swap(int * a, int i, int b) {
		
		  int temp;
		
		  temp = a[i];
		  a[i] = a[b];
		  a[b] = temp;
		}
		
		int main() {
		
		  int n = 4;
		  int a[100] = {};
		  int j;
		  int i = 0;
		
	    /*Массив целых*/
		  for (j = 0; j <= n; j++) a[i++] = j;
		  permute(a, 0, n);
		
		}
