#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int search(const char *SInputFile, char *word)
{int m, k, i, z = 0;
char s;
char min[513];
FILE *in = fopen(SInputFile,"r");
if (in == NULL)
{
printf("error");
return (-1);
}
while ((s = getc(in)) != EOF)
if (s == '"')
{
for (i = 0; (s = getc(in)) != '"'; ++i) min[i] = s;
min[i] = 0;
k = atoi(min);
if (z == 0) {m = k; z = 1;}
if (k < m) {m = k; strcpy(word, min);}
}
return 0;
}
int main(void)
{const char *SInputFile = "111.txt";
char w[513];

search(SInputFile, w);
printf("%s\n", w);
return 0;
}
