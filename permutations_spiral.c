/*Программа порождает перестановки методом сдвига - спиральная геометрия (перестановки для суперперестановок)
 Алгоритм: 1) Если переменная от n делится с остатком на  переменную от номера итерации, то обмен - сдвиг на одну позицию.
2) Если делится без остатка, то переменная от номера итерации делится на переменную от n,
n уменьшается. Далее повтор внутрннего цикла. Так достигается дополнительный сдвиг.*/

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
