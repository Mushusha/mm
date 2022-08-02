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