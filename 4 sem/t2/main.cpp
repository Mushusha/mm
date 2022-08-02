#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

class CMatrix {
public:
	int n;
	int m;
	double** matrix;
	CMatrix (double** matrix, int n, int m) {
		this->n = n;
		this->m = m;
		this->matrix = new double*[n];
		for (int i = 0; i < n; i++) {
			this->matrix[i] = new double[m];
			for (int j = 0; j < m; j++)
				this->matrix[i][j] = matrix[i][j];
		}
	}

	CMatrix(int n, int m) {
		this->n = n;
		this->m = m;
		this->matrix = new double*[n];
		for (int i = 0; i < n; i++) {
			this->matrix[i] = new double[m];
			for (int j = 0; j < m; j++)
				matrix[i][j] = 0;
		}
	}

	~CMatrix() {
		for (int i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
		n = 0;
	}

	void product0 (CMatrix v, CMatrix mat) {
		CMatrix R(v.n, 1);
		for (int i = 0; i < v.n; i++)
			for (int j = 0; j < v.n; j++)
				R.matrix[i][0] = R.matrix[i][0] + v.matrix[j][0]*mat.matrix[i][j];
	return;
	}

	void product1 (CMatrix v, CMatrix mat) {
		int n1, n2, n3, n4, N = int(v.n);
		n1 = N/2; n3 = N - n1;
		n2 = n1/2; n1 = n1 - n2;
		n4 = n3/2; n3 = n3 - n4;
		CMatrix R(v.n, 1);
		#pragma omp parallel sections 
		{
			#pragma omp section
			{
				for (int i = 0; i < n1; i++)
					for (int j = 0; j < n1; j++)
						R.matrix[i][0] = R.matrix[i][0] + v.matrix[j][0]*mat.matrix[i][j];
			}
			#pragma omp section
			{
				for (int i = n1; i < n1 + n2; i++)
					for (int j = n1; j < n1 + n2; j++)
						R.matrix[i][0] = R.matrix[i][0] + v.matrix[j][0]*mat.matrix[i][j];
			}
			#pragma omp section
			{for (int i = n1 + n2; i < n1 + n2 + n3; i++)
					for (int j = n1 + n2; j < n1 + n2 + n3; j++)
						R.matrix[i][0] = R.matrix[i][0] + v.matrix[j][0]*mat.matrix[i][j];
			}
			#pragma omp section
			{
				for (int i = n1 + n2 + n3; i < n1 + n2 + n3 + n4; i++)
					for (int j = n1 + n2 + n3; j < n1 + n2 + n3 + n4; j++)
						R.matrix[i][0] = R.matrix[i][0] + v.matrix[j][0]*mat.matrix[i][j];
			}
		}
	return;
	}
};

int main() {
	srand(time(NULL));
	int k = 10000000000;
	CMatrix A0 (k, 1);
	CMatrix A1 (k, 1);
	CMatrix B0 (k, k);
	CMatrix B1 (k, k);
	CMatrix C0 (k, 1);
	CMatrix C1 (k, 1);
	for (int i = 0; i < k; i++) {
		A0.matrix[i][0] = rand() % 10 + 1;
		A1.matrix[i][0] = A0.matrix[i][0];
		for (int j = 0; j < k; j++) {
			B0.matrix[i][0] = rand() % 10 + 1;
			B1.matrix[i][0] = B0.matrix[i][0];
		}
	}
	time_t t0, t1, t2;
	time(&t0);
	C0.product1(A0, B0);
	time(&t1);
	C1.product0(A1, B1);
	time(&t2);
	cout << "with OMP: " << (double)(t1 - t0) << endl;
	cout << "without OMP: " << (double)(t2 - t1) << endl;	
	return 0;
}

