#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> initNext(string& p) {
	int M = p.length();
	vector<int> next(M); //크기 M으로 vector 초기화
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
	if (j == M) return i - M; //pattern을 찾음
	else return i;//pattern을 찾지 못함
}

void Ex1() {
	string text("ababababcababababcaabbabababcaab");
	string pattern("abababca");

	int i = 0;
	while (1) {
		int loc = KMP(pattern, text, i);
		if (loc < text.length()) {
			cout << "패턴이 발생한 위치: " << loc << endl; //결과 출력
			i++; //패턴을 찾은 이후부터 다시 탐색
		}
		else {
			cout << "탐색종료" << endl;
			break; //i가 패턴길이보다 짧을 때만 동작
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
			cout << "패턴이 발생한 위치: " << loc << endl; //결과 출력
			i++; //패턴을 찾은 이후부터 다시 탐색
		}
		else {
			cout << "탐색종료" << endl;
			break; //i가 패턴길이보다 짧을 때만 동작
		}
	}
}

int main() {
	//Ex1();
	Ex2();	
	return 0;
}