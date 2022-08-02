#include"f.h"

int main() {
	char filename[20];
    	int i = 0;
	int n;
    	cout << "Enter filename: " << endl;
   	cin >> filename;
   	n = count (filename);
    	CVector **arr = Input(filename);
	FILE *f = fopen("out.txt","w");
	fclose(f);
    	for(i = 0; i < n; i++){
        	arr[i]->output("out.txt");
    	}
    	for(i = 0; i < n; i++){
		free (arr[i]);
    	}
    	delete [] arr;    
return 0;
}

