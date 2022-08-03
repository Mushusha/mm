#include <stdio.h>
#include <stdlib.h>
int main (void)
{int k, i, s, j, p, maxstr, t;
char ch;
int* a;
int* c;
double* sredar;
int** m;
FILE *in = fopen("data.dat","r");
FILE *out = fopen("data.res", "w");
s = 1;
while ((ch = getc(in)) != EOF)
    if (ch =='\n') ++s;
rewind(in);
a = (int*)malloc(s*sizeof(int));
i = 0;
a[0] = 1;
maxstr = 0;
while ((ch = getc(in)) != EOF)
    {
    if (ch == ' ') a[i] = a[i] + 1;
    if (ch =='\n') {++i; a[i] = 1;}
    if (a[i] > maxstr) maxstr = a[i];
    }
m = (int**)malloc(s*sizeof(int*));
for (i = 0; i < s; ++i)
    m[i] = (int*)malloc(a[i]*sizeof(int));
rewind(in);
for (i = 0; i<s; ++i)
    for (j = 0; j<a[i]; ++j)
        fscanf(in, "%d", &m[i][j]);
sredar = (double*)malloc(maxstr*sizeof(double));
c = (int*)malloc(maxstr*sizeof(int));
for (i = 0; i<maxstr; ++i) {sredar[i] = 0; c[i] = 0;}
for (i = 0; i<s; ++i)
    for (j = 0; j<a[i]; ++j)
    {
    sredar[j] = sredar[j] + m[i][j];
    c[j] = c[j] + 1;
    }
for (i = 0; i<maxstr; ++i) sredar[i] = sredar[i]/c[i];

for (i = 0; i<s; ++i)
    {
    p = 0;
    for (j = 0; j<a[i]; ++j)
        if (m[i][j] == sredar[j]) ++p;
    if (p == a[i])
        {for (k = i; k < s; ++k)
            {
            a[k] = a[k+1];
            m[k] = m[k+1];
            }
            --s;
            --i;
        }
    }
for (i = 0; i<s; ++i)
    {
    for (j = 0; j<a[i]; ++j)
        fprintf(out,"%d ", m[i][j]);
    fprintf(out, "\n");
    }

for (i = 0; i<s; ++i)
    {
    for (j = 0; j<a[i]; ++j)
        printf("%d ", m[i][j]);
    printf("\n");
    }

free(a);
free(c);
for (i = 0; i < s; ++i) free(m);
free(sredar);
fclose(in);
fclose(out);
return 0;
}

