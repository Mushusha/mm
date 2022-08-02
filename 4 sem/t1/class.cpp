#include"f.h"
CVector::CVector() {
	for (int i = 0; i < N; i++)
		this->a[i] = 0;
}

CVector::CVector(int a[N]) {
	for (int i = 0; i < N; i++)
		this->a[i] = a[i];
}

int CVector0::output(const char *FileName) {
		FILE *f = fopen(FileName,"a+");
		for (int i = 0; i < N; i++)
			fprintf(f, "[%d] ", a[i]);
		fprintf(f, "\n");
                fclose(f);
                return 0;
	}

int CVector1::output(const char *FileName) {
		FILE *f = fopen(FileName,"a+");
		for (int i = 0; i < N; i++)
			fprintf(f, "{%d} ", a[i]);
		fprintf(f, "\n");
                fclose(f);
                return 0;
	}


CVector** Input(const char *file) {
	CVector **arr;
	int k = 1;
	int i = 0;
	char c;
	FILE *f = fopen(file, "r");
	while(!feof(f)) {
		fscanf(f, "%c", &c);
		if(c == '\n') k++;
	}
	rewind(f);
	arr = new CVector*[k];
	while (i < k) {
		int b[N];
		bool s = false;
		for (int j = 0; j < N; j++) {
			fscanf(f, "%d", &b[j]); 
			int p = 0;
			for (int t = 1; t < b[j]; t++)
				if (b[j] % t == 0) p++;
			if (p == 1) s = true;	
		} 
		if (s) {
			arr[i] = new CVector0;
			for (int t = 0; t < N; t++)
				arr[i]->a[t] = b[t];
		}
		else {	
			arr[i] = new CVector1;
			for (int t = 0; t < N; t++)
				arr[i]->a[t] = b[t];     
		}
		i++;
		s = false;
	}	
	fclose(f);
	return arr;
}

int count(char *s)
{
    FILE *f = fopen(s, "r");
    int n = 1;
    char c;
    while(!feof(f)) {
        fscanf (f, "%c", &c);
        if(c == '\n')
            n++;
    }
    fclose(f);
    return n;
}
