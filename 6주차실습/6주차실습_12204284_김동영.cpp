#include<iostream>
#include<vector>
#include <ctime>

using namespace std;


//void max_heapify(vector<unsigned int>& a, int r, int n) {
//    int tmp = a[r];
//    int c = r * 2;
//    while (c <= n) {
//        
//        if (c < n && a[c] < a[c + 1])
//            c++;
//        if (tmp < a[c]) {
//            a[c / 2] = a[c];
//            c *= 2;
//        }
//        else break;
//    }
//    a[c / 2] = tmp;
//
//}
void max_heapify(vector<unsigned int>& a, int h, int m) {
    int v = a[h]; //heapify 대상 노드 값
    int j;
    for (j = h * 2; j <= m; j *= 2) { //자식 노드 접근, 자식 노드가 힙 범위 내부일 경우 동작
        if (j < m && a[j] < a[j + 1]) j++; //오른쪽 자식 노드가 크면 오른쪽 자식 노드로 변경
        if (v >= a[j]) break; //현재 노드가 자식 노드 보다 크거나 같으면 exit
        else a[j / 2] = a[j]; // 자식 도느들 부모 노드로 이동
    }
    a[j / 2] = v; // v를 최종 자식 노드에 대입
}
void max_HeapSort(vector<unsigned int>& a) {
    int n = a.size() - 1;
    for (int i = n / 2; i >= 1; i--) { //모든 내부 노드
        max_heapify(a, i, n); //내부 노드에 대해서 heapify
        //i = healify 대상, n = 힙 크기
    }

    for (int i = n; i >= 1; i--) {
        swap(a[1], a[i]); //마지막 원소와 루트 swap
        max_heapify(a, 1, i - 1); // 마지막 노드를 제외하고 heapify
    }
}

//void min_heapify(vector<unsigned int>& a, int r, int n) {
//    int tmp = a[r];
//    int c = r * 2;
//    while (c <= n) {
//
//        if (c < n && a[c] > a[c + 1])
//            c++;
//        if (tmp > a[c]) {
//            a[c / 2] = a[c];
//            c *= 2;
//        }
//        else break;
//    }
//    a[c / 2] = tmp;
//
//}

void min_heapify(vector<unsigned int>& a, int h, int m) {
    int v = a[h];
    int j;
    for (j = h * 2; j <= m; j *= 2) {
        if (j < m && a[j] > a[j + 1]) j++;
        if (v <= a[j]) break;
        else a[j / 2] = a[j];
    }
    a[j / 2] = v;
}
void min_HeapSort(vector<unsigned int>& a) {
    int n = a.size() - 1;
    for (int i = n / 2; i >= 1; i--) {
        min_heapify(a, i, n);
    }

    for (int i = n; i >= 1; i--) {
        swap(a[1], a[i]);
        min_heapify(a, 1, i - 1);
    }
}

void printArray(vector<unsigned int>& a) {
	for (int i = 1; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

void max_checkSort(vector<unsigned int>& a) {
    int i, sorted;
    sorted = true;
    for (i = 1; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) sorted = false;
        if (!sorted) break;
    }
    if (sorted) cout << "정렬완료.";
    else cout << "정렬오류!";
}

void min_checkSort(vector<unsigned int>& a) {
    int i, sorted;
    sorted = true;
    for (i = 1; i < a.size() - 1; i++) {
        if (a[i] < a[i + 1]) sorted = false;
        if (!sorted) break;
    }
    if (sorted) cout << "정렬완료.";
    else cout << "정렬오류!";
}

void smallN() {
    //0 index는 사용하지 않으므로 0을 배정
	vector<unsigned int> arr1{0, 6, 2, 8, 1, 3, 9, 4, 5, 10, 7 };
	
	max_HeapSort(arr1);
    printf("MaxHeap 정렬 결과\n");
	printArray(arr1);

    min_HeapSort(arr1);
    printf("MinHeap 정렬 결과\n");
    printArray(arr1);
}

void largeN() {
    vector<unsigned int> arr;
    int inputN[] = { 10000, 50000, 100000, 500000, 1000000 };

    for (int N = 0; N < 5; N++) {

        clock_t start, end;
        float res;

        for (int i = 0; i < inputN[N]; i++)
            arr.push_back(rand() % 1000);

        start = clock();
        max_HeapSort(arr);
        end = clock();

        cout << "Maxheap ";
        max_checkSort(arr);
        cout << "정렬 실행시간(N = " << inputN[N] << "): ";
        res = (float)(end - start);
        cout << res << "ms\n";


        start = clock();
        min_HeapSort(arr);
        end = clock();

        cout << "Minheap ";
        min_checkSort(arr);
        cout << "정렬 실행시간(N = " << inputN[N] << "): ";
        res = (float)(end - start);
        cout << res << "ms\n";
        

        arr.clear();
    }
}

int main() {
	smallN();

	return 0;
}
