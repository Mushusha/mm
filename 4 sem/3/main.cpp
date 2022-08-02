#include"f.h"

void Test() {
	vector<CFabric*> fabric;
	vector<CVector*> v;
	string FileName;
	fabric.push_back(new CFabric0);
	fabric.push_back(new CFabric1);

	cout <<"Enter file name: "<< endl;
	cin >> FileName;
	fstream file(FileName);
	if (!file.is_open()) 
		cout << "Not open\n";
    	else if (file.peek() == EOF) 
		cout << "File empty\n";
	else 
		CVector::Out(FileName, v, fabric);
	
	for(size_t i = 0; i < v.size(); i++)
		delete v[i];

	for(size_t i = 0; i < fabric.size(); i++)
		delete fabric[i];
}

void Test3 () {
	srand(time(NULL));
	int k = 1000*1000*10;
	CVector0 A0 (k);
	CVector1 A1 (k);
	for (int i = 0; i < k; i++) {
		A0.a[i] = rand() % 10 + 1;
		A1.a[i] = A0.a[i];
	}
	time_t t0, t1, t2;
	time(&t0);
	A0.MSort0();
	time(&t1);
	A1.MSort1();
	time(&t2);
	cout << "with OMP: " << (double)(t1 - t0) << endl;
	cout << "without OMP: " << (double)(t2 - t1) << endl;	
}

void Test32 () {
	srand(time(NULL));
	int k = 4000*1000*100;
	CVector0 A0 (k);
	CVector1 A1 (k);
	CVector0 B0 (k);
	CVector1 B1 (k);
	CVector0 C0 (k);
	CVector1 C1 (k);
	for (int i = 0; i < k; i++) {
		A0.a[i] = rand() % 10 + 1;
		A1.a[i] = A0.a[i];
		B0.a[i] = rand() % 20 + 2;
		B1.a[i] = B0.a[i];
	}
	time_t t0, t1, t2;
	time(&t0);
	C0.sum0(A0, B0);
	time(&t1);
	C1.sum1(A1, B1);
	time(&t2);
	cout << "with OMP: " << (double)(t1 - t0) << endl;
	cout << "without OMP: " << (double)(t2 - t1) << endl;	
}

int main() {
	Test32();
	return 0;
}

