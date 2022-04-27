#include<iostream>
#include<vector>
#include <ctime>

using namespace std;

void shellSort(vector<unsigned int> &);
void checkSort(vector<unsigned int> &);

int main() {
	vector<unsigned int> arr;
	int inputN[] = { 100000, 500000, 1000000, 5000000, 10000000 };
	
	for (int N = 0; N < 5; N++) {

		clock_t start, end;
		float res;

		for (int i = 0; i < inputN[N]; i++)
			arr.push_back(rand());
		
		start = clock();
		shellSort(arr);
		end = clock();

		cout << "증가식 : 5h + 1, ";
		cout << "감소식 : h / 5 ";
		cout << "정렬 실행시간(N = " << inputN[N] << "): ";
		res = (float)(end - start);
		cout << res << "ms\n";
		checkSort(arr);
		
		arr.clear();
	}
	return 0;
}

void shellSort(vector<unsigned int>& a) {
	int h;
	for (h = 1; h < a.size(); h = 5 * h + 1);
	for (; h > 0; h = h / 5) {
		for (unsigned int i = h + 1; i <= a.size(); i++) {
			unsigned int v = a[i - 1];
			unsigned int j = i;
			while (j > h && a[j - h - 1] > v) {
				a[j - 1] = a[j - h - 1];
				j = j - h;
			}
			a[j - 1] = v;
		}
	}
}

void checkSort(vector<unsigned int>& a) {
	int i, sorted;
	sorted = true;
	for (i = 0; i < a.size() - 1; i++) {
		if (a[i] > a[i + 1]) sorted = false;
		if (!sorted) break;
	}
	if (sorted) cout << "정렬완료." << endl;
	else cout << "정렬오류!" << endl;
}