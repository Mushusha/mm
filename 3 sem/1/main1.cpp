#include"f1.h"
#include <fstream>

int main() {
	int pa[N], pb[N];
	int qa[N], qb[N];
	ifstream fis("1.txt");
	for (int j = 0; j < 4; j++)
		for (int i = 0; i < N; i++) {
			switch (j) {
				case 0:
					fis >> pa[i];
					break;
				case 1:
					fis >> qa[i];
					break;
				case 2: 
					fis >> pb[i];
					break;
				case 3:
					fis >> qb[i];
					break;
				}
	}
	
	CRat A(pa, qa);
	CRat B(pb, qb);
	A.print();
	B.print();
	A = A + B;
	A.print();
	B = B - A;
	B.print();

	return 0;
}
