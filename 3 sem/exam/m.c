#include "f.h"

int main() {
	int err, size, i, k;
	k = 4;
  	char **array;
  	err = Input("e.txt", &(array), &size);
  	if (err != 0)
		printf("error = %d\n", err);
  
  	else {
   		for (i = 0; i < size; i++)
     			printf("%s\n", array[i]);
		printf ("%s\n", statk(array, k, size));
	}
	return 0;
}
