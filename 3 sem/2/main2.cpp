#include"f2.h"
#include <cstdlib>

int main() {
	int n = 8;
	double *a = new double [n];
	double *b = new double [n];
	double *c = new double [n];
	bool q = 1;
	for (int j = 0; j < 1000; j++) {
		for (int i = 0; i < n; i++) {
			a[i] = 0.01 * rand();
			b[i] = 0.01 * rand();
			c[i] = a[i] + b[i];
		}
		CVector A(a, n);
		CVector B(b, n);
		CVector C(n);
		C = A + B;
		for (int k = 0; k < n; k++) 
			q = q && (C.a[k] == c[k]);
	}
	if (q == 1)
		cout << "Addition is correct\n";
	CVector A(a, n);
	CVector B(b, n);
	CVector C(n);
	cout << "vector a:\n";
	A.print();
	cout << "vector b:\n";
	B.print();
	C = A + B;
	cout << "a + b:\n";
	C.print();
	C = B - A;
	cout << "a - b:\n";
	C.print();
	A.NewEl(5, 1);
	B.NewEl(6, 1);
	cout << "new element in a:\n";
	A.print();
	cout << "new element in b:\n";
	B.print();
	double k;
	k = A * B;
	cout << "a * b = " << k << endl;
	delete [] a;
	delete [] b;
	delete [] c;
	return 0;
}

