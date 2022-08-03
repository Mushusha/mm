#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void gauss (int, int, double**, double);
void gauss (int m, int n, double** a, double eps)
{
    int i, j, k, l;
    double r;
    i = 0; j = 0;
    while (i < m && j < (2*n))
    {
        r = 0.0;
        for (k = i; k < m; ++k)
            if (fabs(a[k][j]) > r)
        {
            l = k;
            r = fabs(a[k][j]);
        }
        if (r < eps)
        {
            for (k = i; k < m; ++k)
                a[k][j] = 0.0;
            ++j;
            continue;
        }
        if (l != i)
            for (k = j; k < (2*n); ++k)
            {
                r = a[i][k];
                a[i][k] = a[l][k];
                a[l][k] = (-r);
            }
        for (k = i + 1; k < m; ++k)
        {
            r = (-a[k][j]/a[i][j]);
            a[k][j] = 0.0;
            for (l = j + 1; l < (2*n); ++l)
                a[k][l] += r*a[i][l];
        }
        ++i; ++j;
    } \
    for (i = 0; i < m; ++i)
        {r = a[i][i];
        for (j = 0; j < (2*n); ++j)
            a[i][j] = a[i][j] / r;
        }

    for (i = m - 1 ; i > 0; --i)
        for (k = 1; k < i + 1; ++k)
            {r = a[i-k][i];
            for (j = 0; j < (2*n); ++j)
                    a[i-k][j] = a[i-k][j] - a[i][j]*r;
            }
}

int main (void)
{int i, j, m, n;
double eps;
double** a;
eps = 0.000001;
FILE *in = fopen("111.txt","r");
fscanf (in, "%d", &m);
fscanf (in, "%d", &n);
a = (double**)malloc(m*sizeof(double*));
for (i = 0; i < m; ++i)
    a[i] = (double*)malloc((2*n)*sizeof(double));
for (i = 0; i < m; ++i)
    for (j = 0; j < n; ++j)
        fscanf(in, "%lf", &a[i][j]);

for (i = 0; i<m; ++i)
    for (j = n; j < (2*n) ; ++j)
     if ((n + i) == j) a[i][j] = 1.0;
        else a[i][j] = 0.0;

gauss(m, n, a, eps);

for (i = 0; i < m; ++i)
    {
    for (j = n; j < (2*n); ++j)
        printf("%lf ", a[i][j]);
    printf("\n");
    }

for (i = 0; i < m; ++i) free(a);
fclose(in);
return 0;
}
