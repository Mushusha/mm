#include <stdio.h>
#include <stdlib.h>
void f(double *, int);
void f(double *a, int p)
{int i, j, n, t;
n = 0;
for (i = 0; i < p; ++i)
	if (a[i] < 0) (++n);
if (n != p)
for (i = 0; i < p; ++i) 
if (a[i] < 0) 
	for (j = i; j < p; ++j)
		if (a[j] >= 0) 
		{t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
if (n != p)
for (i = 0; i < p; ++i)
if (a[i] < 0) a[i] = 0; 
if (n == p)
	for (i = 0; i < p; ++i)
		a[i] = 0;

}

int main (void)
{int i, m, k, p;
double *a;
FILE *in = fopen("14z.txt","r");

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
f(a, p);
for (i = 0; i < p; ++i)
printf ("%lf ",a[i]);
free (a);
fclose(in);
return (0);
}
