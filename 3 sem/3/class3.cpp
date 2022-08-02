#include "f3.h"
#include <stdlib.h>
BitSet::BitSet (int first, int last) {
	this->first = first;
	this->last = last;
	set = new bool [last - first + 1];
	for (int i = 0; i <= last - first; i++)
		set[i] = 0;
}

BitSet::BitSet (int first, int last, bool *b) {
	this->first = first;
	this->last = last;
	set = new bool [last - first + 1];
	for (int i = 0; i <= last - first; i++)
		set[i] = b[i];
}

BitSet::~BitSet () {
	delete [] set;
}

void BitSet::Zero () {
	 for (int i = 0; i <= last - first; i++)
                set[i] = 0;
}
void BitSet::NewEl (int value) {
	if (value >= first && value <= last)
		set [value - first] = true;
	else
		cout << "Error: this value is out of range\n";
}

void BitSet::DeleteEl (int value) {
	if (value >= first && value <= last)
		set [value - first] = false;
	else
                cout << "Error: this value is out of range\n";
}

bool BitSet::Check (int value) {
        if (value >= first && value <= last)
                return set[value - first];
        else
                cout << "Error: this value is out of range\n";
	return 0;
}

int BitSet::Max () {
	int k = 0;
	for (int i = 0; i <= last - first; i++)
		if (set[i] == 0) k++;
	if (k == last - first + 1)
		cout << "error: set is empty";
	else {
		int i = last - first;
		while (set [i] != true)
			i--;
		return i + first;
	}
	return -1;
}

int BitSet::Min () {
	int k = 0;
	for (int i = 0; i <= last - first; i++)
		if (set[i] == 0) k++;
	if (k == last - first + 1)
		cout << "error: set is empty";
	else {
		int i = 0;
        	while (set [i] != true)
               		i++;
        	return i + first;
	}
	return -1;
}

int BitSet::getFirst () {
        return first;
}

int BitSet::getLast () {
        return last;
}

BitSet& BitSet::un (BitSet &f, BitSet &e) {
	int ff = f.first;
	int fl = f.last;
	int ef = e.first;
	int el = e.last;
	if((f.first != e.first) || (f.last != e.last)) {
		f.Change(min(f.first, e.first), max(f.last, e.last));
		e.Change(f.first, f.last);
		this->Change(f.first, f.last);
	}
	for (int i = 0; i <= e.last - e.first; i++)
		this->set[i] = f.set[i] | e.set[i];
	f.Change(ff, fl);
	e.Change(ef, el);
	return *this;
}

BitSet& BitSet::cr (BitSet &f, BitSet &e) {
	BitSet c(f.first, f.last, f.set);
	BitSet h(e.first, e.last, e.set);
	if((c.first != h.first) || (c.last != h.last)) {
		c.Change(max(c.first, h.first), min(c.last, h.last));
		h.Change(c.first, c.last);
		this->Change(c.first, c.last);
	}
	for (int i = 0; i <= c.last - c.first; i++)
		this->set[i] = c.set[i] & h.set[i];
	return *this;
}

/*BitSet& operator|(BitSet &f, BitSet &e) {
	if((f.first != e.first) || (f.last != e.last)) {
		f.Change(min(f.first, e.first), max(f.last, e.last));
		e.Change(f.first, f.last);
	}
	return BitSet::un(e, f);
}*/

/*BitSet& BitSet::operator&(BitSet &c) {
	if((this->first != c.first) || (this->last != c.last)) {
		this->Change(max(this->first, c.first), min(this->last, c.last));
		c.Change(this->first, this->last);
	}
	for (int i = 0; i <= c.last - c.first; i++)
		c.set[i] = this->set[i] & c.set[i];
	return *(new BitSet(c.first, c.last, c.set));
}*/

void BitSet::Change (int f, int l) {
	bool *s = new bool[l - f + 1];
	for (int i = 0; i <= l - f; i++)
                s[i] = 0;
	for (int i = 0; i <= l - f; i++) {
		if (i + f >= first)
			s[i] = set[i + f - first];
	}
	delete [] set;
	set = new bool[l - f + 1];
	for (int i=0; i <= l - f; i++) 
		set[i] = s[i];
	if (last < l)
		for (int i = last - first; i <= l - f; i++)
			set[i] = 0;
	first = f;
	last = l;
	delete [] s;
}
BitSet& BitSet::operator=(BitSet &c) {
	if((this->first != c.first) || (this->last != c.last)) {
		this->Change(min(this->first, c.first), max(this->last, c.last));
		c.Change(this->first, this->last);
	}
	for (int i = 0; i <= this->last - this->first; i++)
		this->set[i] = c.set[i];
	return (*this);
}

void BitSet::print () {
	for (int i = 0; i <= last - first; i++)
		printf("%d ", set[i]);
	cout << "\n";
}
