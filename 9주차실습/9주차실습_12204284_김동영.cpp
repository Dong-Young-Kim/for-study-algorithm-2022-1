#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct nodetype {
	nodetype(string sym, int freq) : symbol(sym), frequency(freq){}
	string symbol;
	int frequency;
	nodetype* left = nullptr;
	nodetype* right = nullptr;
};

// pq 내부 정렬을 위한 연산자 오버로딩
struct comp {
	bool operator()(nodetype* a, nodetype* b){
		return a->frequency > b->frequency;
	}
};


void printPreorder(struct nodetype* node, string tmp)
{
	if (node->symbol.size() != 0) {
		cout << node->symbol << " " << tmp << endl;
		return;
	}
	printPreorder(node->left, tmp + "0");

	printPreorder(node->right, tmp + "1");
}


void ex1() {
	vector<nodetype> str_arr = { nodetype("r",27), nodetype("A",15), nodetype("B",12), nodetype("C",9),
							 nodetype("D",5), nodetype("E",10), nodetype("F",11) };

	//PQ에 값을 넣음
	priority_queue<nodetype*, vector<nodetype*>, comp> PQ;
	for (int i = 0; i < str_arr.size(); i++)
		PQ.push(&str_arr[i]);

	nodetype* r;


	while (PQ.size() > 1) {
		nodetype *p = PQ.top(); PQ.pop();
		nodetype *q = PQ.top(); PQ.pop();

		r = new nodetype("", p->frequency + q->frequency);
		r->left = p;
		r->right = q;

		PQ.push(r);
	}

	printPreorder(PQ.top(), "");
}

void ex2() {
		vector<nodetype> str_arr = { nodetype("ROOT", 27), nodetype("ABC", 12), nodetype("ABCC", 7), nodetype("AB", 19),
							  nodetype("A", 35), nodetype("B", 40), nodetype("BABA", 15) };

	//PQ에 값을 넣음
	priority_queue<nodetype*, vector<nodetype*>, comp> PQ;
	for (int i = 0; i < str_arr.size(); i++)
		PQ.push(&str_arr[i]);

	nodetype* r;


	while (PQ.size() > 1) {
		nodetype* p = PQ.top(); PQ.pop();
		nodetype* q = PQ.top(); PQ.pop();

		r = new nodetype("", p->frequency + q->frequency);
		r->left = p;
		r->right = q;

		PQ.push(r);
	}

	printPreorder(PQ.top(), "");
}


int main() {
	ex1();
	cout << endl;
	ex2();
}