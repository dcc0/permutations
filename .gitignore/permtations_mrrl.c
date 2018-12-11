/*Алгоритм Андрея Астрелина*/
#include <stdio.h>
		
		  int main() {
		
		    int n = 8;
		    int perm[8] = {
		      0,
		      1,
		      2,
		      3,
		      4,
		      5,
		      6,
		      7
		    };
		    int a, j, i, x, p, mm, m;
		    int swap;
		
		    for (i = 1;; i++) {
		
		      for (a = 0; a < n; a++) printf("%d", perm[a]);
		      printf("\n");
		
		      mm = i;
		      m = n;
		      p = 0;
		
		      for (j = n; j > 0; j--) {
		        x = mm % j;
		        mm /= j;
		
		        if (x) {
		          if (mm % 2) x = j - x;
		
		          swap = perm[p - 1 + x];
		          perm[p - 1 + x] = perm[p + x];
		          perm[p + x] = swap;
		
		          break;
		        } else {
		          p += 1 - mm % 2;
		        }
		      }
		      if (!j) break;
		    }
		  }
		
