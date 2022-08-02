#include "f3.h"

int main () {
	BitSet a (12, 32);
	BitSet b (13, 31);
	BitSet d (13, 31);

	cout << "Filling a\n";
	a.NewEl(23);
	a.NewEl(16);
	a.NewEl(18);
	a.NewEl(26);
	a.NewEl(31);
	cout << "value all range:\n";
	a.NewEl(68);
	a.print();
	cout << "max value: " << a.Max() << endl;
	cout << "min value: " << a.Min() << endl;
	cout << "first value: " << a.getFirst() << endl;
	cout << "last value: " <<a.getLast() << endl;

	cout << "Filling b\n";
	b.NewEl(13);
	b.NewEl(16);
	b.NewEl(19);
	b.NewEl(24);
	b.NewEl(26);
	b.NewEl(28);
	b.NewEl(31);
	b.print();
	cout << "delete value 31:\n";
	b.DeleteEl(31);
	b.print();

	cout << "Check 23 in a: ";
	cout << a.Check(23) << endl;
	cout << "Check 22 in a: ";
	cout << a.Check(22) << endl;

	cout << "union a and b:\n";
//	d = a | b;
	d.un(a, b);
	d.print();
	cout << "a and b before cross:\n";
	a.print();
	b.print();
	cout << "cross a and b:\n";
//	d = a & b;
	d.cr(a, b);
	d.print();
	cout << "a and b after cross:\n";
	a.print();
	b.print(); 	
	cout << "Change range:\n";
	d.Change(12, 36);
	d.print();

	cout << "iterator: ";
	for(BitSet::iterator it = d.begin(); it != d.end(); ++it)
		cout<< *it << " ";
	cout << endl;
	return 0;
}
