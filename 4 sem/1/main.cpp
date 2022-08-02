#include"f.h"


void Test() {
	char f[32];
	int k = 0, i = 0;
	cout << "Enter filename: "<< endl;
	cin >> f;
	k = count(f);
	char **FileName = new char*[k];
	for(i = 0; i < k; i++)
		FileName[i] = new char[256];
    	CVector **arr = Input(f, FileName);

	for(i = 0; i < k; i++) {
		FILE *f = fopen(FileName[i],"w");
		fclose(f);
	}

    	for(i = 0; i < k; i++)
        	arr[i]->output(FileName[i]);

    	for(i = 0; i < k; i++) {
        	free (arr[i]->a);
        	free (arr[i]);
    	}
    	delete [] arr;
    	for(i = 0; i < k; i++)
        	delete [] FileName[i];
    	delete [] FileName;
}

int main() {
	Test();
	return 0;
}

