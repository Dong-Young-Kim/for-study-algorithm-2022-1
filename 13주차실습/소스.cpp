#include <iostream>
#include <utility>
using namespace std;

//case 1
#define SACKWEIGH 15
#define NUMJEW 6
pair<int, int> WeiVal[NUMJEW + 1] = { {0,0},{5,5},{10,7},{7,10},{3,6},{4,8},{11,20} }; //index를 맞추기 위해 빈 공간 삽입

////case 2
//#define SACKWEIGH 30
//#define NUMJEW 8
//pair<int, int> WeiVal[NUMJEW + 1] = { {0,0},{3,5},{7,7},{8,10},{5,6},{6,8},{13,20},{11,18},{2,5} }; //index를 맞추기 위해 빈 공간 삽입


int KS[NUMJEW + 1][SACKWEIGH + 1]; //DP 통한 해결을 위한 배열을 생성


int knapsack() {

    for (int i = 0; i <= NUMJEW; i++) KS[i][0] = 0; //가방 무게가 0인 경우 어떠한 것도 들어갈 수 없음
    for (int j = 0; j <= SACKWEIGH; j++) KS[0][j] = 0; //가방에 어떠한 것도 들어가지 않는 경우

    for (int i = 1; i <= NUMJEW; i++) {
        for (int w = 1; w <= SACKWEIGH; w++) {
            if (WeiVal[i].first > w)
                KS[i][w] = KS[i - 1][w];
            else
                KS[i][w] = max((WeiVal[i].second + KS[i - 1][w - WeiVal[i].first]), KS[i - 1][w]);
        }
    }
    return KS[NUMJEW][SACKWEIGH];
}

int main() {
    cout << "가방에 담은 보석의 최대 가치: " << knapsack() << endl;
    return 0;
}