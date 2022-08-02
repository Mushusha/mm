#include <iostream>
#define N 3

struct BNode {
    int key[2*N];
    BNode *son[2*N+1];	
    BNode *parent;
    int ckey;
    int cson;
    bool leaf;
};

class Btree {
	BNode *root;
public:
	Btree();
	~Btree();
	void insert (int k);
	bool search (int k);
	void remove (int k);
	int amount ();
	//iterator
}
