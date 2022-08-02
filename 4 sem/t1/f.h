#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#define N 6
using namespace std;

class CVector {
public:
	int a[N];
	CVector();
	CVector(int a[N]);
	virtual int output(const char *FileName) = 0;
};

class CVector0: public CVector {
public:
	CVector0(): CVector() {};
	CVector0(int a[N]): CVector(a) {};
	int output(const char *FileName);
};

class CVector1: public CVector {
public:
	CVector1(): CVector() {};
	CVector1(int a[N]): CVector(a) {};
	int output(const char *FileName);

};

CVector** Input(const char *file);
int count(char *s);


 
