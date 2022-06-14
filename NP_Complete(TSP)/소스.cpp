#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

#define INF std::numeric_limits<int>::max() / 10

#define NUMVERTEX 5
using namespace std;

//����ġ�� �����ϱ� ���� �迭 
//int W[NUMVERTEX][NUMVERTEX] = { { 0, 10, 15, 20 },
//                                   { 10, 0, 35, 25 },
//                                   { 15, 35, 0, 30 },
//                                   { 20, 25, 30, 0 } };

const int W[NUMVERTEX][NUMVERTEX] = { {0, 1, INF, 1, 5},
                                  {9, 0, 3, 2, INF},
                                  {INF, INF, 0, 4, INF},
                                  {INF, INF, 2, 0, 3},
                                  {3, INF, INF, INF, 0} };

int TSP(vector<int> path, vector<bool> visited, int len) {
    //��� ���� �� �湮���� ��� 
    if (path.size() == NUMVERTEX) return len + W[path.back()][0];
    int ret = 987654321;

    for (int next = 0; next < NUMVERTEX; next++) {
        //�湮 �ߴٸ� �н� 
        if (visited[next] == true) continue;

        int cur = path.back();
        path.push_back(next);
        visited[next] = true;
        ret = min(ret, TSP(path, visited, len + W[cur][next]));
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}
int main() {

    clock_t start, end;
    float res;
    
    start = clock();

    vector<int> path(1, 0); // ��θ� ������ ����, ���� ���� 0������ ����. 
    vector<bool> visited(NUMVERTEX, false); // �湮 ���θ� ������ ����. false�� �ʱ�ȭ. 
    visited[0] = true; // ��� ���� �湮���� üũ.
    double ret = TSP(path, visited, 0);
    cout << ret << endl;
    end = clock();


    cout << "����ð�: ";
    //cout << "���� ����ð�(N = " << inputN[N] << "): ";
    res = (float)(end - start);
    cout << res << "ms\t";
}