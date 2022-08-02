#include"f2.h"

CVector::CVector(): n(0), a(nullptr) {
}

CVector::CVector(const CVector &D) {
	this->n = D.n;
	this->a = new double[D.n];
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
}

CVector::CVector(int n) {
	this->n = n;
	a = new double [n];
}

CVector::CVector(double *a, int n) {
	this->n = n;
	this->a = new double [n];
	for (int i = 0; i < n; i++)
		this->a[i] = a[i];
}

void CVector::print() {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

CVector& CVector::operator=(const CVector &D) {
	this->n = D.n;
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
	return (*this);
}

CVector CVector::operator+(const CVector &D) {
	CVector s(D.n);
        for (int i = 0; i < D.n; i++)
                s.a[i] = this->a[i] + D.a[i];
        return s;
}

CVector CVector::operator-(const CVector &D) {
	CVector s(D.n);
        for (int i = 0; i < D.n; ++i)
                s.a[i] = this->a[i] - D.a[i];
        return s;
}

double CVector::operator*(const CVector &D) {
	double k = 0;
        for (int i = 0; i < n; i++)
                k = k + a[i]*D.a[i];
        return k;
}

void CVector::NewEl(double value, int index) {
        double *a1 = new double[n+1];
        for (int i = 0; i < index; i++)
        	a1[i] = a[i];
        a1 [index] = value;
        for (int i = index; i < n; i++)
        	a1[i+1] = a[i];
        delete[] a;
        a = a1;
        ++n;
}

CVector::~CVector() {
	delete [] a;
	n = 0;
}

	
	
