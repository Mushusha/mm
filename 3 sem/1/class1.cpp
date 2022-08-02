#include"f1.h"

CRat::CRat(int p[N], int q[N]) {
	for (int i = 0; i < N; i++) {
		this->p[i] = p[i];
		this->q[i] = q[i];
	}
}

void CRat::print() {
	for (int i = 0; i < N; i++)
		cout << p[i] << "/" << q[i] << " ";
	cout << "\n";
}

CRat CRat::reduction() {
        for (int i = 0; i < N; i++)
                for (int j = 1; j <= q[i]; j++)
                        if ((p[i] % j == 0) && (q[i] % j == 0)) {
                                p[i] = p[i] / j;
                                q[i] = q[i] / j;
                        }
        return CRat(p, q);
}

CRat CRat::operator+(const CRat &C) {
	for (int i = 0; i < N; i++) {
		p[i] = p[i] * C.q[i] + C.p[i] * q[i];
		q[i] = q[i] * C.q[i];
	}
	reduction();
	return CRat(p, q);
}

CRat CRat::operator-(const CRat &C) {
        for (int i = 0; i < N; i++) {
                p[i] = p[i] * C.q[i] - C.p[i] * q[i];
                q[i] = q[i] * C.q[i];
        }
	reduction();
        return CRat(p, q);
}

