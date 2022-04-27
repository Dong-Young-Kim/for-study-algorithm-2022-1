#include<iostream>
#include<vector>
#include <ctime>

using namespace std;

void printArray(vector<unsigned int>&);
void oddEvenSort(vector<unsigned int>&);
void checkSort(vector<unsigned int>&);

void smallN() {
	vector<unsigned int> arr1{ 2, 10, 5, 3, 7, 9, 4, 10 };
	vector<unsigned int> arr2{ 2, 1, 5, 3, 7, 9, 4, 10 };
	vector<unsigned int> arr3{ 4, 13, 2, 5, 6, 70, 8, 3, 10, 11, 24, 23, 21, 7, 9 ,12 };

	oddEvenSort(arr1);
	oddEvenSort(arr2);
	oddEvenSort(arr3);

}

void largeN() {
	vector<unsigned int> arr;
	int inputN[] = { 10000, 50000, 100000 };

	for (int N = 0; N < 3; N++) {

		clock_t start, end;
		float res;

		for (int i = 0; i < inputN[N]; i++)
			arr.push_back(rand() % 1000);

		start = clock();
		oddEvenSort(arr);
		end = clock();

		cout << "정렬 실행시간(N = " << inputN[N] << "): ";
		res = (float)(end - start);
		cout << res << "ms\t";
		checkSort(arr);

		arr.clear();
	}
}

int main() {

	largeN();
	return 0;
}


void oddEvenSort(vector<unsigned int>& a){
	bool sorted = false;

	for(int k = 0; k < a.size(); k += 2)  {
		// odd index
		for (int i = 0; i < a.size() - 1; i = i + 2)
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		//cout << "odd Index" << endl;
		//printArray(a);

		// even index

		for (int i = 1; i < a.size() - 1; i = i + 2)
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		//cout << "even Index" << endl;
		//printArray(a);
	}
	//cout << "\n최종 졍렬 결과" << endl;
	//printArray(a);
	//cout << endl;
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

void printArray(vector<unsigned int>& a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}