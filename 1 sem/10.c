#include <stdio.h>
int main (void)
{int z, x, k, tmp, a;
FILE *in;
in = fopen("10z.txt","r");
if (in == NULL)
{printf("Не удалось открыть файл.\n");
return 1;
}
if (fscanf(in,"%d",&a)!=1)
{printf("Не удалось прочитать первое число.\n");
printf("не удалось определить общее количество элементов на постоянных участках последовательности.\n");
return 0;
}
k = 0;
x = 0;
z = 0;
while(fscanf(in,"%d",&tmp) == 1)
{k +=1;
if (a == tmp && z == 0)
{x += 1;
z += 1;
}
if (tmp != a)
{x -= 1;
z = 0;
a = tmp;
}
}
printf ("Общее количество элементов на постоянных участках последовательности: %d.\n",k+x); 
fclose(in);
return (0);
}


