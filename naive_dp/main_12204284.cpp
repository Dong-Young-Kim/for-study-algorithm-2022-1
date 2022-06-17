#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

#define INF std::numeric_limits<int>::max() / 10 //���Ѵ� ǥ��, �����÷ο� ����
#define NUMVERTEX 10

const int W[NUMVERTEX][NUMVERTEX] = { {0, 1, INF, 1, 5, INF, INF, INF, INF, 3},
                                      {9, 0, 3, 2, INF, INF, INF, 4, INF, 3},
                                      {INF, INF, 0, 4, INF, 3, INF, INF, INF, INF},
                                      {INF, INF, 2, 0, 3, INF, INF, INF, 4, INF},
                                      {3, INF, INF, INF, 0, INF, 2, 6, 3, INF},
                                      {9, 9, 3, 2, INF, 0, INF, 4, INF, 3} ,
                                      {6, 4, 3, 2, INF, INF, 0, 4, INF, 3} ,
                                      {2, 1, 3, 2, INF, INF, INF, 0, INF, 3} ,
                                      {3, INF, 3, 2, 9, 3, 2, 4, 0, 3} ,
                                      {INF, INF, INF, 2, INF, INF, INF, 4, INF, 0} };

int naiveTSP(vector<int> path, vector<bool> visited, int len) { //��͸� ���� ����
    if (path.size() == NUMVERTEX) return len + W[path.back()][0]; //��� ���� �� �湮���� ��� 
    int res = INF; //����� �ʱ�ȭ

    for (int next = 0; next < NUMVERTEX; next++) {//0�� ������ ������ Ž��
        if (visited[next] == true) continue; //�̹� �湮�� vertex

        int cur = path[path.size() - 1]; //Ž�� ��带 �����ϴ� ����� ������ ���(���� ������� ������ ��ġ)
        path.push_back(next);
        visited[next] = true; //���ο� ��带 ��ο� �Է��ϰ� �湮ó��
        res = min(res, naiveTSP(path, visited, len + W[cur][next])); //����Լ� ȣ��� �ش� ��ΰ� �������� �� ���� ������� �Ǵ�
        visited[next] = false;
        path.pop_back(); //��� �湮��� �ʱ�ȭ
    }
    return res;
}

void naive() {
    clock_t start, end;
    float res;

    start = clock();

    vector<int> path; //Ž���ϴ� ��θ� �����ϴ� �迭
    path.push_back(0); //���� ���� 0������ ����. 

    vector<bool> visited(NUMVERTEX, false); // �湮 ���θ� ������ ����. false�� �ʱ�ȭ.
    visited[0] = true; // ��� ���� �湮���� üũ.

    res = naiveTSP(path, visited, 0);
    cout << res << endl;
    end = clock();

    double timeRes;
    cout << "����ð�: ";
    timeRes = (float)(end - start);
    cout << timeRes << "ms\n";
}

int DPtsp(const int s) {
    vector<vector<int>> dp(2 << (NUMVERTEX - 1), vector<int>(NUMVERTEX, INF));
    dp[1][0] = 0;
    for (int s = 2; s <= NUMVERTEX; s++) {
        vector<bool> S(NUMVERTEX - s, false);
        S.insert(S.end(), s - 1, true); //��� ������ ����� �κ� ���� ���� true ǥ�ó�� �̿�
        do {
            int subset = 1;
            for (int i = 0; i < NUMVERTEX - 1; i++) {
                if (S[i]) subset |= (1 << (i + 1)); 
            }
            for (int j = 0; j < NUMVERTEX - 1; j++) {
                if (!S[j]) continue;

                for (int i = -1; i < NUMVERTEX - 1; i++) {
                    if (i == -1 || (S[i] && i != j)) {
                        if (W[i + 1][j + 1] != 0)
                            dp[subset][j + 1] = min(dp[subset][j + 1], dp[subset - (1 << (j + 1))][i + 1] + W[i + 1][j + 1]);
                    }
                }
            }
        } while (next_permutation(S.begin(), S.end())); //https://notepad96.tistory.com/38 ���� �ڵ� ����
    }
    int subset = (1 << NUMVERTEX) - 1;
    int res = INF;
    for (int j = 0; j < NUMVERTEX; j++) {
        if (W[j][s] != 0)
            res = min(res, dp[subset][j] + W[j][s]);
    }
    return res;
}

void dp() {
    clock_t start, end;
    float res;

    start = clock();

    cout << DPtsp(0) << "\n";

    end = clock();

    double timeRes;
    cout << "����ð�: ";
    timeRes = (float)(end - start);
    cout << timeRes << "ms\n";
}

int main() {
    cout << "12204284 �赿��\n";
    naive();
    dp();
    return 0;
}