#include <stdio.h>
#include <stdlib.h>
void f(double *, int, int);
void f(double *a, int p, int x)
{int m, r,  i, j, z;
m = 0;
z = 1;
r = 0;
for (i = 0; i < p; ++i)
{for (j = 0; j < i+1; ++j)
z = z*x;
m = m + a[i]*z;
z = 1;
}
printf ("%d \n", m);
for (i = 1; i < p; ++i)
{for (j = 1; j < i+1; ++j)
z = z*x;
r = r + i*a[i]*z;
z = 1;
}
printf ("%d \n", r);

}
int main (void)
{int p, m, k, x;
double *a;
FILE *in = fopen("20z.txt","r");

if(fscanf(in, "%d", &k)!=1)
{printf ("Ошибка при чтении размера.\n");
        fclose(in);
        return 1;
}
p=k;
a = (double*)malloc(sizeof(double)*k);
if (a == NULL)
{printf ("Ошибка при выделении памяти.\n");
fclose(in);
return 1;
}
m = -1;
while (fscanf(in, "%d", &k) == 1)
{(++m);
a[m]=k;
}
scanf("%d", &x);
f(a, p, x);
free (a);
fclose(in);
return (0);
}

