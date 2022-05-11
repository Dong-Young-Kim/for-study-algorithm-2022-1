#include <iostream>
using namespace std;

#define ROWSIZE 9
#define COLSIZE 9

#define CHE 1
#define non -1
#define TRP 2

inline int CHEorTRP(int n) {
    switch (n){
    case 1: //치즈인 경우
        return 1;
    case 2: //트랩인 경우
        return numeric_limits<int>::lowest();
    default: //빈 공간인 경우
        return 0;
    }
}

int findMaxCheese(int arr[ROWSIZE][COLSIZE]) {    
    int sumarr[ROWSIZE][COLSIZE]; //sum을 기록할 array
    for (int i = ROWSIZE - 1; i >= 0; i--) {
        for (int j = 0; j < COLSIZE; j++) {
            //base case 처리
            if (i == ROWSIZE - 1 && j == 0) sumarr[i][j] = 0;
            else if (i == ROWSIZE - 1) sumarr[i][j] = sumarr[i][j - 1] + CHEorTRP(arr[i][j]);
            else if (j == 0) sumarr[i][j] = sumarr[i][j] = sumarr[i + 1][j] + CHEorTRP(arr[i][j]);
            //recursive property
            else sumarr[i][j] = max(sumarr[i][j - 1], sumarr[i + 1][j]) + CHEorTRP(arr[i][j]);
        }
    }
    return sumarr[0][COLSIZE - 1]; //최종 결과 반환
}

int main() {
    int array[ROWSIZE][COLSIZE] = { {non,non,CHE,non,non,non,non,non,non},
                                    {non,non,non,non,non,CHE,non,TRP,non},
                                    {CHE,non,TRP,non,non,non,non,CHE,non},
                                    {non,non,non,non,CHE,TRP,non,non,non},
                                    {non,CHE,non,CHE,non,non,non,non,non},
                                    {non,non,non,non,non,TRP,CHE,TRP,non},
                                    {non,CHE,non,non,CHE,non,non,non,non},
                                    {non,non,non,non,non,CHE,non,non,non},
                                    {non,non,non,non,non,non,non,non,non} };

    cout << "max cheese " << findMaxCheese(array) << endl;
    return 0;
}