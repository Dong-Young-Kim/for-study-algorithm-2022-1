//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//#define ROWSIZE 9
//#define COLSIZE 9
//
//#define CHE 1
//#define non 0
//#define TRP -9999
//
//
//int calMaxCheese(int arr[ROWSIZE][COLSIZE], int n, int m) {
//
//    if (n == 0 && m == 0) return 0;
//    else if (n == ROWSIZE - 1) return calMaxCheese(arr, n, m - 1)+ arr[n][m];
//    else if (m == 0) return calMaxCheese(arr, n + 1, m) + arr[n][m];
//
//    else return max(calMaxCheese(arr, n, m - 1), calMaxCheese(arr, n + 1, m)) + arr[n][m];
//}
//
//
//int main() {
//    int array[ROWSIZE][COLSIZE] = { {non,non,CHE,non,non,non,non,non,non},
//                                    {non,non,non,non,non,CHE,non,TRP,non},
//                                    {CHE,non,TRP,non,non,non,non,CHE,non},
//                                    {non,non,non,non,CHE,TRP,non,non,non},
//                                    {non,CHE,non,CHE,non,non,non,non,non},
//                                    {non,non,non,non,non,TRP,CHE,TRP,non},
//                                    {non,CHE,non,non,CHE,non,non,non,non},
//                                    {non,non,non,non,non,CHE,non,non,non},
//                                    {non,non,non,non,non,non,non,non,non} };
//
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < 9; j++) {
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
//    calMaxCheese(array, 0, COLSIZE - 1);
//    return 0;
//}