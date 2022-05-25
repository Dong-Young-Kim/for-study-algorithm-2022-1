#include <iostream>
#include <utility>
using namespace std;

//case 1
#define SACKWEIGH 15
#define NUMJEW 6
pair<int, int> WeiVal[NUMJEW + 1] = { {0,0},{5,5},{10,7},{7,10},{3,6},{4,8},{11,20} }; //index�� ���߱� ���� �� ���� ����

////case 2
//#define SACKWEIGH 30
//#define NUMJEW 8
//pair<int, int> WeiVal[NUMJEW + 1] = { {0,0},{3,5},{7,7},{8,10},{5,6},{6,8},{13,20},{11,18},{2,5} }; //index�� ���߱� ���� �� ���� ����


int KS[NUMJEW + 1][SACKWEIGH + 1]; //DP ���� �ذ��� ���� �迭�� ����


int knapsack() {

    for (int i = 0; i <= NUMJEW; i++) KS[i][0] = 0; //���� ���԰� 0�� ��� ��� �͵� �� �� ����
    for (int j = 0; j <= SACKWEIGH; j++) KS[0][j] = 0; //���濡 ��� �͵� ���� �ʴ� ���

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
    cout << "���濡 ���� ������ �ִ� ��ġ: " << knapsack() << endl;
    return 0;
}