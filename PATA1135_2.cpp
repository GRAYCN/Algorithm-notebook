//PATA1135_2
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
enum Type {RED, BLK};

struct RBNode{
	int val;
	RBNode *l, *r;
	Type type;
	RBNode(int v){
		l=r=NULL;
		type=v<0? RED: BLK;
		val = abs(v);
	}
};

int main(){
	
}
