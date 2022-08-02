#include"f.h"

CVector::CVector(): n(0), a(nullptr) {
}

CVector::CVector(const CVector &D) {
	this->n = D.n;
	this->a = new double[D.n];
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
}

CVector::CVector(int n) {
	this->n = n;
	a = new double [n];
}

CVector::CVector(double *a, int n) {
	this->n = n;
	this->a = new double [n];
	for (int i = 0; i < n; i++)
		this->a[i] = a[i];
}

/*
CVector::CVector(string file){
    FILE *f = fopen(file,"r");
    int n;
    fscanf(f,"%d",&n);
    this->n = n;
    this->a = new double[n];
    for(int i = 0; i < n; i++)
        fscanf(f,"%lf",&(this->a[i]));
    fclose(f);
}
*/
/*
void CVector::print() {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}
*/

CVector& CVector::operator=(const CVector &D) {
	this->n = D.n;
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
	return (*this);
}

void CVector::NewEl(double value, int index) {
        double *a1 = new double[n + 1];
        for (int i = 0; i < index; i++)
        	a1[i] = a[i];
        a1 [index] = value;
        for (int i = index; i < n; i++)
        	a1[i+1] = a[i];
        delete[] a;
        a = a1;
        ++n;
}

void CVector::Add(double value) {
//NewEl(value, n);
	double *a1 = new double[n + 1];
        for (int i = 0; i < n; i++)
        	a1[i] = a[i];
        a1 [n] = value;
        delete[] a;
        a = a1;
	n++;

}

/*
void CVector0::NewEl(double value, int index) {
        double *a1 = new double[n+1];
        for (int i = 0; i < index; i++)
        	a1[i] = a[i];
        a1 [index] = value;
        for (int i = index; i < n; i++)
        	a1[i+1] = a[i];
        delete[] a;
        a = a1;
        ++n;
}

void CVector1::NewEl(double value, int index) {
        double *a1 = new double[n+1];
        for (int i = 0; i < index; i++)
        	a1[i] = a[i];
        a1 [index] = value;
        for (int i = index; i < n; i++)
        	a1[i+1] = a[i];
        delete[] a;
        a = a1;
        ++n;
}
*/

CVector::~CVector() {
	delete [] a;
	n = 0;
}

CVector0 CVector0::operator+(CVector0 &D) {
	CVector0 F;
	F.n = D.n;
	F.a = new double[this->n];
        for (int i = 0; i < D.n; i++)
                F.a[i] = D.a[i] + this->a[i];
        return F;
}

CVector0 CVector0::operator-(CVector0 &D) {
	CVector0 F;
	F.n = D.n;
	F.a = new double[this->n];
        for (int i = 0; i < D.n; i++)
                F.a[i] = this->a[i] - D.a[i];
        return F;
}

CVector1 CVector1::operator+(CVector1 &D) {
	CVector1 F;
	F.n = D.n;
	F.a = new double[this->n];
        for (int i = 0; i < D.n; i++)
                F.a[i] = D.a[i] + this->a[i];
        return F;
}

CVector1 CVector1::operator-(CVector1 &D) {
	CVector1 F;
	F.n = D.n;
	F.a = new double[this->n];
        for (int i = 0; i < D.n; i++)
                F.a[i] = this->a[i] - D.a[i];
        return F;
}

CVector0::~CVector0() {
	delete [] a;
	n = 0;
}

CVector1::~CVector1() {
	delete [] a;
	n = 0;
}

int CVector0::output(string FileName) {
	ofstream fos(FileName, ios::app);
	for (int i = 0; i < n; i++)
		fos << a[i] << " ";
	fos<< "\n---------------------------\n";
	fos.close();
	return 0;
}

int CVector1::output(string FileName) {
	ofstream fos(FileName, ios::app);
	for (int i = 0; i < n; i++)
		fos << a[i] << endl;
	fos << "---------------------------\n";
	fos.close();
	return 0;
}

CVector0& CVector0::operator=(const CVector &D) {
	this->n = D.n;
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
	return (*this);
}

CVector1& CVector1::operator=(const CVector &D) {
	this->n = D.n;
	for (int i = 0; i < D.n; i++)
		this->a[i] = D.a[i];
	return (*this);
}

double CVector0::operator*(const CVector0 &D) {
	double k = 0;
        for (int i = 0; i < n; i++)
                k = k + a[i]*D.a[i];
        return k;
}

double CVector1::operator*(const CVector1 &D) {
	double k = 0;
        for (int i = 0; i < n; i++)
                k = k + a[i]*D.a[i];
        return k;
}

void Merge (double *a1, int n1, double *a2, int n2, double *r) {
	int i1, i2, i;
	for (i1 = 0, i2 = 0, i = 0; i1 < n1 && i2 < n2; )
		if(a1[i1] < a2[i2]) r[i++] = a1[i1++];
		else r[i++] = a2[i2++];
	while (i1 < n1) r[i++] = a1[i1++];
	while (i2 < n2) r[i++] = a2[i2++];
}

void MSort (double *m, int n, double *t) {
 	int n1, n2;
	if (n <= 1) return;
	n1 = n/2;
	n2 = n - n1;
	MSort (m, n1, t);
	MSort (m + n1, n2, t);
	Merge (m, n1, m + n1, n2, t);
	memcpy(m, t, n*sizeof(int));
}

void CVector0::MSort0 () {
	int n1, n2, n3, n4, N = (int)n;
	if (N <= 1) return;
	n1 = N/2; n3 = N - n1;
	n2 = n1/2; n1 = n1 - n2;
	n4 = n3/2; n3 = n3 - n4;
	double *t = new double[N];
	#pragma omp parallel sections 
	{
		#pragma omp section
			{ MSort (a, n1, t); }
		#pragma omp section
			{ MSort (a + n1, n2, t + n1); }
		#pragma omp section
			{ MSort (a + n1 + n2, n3, t + n1 + n2); }
		#pragma omp section
			{ MSort (a + n1 + n2 + n3, n4, t + n1 + n2 + n3); }
	}
	#pragma omp parallel sections 
	{
		#pragma omp section 
			{
			Merge (a, n1, a + n1, n2, t);
			memcpy(a, t, (n1 + n2)*sizeof(double));
			}
		#pragma omp section 
			{
			Merge (a + n1 + n2, n3, a + n1 + n2 + n3, n4, t + n1 +n2);
			memcpy(a + n1 + n2, t + n1 + n2, (n3 + n4)*sizeof(double));
			}
	}
	Merge (a, n1 + n2, a + n1 + n2, n3 + n4, t);
	memcpy(a, t, N*sizeof(double));
	delete[] t;
}

void CVector1::MSort1 () {
	int n1, n2, N = (int)n;
	if (N <= 1) return;
	n1 = N/2;
	n2 = N - n1;
	double *t = new double[N];
	MSort (a, n1, t);
	MSort (a + n1, n2, t);
	Merge (a, n1, a + n1, n2, t);
	memcpy(a, t, N*sizeof(int));
	delete[] t;

}

void CVector0::sum0 (CVector0 &A, CVector0 &B) {
	int n1, n2, n3, n4, N = int(n);
	n1 = N/2; n3 = N - n1;
	n2 = n1/2; n1 = n1 - n2;
	n4 = n3/2; n3 = n3 - n4;
	#pragma omp parallel sections 
	{
		#pragma omp section
		{
			for (int i = 0; i < n1; i++)
				this->a[i] = A.a[i] + B.a[i];
		}
		#pragma omp section
		{
			for (int i = n1; i < n1 + n2; i++)
				this->a[i] = A.a[i] + B.a[i];
		}
		#pragma omp section
		{
			for (int i = n1 + n2; i < n1 + n2 + n3; i++)
				this->a[i] = A.a[i] + B.a[i];
		}
		#pragma omp section
		{
			for (int i = n1 + n2 + n3; i < n1 + n2 + n3 + n4; i++)
				this->a[i] = A.a[i] + B.a[i];
		}
	}
	return;
}

void CVector1::sum1 (CVector1 &A, CVector1 &B) {
	for (int i = 0; i < n; i++)
		this->a[i] = A.a[i] + B.a[i];
	return;
}

/*
int count(const char *ch) {
    	FILE *f = fopen(ch, "r");
    	int n = 1;
    	char c, cc = '0';
    	while(!feof(f)){
    		fscanf(f, "%c", &c);
    		if (c == '\n') {
        		n++;
			fscanf(f, "%c", &cc);
		}
		if (cc != '1' && cc != '0') {
			n--;
			break;
		}
    	}
	fclose(f);
    	return n;
}
*/

int CVector::Input(string File, vector <CVector*> &arr, vector <CFabric*> &fabric){
	int s = 0;
	ifstream f(File); 
	string str, FileName;
	while(getline(f, str)) {
		stringstream ss (str);
		istream_iterator <double> it;
		it = ss;
		if (it != istream_iterator <double>()) {
			if (*it >= 0 && *it <= 1) {
				ss >> FileName;
				CVector *v = fabric[*it]->Create(FileName);
				++it;
				for (; it != istream_iterator<double>(); it++)
					v->Add(*it);
				arr.push_back(v);
				s++;
			}
		}
	}
	return s;
}

void CVector::Out (string FileName, vector <CVector*> &arr, vector <CFabric*> &fabric) {
	int k = Input(FileName, arr, fabric);
	for (int i = 0; i < k; i++) {
		ofstream f(arr[i]->f(), ios::trunc);
		f.close();		
	}

	for (int i = 0; i < k; i++)
		arr[i]->output(arr[i]->f());

}