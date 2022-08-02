#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class CVector {
public:
	int n;
	double *a;
	CVector();
	CVector(const CVector &A);
	CVector(int n);
	CVector(double *a, int n);
	CVector(const char *file);
//	void print();
	virtual int output(const char *FileName = NULL) = 0;
	CVector& operator=(const CVector &D);
	~CVector();
};

class CVector0: public CVector {
public:
	CVector0(): CVector() {};
	CVector0(const CVector0 &A): CVector(A) {};
	CVector0(int n): CVector(n) {};
	CVector0(double *a, int n): CVector(a, n) {};
	CVector0(const char *file): CVector(file) {};
	~CVector0();
	void NewEl(double value, int index);
	CVector0& operator=(const CVector &D);
//	CVector0& operator=(const CVector0 &D);
	double operator*(const CVector0 &D);
	CVector0 operator+(CVector0 &D);
	CVector0 operator-(CVector0 &D);
	int output(const char *FileName);
};

class CVector1: public CVector {
public:
	CVector1(): CVector() {};
	CVector1(const CVector1 &A): CVector(A) {};
	CVector1(int n): CVector(n) {};
	CVector1(double *a, int n): CVector(a, n) {};
	CVector1(const char *file): CVector(file) {};
	~CVector1();
	void NewEl(double value, int index);
	CVector1& operator=(const CVector &D);
//	CVector1& operator=(const CVector1 &D);
	double operator*(const CVector1 &D);
	CVector1 operator+(CVector1 &D);
	CVector1 operator-(CVector1 &D);
	int output(const char *FileName);
};

int count(const char *ch);
CVector** Input(const char *file, char** FileName);

 
