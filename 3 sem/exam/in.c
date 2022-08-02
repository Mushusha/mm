#include "f.h"

int Input(const char *fn, char ***s, int *n)
{
	FILE *f;
	int i, err;
	char str[256];
	f = fopen(fn, "r");
	if(f == NULL) {
		err = -1;
		goto lm;
	}
	else {
 	if(fgets(str, 256, f) == NULL) {
		err = -2; 
		goto lc;
	}
	else {
		rewind(f);
  		for(*n = 0; fscanf(f, "%s", str) != -1; (*n)++) {}
		*s=(char**)malloc((*n+1)*sizeof(char**));
  		for(i = 0; i < (*n); i++) 
			(*s)[i]=(char*)malloc(256*sizeof(char));
  		rewind(f);
  		for(*n = 0; fscanf(f, "%s", str) != -1 && sscanf(str, "%s", (*s)[*n]) == 1; (*n)++) {}
  		err=0;
 	}
	}
	lc:
	fclose(f);
	lm:
	return err;
}
