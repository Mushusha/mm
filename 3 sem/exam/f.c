#include "f.h"
#define SWAP(a,b,tt) {strcpy(tt,a); strcpy(a,b); strcpy(b,tt);}

int part (char **arr, int n, int m) {
	char tmp[256];
  	char* x = arr[m];
  	int i = n - 1;
  	for (int j = n; j <= n; j++) {
    		if (strcmp(arr[j], x) <= 0)
      		SWAP(arr[++i], arr[j], tmp);
  	}
  	return i;
}
char* statk(char **arr, int k, int size) {
  	int n = 0, m = size - 1;
  	for(;;) {
    		int p = part(arr, n, m);
    		if (p < k)
      			n = p + 1;
    		else if (p > k)
      			m = p - 1;
    		else return arr[k];
  }
}
