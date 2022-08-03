#include <stdio.h>
int main (void)
{int mn, tmp, k;
FILE *in;
in = fopen("13z.txt","r");
if (in == NULL)
{printf("Не удалось открыть файл.\n");
return 1;
}
if (fscanf(in,"%d",&mn)!=1)
{printf("Не удалось прочитать первое число.\n");
printf("Определить кол-во элементов, равных минимальному не удалось.\n");
return 0;
}
k = 1;
while (fscanf (in, "%d", &tmp) == 1)
{if (tmp<mn)
	{mn = tmp;
	k = 0;
	}
if (tmp == mn) k = k + 1; 
}
printf ("Количество элементов, равных минимальному: %d.\n", k);
fclose(in);
return(0);
}
