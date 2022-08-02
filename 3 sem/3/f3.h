#include <iostream>
#include <stdlib.h>
using namespace std;


class BitSet {
	int first;
	int last;
	bool* set;
public:
	class iterator {
	public:
		BitSet* s;
		int p;
		iterator(BitSet* s, int p) {
			this->s = s;
			this->p = p;
		}
		iterator &operator=(const iterator& c) {
			this->s = c.s;
			this->p = p;
			return *this;
		}
		int operator!=(const iterator& c) {
			return this->p != c.p;
		}
		int operator==(const iterator& c) {
                        return this->p == c.p;
                }
		void operator++() {
			++p;
			while (s->set[p] == 0) {
				if (p + s->first == s->last)
					break;
			else ++p;
			}
		}
		int operator*() {
			return ((s->first) + p);
		}
	};
	iterator begin() {
		return iterator(this, this->Min() - first);
	}
        iterator end() {
		return iterator(this, last - first);
	}

	BitSet (int first, int last);
	BitSet (int first, int last, bool *b);
	~BitSet ();
	void Zero ();
	void NewEl (int value);
	void DeleteEl (int value);
	bool Check (int value);
	int Max ();
	int Min ();
	int getFirst ();
        int getLast ();
	//friend BitSet& operator|(BitSet &f, BitSet &e);
	//BitSet& operator&(BitSet &c);
	void Change (int f, int l);
	BitSet& operator=(BitSet &c);
	void print ();
	BitSet& un (BitSet &f, BitSet &e);
	BitSet& cr (BitSet &f, BitSet &e);
};

