#include<iostream>
#include<fstream>
#include<math.h>
#include<float.h>
#include<stdlib.h>
using namespace std;

double R (double x1, double y1, double x2, double y2) {
	return (sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
}

double S (double a, double b, double c) {
	double p = (a + b + c)/2;
	return(sqrt(p*(p-a)*(p-b)*(p-c)));
}

int main() {
	int m, n;
	cout << "Enter m and n: ";
	cin >> m >> n;
	int k = 0;
	ifstream fis("a.txt");
        double *w= (double*)malloc(k*sizeof(double));
	while (!fis.eof()) {
		k++;
		w = (double*)realloc(w, k*sizeof(double));
		fis >> w[k - 1];
	}
	int i;
	k = k/2;
	double *x = (double*)malloc(k*sizeof(double));
	double *y = (double*)malloc(k*sizeof(double));
	for (i = 0; i < k; i++) {
		x[i] = w[i*2];
		y[i] = w[i*2 + 1];
	}
	double *area = (double*)malloc((k-2)*sizeof(double));
	for (int i = 1; i < k - 1; i++) {
		double a = R(x[0], y[0], x[i], y[i]);
		double b = R(x[0], y[0], x[i + 1], y[i + 1]);
		double c = R(x[i], y[i], x[i + 1], y[i + 1]);
		area[i - 1] = S(a, b, c);
	}
	double sq = 0;
	for (int i = 0; i < k - 2; i++) sq += area[i];
	double sm = sq*m/(n + m);
	double sn = sq*n/(n + m);
	double sm1 = 0;
	double sn1 = 0;
	int j = 0;
	while (sm1 < sm) 
		sm1 += area[j++];
	double z[2];
	for (int i = j; i < k - 2; i++)
		sn1 += area[i];

	if ((sn1 - sn) < 0.001 && (sm1 - sm) < 0.001) {
		z[0] = x[j + 1];
		z[1] = y[j + 1];
	}
	else {
		j--;
		sm1 -= area[j];
		sm1 = sm - sm1;
		sn1 = sn - sn1;
		z[0] = (x[j + 1] + x[j + 2]*sm1/sn1)/(1 + sm1/sn1);
		z[1] = (y[j + 1] + y[j + 2]*sm1/sn1)/(1 + sm1/sn1);
	}	
	cout << "m poligon:\n";
	int t = j + 2;
	if ((z[0] - x[j + 1]) < 0.001 && (z[1] - y[j + 1]) < 0.001) t--;
	for (int i = 0; i < t; i++)
		cout << "(" << x[i] << ", " << y[i] << "), ";
	cout << "(" << z[0] << ", " << z[1] << ")";
	cout << "\nn poligon:\n";
	cout << "(" << x[0] << ", " << y[0] << "), ";
	cout << "(" << z[0] << ", " << z[1] << ")";
	for (int i = j + 2; i < k; i++)
               	cout << ", (" << x[i] << ", " << y[i] << ")";
	
	free(x);
	free(y);
	free(area);
	free(w);
	return 0;
}
