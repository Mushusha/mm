#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void f(double *, int);
void f(double *a, int n)
{int d, s, i, j;
s = 0;
for (i = 1; (i < n) && !s; ++i)
{s = 1;
for (j = 0; j < n - 1; ++j)
{if (a[j] > a [j+1])
{d = a[j+1];
a[j+1] = a[j];
a[j] = d;
s = 0;
}
}
printf ("%lf",a[i]);
}
}
int main (void)
{int  m, k, n;
double *a;
FILE *in = fopen("2z.txt","r");

if(fscanf(in, "%d", &k)!=1)
{printf ("Ошибка при чтении размера.\n");
        fclose(in);
        return 1;
}
n=k;
a = (double*)malloc(sizeof(double)*k);
if (a == NULL)
{printf ("Ошибка при выделении памяти.\n");
fclose(in);
return 1;
}
k = n;
m = -1;
while (fscanf(in, "%d", &k) == 1)
{(++m);
a[m]=k;
}
f(a, n);
free (a);
fclose(in);
return (0);
}

