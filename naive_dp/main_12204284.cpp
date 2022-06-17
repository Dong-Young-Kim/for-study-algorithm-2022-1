#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

#define INF std::numeric_limits<int>::max() / 10 //무한대 표현, 오버플로우 방지
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

int naiveTSP(vector<int> path, vector<bool> visited, int len) { //재귀를 통한 구현
    if (path.size() == NUMVERTEX) return len + W[path.back()][0]; //모든 도시 다 방문했을 경우 
    int res = INF; //결과값 초기화

    for (int next = 0; next < NUMVERTEX; next++) {//0번 노드부터 시작해 탐색
        if (visited[next] == true) continue; //이미 방문한 vertex

        int cur = path[path.size() - 1]; //탐색 노드를 저장하는 경로의 마지막 노드(새로 결과값을 생성할 위치)
        path.push_back(next);
        visited[next] = true; //새로운 노드를 경로에 입력하고 방문처레
        res = min(res, naiveTSP(path, visited, len + W[cur][next])); //재귀함수 호출로 해당 경로가 이전보다 더 작은 경로인지 판단
        visited[next] = false;
        path.pop_back(); //노드 방문기록 초기화
    }
    return res;
}

void naive() {
    clock_t start, end;
    float res;

    start = clock();

    vector<int> path; //탐색하는 경로를 저장하는 배열
    path.push_back(0); //시작 도시 0번도시 선택. 

    vector<bool> visited(NUMVERTEX, false); // 방문 여부를 저장할 벡터. false로 초기화.
    visited[0] = true; // 출발 도시 방문여부 체크.

    res = naiveTSP(path, visited, 0);
    cout << res << endl;
    end = clock();

    double timeRes;
    cout << "실행시간: ";
    timeRes = (float)(end - start);
    cout << timeRes << "ms\n";
}

int DPtsp(const int s) {
    vector<vector<int>> dp(2 << (NUMVERTEX - 1), vector<int>(NUMVERTEX, INF));
    dp[1][0] = 0;
    for (int s = 2; s <= NUMVERTEX; s++) {
        vector<bool> S(NUMVERTEX - s, false);
        S.insert(S.end(), s - 1, true); //노드 조합을 사용할 부분 집합 생성 true 표시노드 이용
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
        } while (next_permutation(S.begin(), S.end())); //https://notepad96.tistory.com/38 조합 코드 참고
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
    cout << "실행시간: ";
    timeRes = (float)(end - start);
    cout << timeRes << "ms\n";
}

int main() {
    cout << "12204284 김동영\n";
    naive();
    dp();
    return 0;
}