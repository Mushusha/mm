#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <time.h>
#include <ctime>
using namespace std;

class CFabric;
class CVector {
public:
	int n;
	double *a;
	CVector();
	CVector(const CVector &A);
	CVector(int n);
	CVector(double *a, int n);
//	CVector(string file);
//	void print();
	void NewEl(double value, int index);
	void Add(double value);
	virtual int output(string FileName = NULL) = 0;
	CVector& operator=(const CVector &D);
	virtual ~CVector();
	virtual string f() = 0;
	static int Input (string FileName, vector <CVector*> &arr, vector <CFabric*> &fabric);
	static void Out (string FileName, vector <CVector*> &arr, vector <CFabric*> &fabric);
};

class CFabric {
public:
	virtual CVector* Create(string FileName) = 0;
	virtual ~CFabric() {};
};

void Merge (double *a1, int n1, double *a2, int n2, double *r);
void MSort (double *m, int n, double *t);

class CVector0: public CVector {
public:
	string file;
	CVector0(): CVector() {};
	CVector0(const CVector0 &A): CVector(A) {};
	CVector0(int n): CVector(n) {};
	CVector0(double *a, int n): CVector(a, n) {};
	CVector0(string file): CVector() { this->file = file; };
	~CVector0();
//	void NewEl(double value, int index);
	CVector0& operator=(const CVector &D);
//	CVector0& operator=(const CVector0 &D);
	double operator*(const CVector0 &D);
	CVector0 operator+(CVector0 &D);
	CVector0 operator-(CVector0 &D);
	int output(string FileName);
	virtual string f() { return this->file; };
	void MSort0 ();
	void sum0 (CVector0 &A, CVector0 &B);
};

class CVector1: public CVector {
public:
	string file;
	CVector1(): CVector() {};
	CVector1(const CVector1 &A): CVector(A) {};
	CVector1(int n): CVector(n) {};
	CVector1(double *a, int n): CVector(a, n) {};
	CVector1(string file): CVector() { this->file = file; };
	~CVector1();
//	void NewEl(double value, int index);
	CVector1& operator=(const CVector &D);
//	CVector1& operator=(const CVector1 &D);
	double operator*(const CVector1 &D);
	CVector1 operator+(CVector1 &D);
	CVector1 operator-(CVector1 &D);
	int output(string FileName);
	virtual string f() { return this->file; };
	void MSort1 ();
	void sum1 (CVector1 &A, CVector1 &B);
};

//int count(const char *ch);

class CFabric0: public CFabric {
	CVector* Create(string FileName) { return new CVector0(FileName); }
	~CFabric0() {};
};

class CFabric1: public CFabric {
	CVector* Create(string FileName) { return new CVector1(FileName); }
	~CFabric1() {};
};