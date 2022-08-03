#include <stdio.h>
#include <stdlib.h>
int main (void)
{int p, m,  k, i, b=0, c=0;
double *a;
double s;
FILE *in = fopen("6z.txt","r");

if(fscanf(in, "%d", &k)!=1)
{printf ("Ошибка при чтении размера.\n");
	fclose(in);
	return 1;
}
a = (double*)malloc(sizeof(double)*k);
if (a == NULL)
{printf ("Ошибка при выделении памяти.\n");
fclose(in);
return 1;
}
p = k;
m = -1;
while (fscanf(in, "%d", &k) == 1)
{(++m);
a[m]=k;
}
for (i = 0; i < p; ++i)
{if (a[i] < 0) b = i;
break;
}
for (i = 0; i < p; ++i)
if (a[i] < 0) c = i;

s = 0;
for (i = b+2; i < c; ++i) 
s = s + a[i];
printf ("Ответ: %lf",s);
free (a);
fclose(in);
return (0);
}

