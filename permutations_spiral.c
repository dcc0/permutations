/*Программа порождает перестановки циклическим сдвигом - спиральная геометрия (перестановки для суперперестановок)*/
#include < stdio.h >

int main() {

    /*Определить: строку, факториал и n.*/
    char str[3] = "123";
    int fact = 6;
    int n = 3;
    /*Размер swap должен быть равен str*/
    char swap[3];
    int a, i, j, m, mm;

    for (a = 1; a != fact + 1; a++) {

        mm = a;
        m = n;

        printf("%s\n", str);

        while (m > 0) {
            /*Проверка на делимость по модулю. Уменьшаем m*/
            if (mm % m == 0) {
                mm /= m--;
            } else {

                j = 0;
                /*Обмен и оборот одной части*/
                for (i = n - m + 1; i <= n - 1; i++, j++)
                    swap[j] = str[i];
                swap[j] = '\0';

                for (i = n - m; i >= 0; i--, j++)
                    swap[j] = str[i];
                swap[j] = '\0';
                
                /*Собираем вместе*/
                for (i = 0; i <= n - 1; i++)
                    str[i] = swap[i];

                break;
            }
        }
    }
}
