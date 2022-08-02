#include<iostream>
#include<stdlib.h>

using namespace std;

class CVector {
	int n;
public:
	double *a;
	CVector();
	CVector(const CVector &A);
	CVector(int n);
	CVector(double *a, int n);
	void Clean();
	void Zero();
	void print();
	void NewEl(double value, int index);
	CVector& operator=(const CVector &D);
	CVector operator+(const CVector &D);
	CVector operator-(const CVector &D);
	double operator*(const CVector &D);
	~CVector();
};

