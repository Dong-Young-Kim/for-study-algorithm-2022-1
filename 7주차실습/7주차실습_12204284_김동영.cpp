#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> initNext(string& p) {
	int M = p.length();
	vector<int> next(M); //ũ�� M���� vector �ʱ�ȭ
	next[0] = -1;
	for (int i = 0, j = -1; i < M; i++, j++) {
		next[i] = j;
		while ((j >= 0) && p[i] != p[j])
			j = next[j];
	}
	return next;
}

int KMP(string& p, string& t, int& i) {
	int M = p.length(), N = t.length();
	vector<int> next = initNext(p);
	int j;
	for (i, j = 0; j < M && i < N; i++, j++) {
		while ((j >= 0) && t[i] != p[j])
			j = next[j];
	}
	if (j == M) return i - M; //pattern�� ã��
	else return i;//pattern�� ã�� ����
}

void Ex1() {
	string text("ababababcababababcaabbabababcaab");
	string pattern("abababca");

	int i = 0;
	while (1) {
		int loc = KMP(pattern, text, i);
		if (loc < text.length()) {
			cout << "������ �߻��� ��ġ: " << loc << endl; //��� ���
			i++; //������ ã�� ���ĺ��� �ٽ� Ž��
		}
		else {
			cout << "Ž������" << endl;
			break; //i�� ���ϱ��̺��� ª�� ���� ����
		}
	}
}

void Ex2() {
	string text("This class is an algorithm design class. Therefore, students will have time to learn about	algorithms and implement each algorithm themselves.");
	string pattern("algorithm");

	int i = 0;
	while (1) { 
		int loc = KMP(pattern, text, i);
		if (loc < text.length()) {
			cout << "������ �߻��� ��ġ: " << loc << endl; //��� ���
			i++; //������ ã�� ���ĺ��� �ٽ� Ž��
		}
		else {
			cout << "Ž������" << endl;
			break; //i�� ���ϱ��̺��� ª�� ���� ����
		}
	}
}

int main() {
	//Ex1();
	Ex2();	
	return 0;
}