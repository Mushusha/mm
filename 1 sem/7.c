#include <stdio.h>
int main (void)
{int k, x, tmp, a;
FILE *in;
in = fopen("7z.txt","r");
if (in == NULL)
{printf("Не удалось открыть файл.\n");
return 1;
}
if (fscanf(in,"%d",&a)!=1)
{printf("Не удалось прочитать первое число.\n");
printf("Определить монотонность не удалось.\n");
return 0;
}
k = 0;
x = 0;
while(fscanf(in,"%d",&tmp)==1)
{k += 1;
if(tmp>a) x += 1 ;
if(tmp<a) x -= 1 ;
a = tmp;
}

if (x == k)
{printf("Последовательность возрастающая.\n");
}
if (x == -k)
{printf("Последовательность убывающая.\n");
}
if (x != -k && x != k)
{printf("Последовательность не убывает и не возрастает.\n");
}

fclose(in);
return (0);
}

