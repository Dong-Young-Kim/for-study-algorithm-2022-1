#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ROWSIZE 8
#define COLSIZE 9

int findRoute(int arr[ROWSIZE][COLSIZE])
{

    int sumarr[ROWSIZE][COLSIZE]; //sum을 기록할 array
    string strarr[ROWSIZE][COLSIZE]; //경로를 기록할 array

    // 첫번째 행인 경우 처리
    for (int j = 0; j < COLSIZE; j++) {
        sumarr[0][j] = arr[0][j];
        strarr[0][j] = to_string(arr[0][j]);
    }

    for (int i = 1; i < ROWSIZE; i++) {
        for (int j = 0; j < COLSIZE; j++) {

            int tmpMax; string tmpstr;

            if (j == 0) { //j가 첫 열인 경우
                if (sumarr[i - 1][j] > sumarr[i - 1][j + 1]) { tmpMax = sumarr[i - 1][j];     tmpstr = strarr[i - 1][j]; }
                else                                         { tmpMax = sumarr[i - 1][j + 1]; tmpstr = strarr[i - 1][j + 1]; }
            }
            else if (j == COLSIZE - 1) { //j가 끝 열인 경우
                if (sumarr[i - 1][j] > sumarr[i - 1][j - 1]) { tmpMax = sumarr[i - 1][j];     tmpstr = strarr[i - 1][j]; }
                else                                         { tmpMax = sumarr[i - 1][j - 1]; tmpstr = strarr[i - 1][j - 1]; }
            }
            else { //어느쪽 끝도 아닌 경우
                if (sumarr[i - 1][j + 1] > sumarr[i - 1][j - 1]) { tmpMax = sumarr[i - 1][j + 1]; tmpstr = strarr[i - 1][j + 1]; }
                else                                             { tmpMax = sumarr[i - 1][j - 1]; tmpstr = strarr[i - 1][j - 1]; }
                if (sumarr[i][j] >= tmpMax) { tmpMax = sumarr[i - 1][j]; tmpstr = strarr[i - 1][j]; }
            }

            sumarr[i][j] = tmpMax + arr[i][j];

            strarr[i][j] = tmpstr + " -> " + to_string(arr[i][j]); //배열 작성
        }
    }

    int maxCol = sumarr[ROWSIZE - 1][0], maxIdx = 0;
    for (int j = 1; j < COLSIZE; j++)
        if (maxCol < sumarr[ROWSIZE - 1][j]) {
            maxCol = sumarr[ROWSIZE - 1][j];
            maxIdx = j;
        }
    

    cout << "Maximum Sum of route = " << maxCol << endl;
    cout << "Route = " << strarr[ROWSIZE - 1][maxIdx] << endl;


    return 0;
}


int main() {
    int array[ROWSIZE][COLSIZE] = { {3, 4, 9, -2, 2, 51, -23, 2, -1},
                                    {223, 7, 8, -11, 5, -99, 2, 3, -4},
                                    {2, 51, -23, -23, 6, 3, 2, 4, 5},
                                    {5, -99, 2, -1, 32, 2, 5, -99, 2},
                                    {6, 3, 3, -4, 2, -1, 6, 3, 3},
                                    {32, 2, 4, 5, 3, -4, 2, -1, 4},
                                    {4, 4, 23, 6, 2, -1, 3, -4, 34},
                                    {78, 32, 1, 7, 3, -4, -23, -23, 6} };
    findRoute(array);
    return 0;
}