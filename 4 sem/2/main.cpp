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
	
	for(int i = 0; i < v.size(); i++)
		delete v[i];

	for(int i = 0; i < fabric.size(); i++)
		delete fabric[i];
}

int main() {
	Test();
	return 0;
}

