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
    int v = a[h]; //heapify ��� ��� ��
    int j;
    for (j = h * 2; j <= m; j *= 2) { //�ڽ� ��� ����, �ڽ� ��尡 �� ���� ������ ��� ����
        if (j < m && a[j] < a[j + 1]) j++; //������ �ڽ� ��尡 ũ�� ������ �ڽ� ���� ����
        if (v >= a[j]) break; //���� ��尡 �ڽ� ��� ���� ũ�ų� ������ exit
        else a[j / 2] = a[j]; // �ڽ� ������ �θ� ���� �̵�
    }
    a[j / 2] = v; // v�� ���� �ڽ� ��忡 ����
}
void max_HeapSort(vector<unsigned int>& a) {
    int n = a.size() - 1;
    for (int i = n / 2; i >= 1; i--) { //��� ���� ���
        max_heapify(a, i, n); //���� ��忡 ���ؼ� heapify
        //i = healify ���, n = �� ũ��
    }

    for (int i = n; i >= 1; i--) {
        swap(a[1], a[i]); //������ ���ҿ� ��Ʈ swap
        max_heapify(a, 1, i - 1); // ������ ��带 �����ϰ� heapify
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
    if (sorted) cout << "���ĿϷ�.";
    else cout << "���Ŀ���!";
}

void min_checkSort(vector<unsigned int>& a) {
    int i, sorted;
    sorted = true;
    for (i = 1; i < a.size() - 1; i++) {
        if (a[i] < a[i + 1]) sorted = false;
        if (!sorted) break;
    }
    if (sorted) cout << "���ĿϷ�.";
    else cout << "���Ŀ���!";
}

void smallN() {
    //0 index�� ������� �����Ƿ� 0�� ����
	vector<unsigned int> arr1{0, 6, 2, 8, 1, 3, 9, 4, 5, 10, 7 };
	
	max_HeapSort(arr1);
    printf("MaxHeap ���� ���\n");
	printArray(arr1);

    min_HeapSort(arr1);
    printf("MinHeap ���� ���\n");
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
        cout << "���� ����ð�(N = " << inputN[N] << "): ";
        res = (float)(end - start);
        cout << res << "ms\n";


        start = clock();
        min_HeapSort(arr);
        end = clock();

        cout << "Minheap ";
        min_checkSort(arr);
        cout << "���� ����ð�(N = " << inputN[N] << "): ";
        res = (float)(end - start);
        cout << res << "ms\n";
        

        arr.clear();
    }
}

int main() {
	smallN();

	return 0;
}
