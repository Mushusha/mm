#include <stdio.h>
#include <stdlib.h>
int main (void)
{int i, j, p, m, n, k;
double* sredar;
int** a;
FILE *in = fopen("data.dat","r");
FILE *out = fopen("data.res", "w");
fscanf (in, "%d", &m);
fscanf (in, "%d", &n);
a = (int**)malloc(m*sizeof(int*));
for (i = 0; i < m; ++i)
    a[i] = (int*)malloc(n*sizeof(int));
for (i = 0; i<m; ++i)
    for (j = 0; j<n; ++j)
        fscanf(in, "%d", &a[i][j]);

sredar = (double*)malloc(m*sizeof(double));
for (i = 0; i<m; ++i) sredar[i] = 0;

for (j = 0; j<n; ++j)
    for (i = 0; i<m; ++i)
        sredar[i] = sredar[i] + a[i][j];

for (i =0; i < m; ++i) sredar[i] = sredar[i] / n;

for (j = 0; j<n; ++j)
    {
    p = 0;
    for (i = 0; i<m; ++i)
        if (a[i][j] == sredar[i]) ++p;
    if (p == m)
        {for (k = j; k < n; ++k)
            for (i = 0; i < m; ++i)
            a[i][k] = a[i][k+1];
        }
    --n;
    break;
    }

for (i = 0; i<m; ++i)
    {
    for (j = 0; j<n; ++j)
        printf("%d ", a[i][j]);
    printf("\n");
    }

for (i = 0; i<m; ++i)
    {
    for (j = 0; j<n; ++j)
        fprintf(out, "%d ", a[i][j]);
    fprintf(out, "\n");
    }

for (i = 0; i < m; ++i) free(a);
free(sredar);
fclose(in);
fclose(out);
return 0;
}


