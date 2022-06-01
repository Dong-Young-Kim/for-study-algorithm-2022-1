#include <iostream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

#define INSERTCOST  0.7
#define DELETECOST  0.5
#define REPLACECOST 0.3

//입력으로 들어온 세 수의 가장 작은 수의 index를 반환
inline int getMinIdx(double a, double b, double c) { 
    double min = a; int minIdx = 0;
    if (b < a) {
        min = b;
        minIdx = 1;
    }
    if (c < min) {
        minIdx = 2;
    }
    return minIdx;
}

void printLev(wstring source, wstring target, vector<vector<double>> dp) {
    printf("   │     ");
    for (int k = 0; k < source.length(); k++) wprintf(L"     %c", source[k]);
    printf("\n───┼─────");
    for (int k = 0; k < source.length(); k++) printf("──────");
    printf("\n");
    for (int i = 0; i <= target.length(); i++) {
        if (i > 0) wprintf(L" %c │", target[i - 1]);
        else printf("   │");
        for (int j = 0; j <= source.length(); j++) {
            printf("%5.1f ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//12204284 김동영
double levDist(wstring source, wstring target, double insertCost, double deleteCost, double replaceCost) {

    size_t m = source.length();
    size_t n = target.length();

    // 동적 계획법을 이용하기 위한 2차원 테이블 생성, 편집 내용을 저장하기 위한 테이블 작성
    vector<vector<double>> editDist(n + 1, vector<double>(m + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
    vector<vector<wstring>> saveEdit(n + 1, vector<wstring>(m + 1, L"Edit\n──────────────────────\n")); //해당 위치까지 이동한 경로를 저장하는 string 배열
    wstring inputTmp;

    editDist[0][0] = 0; //최소의 base case

    //i = 행 방향의 idx count (target의 길이)
    //j = 열 방향의 idx count (source의 길이)

    //source를 빈 string으로 바꾸는 경우 삭제할 연산 (source -> 0)
    for (int j = 1; j <= m; j++) {
        editDist[0][j] = editDist[0][j - 1] + deleteCost; // Min. operations = i

        inputTmp = (wstring)L"-> (delete \"" + source[j - 1] + (wstring)L"\")\n";
        saveEdit[0][j] = saveEdit[0][j - 1] + inputTmp;
    }

    //빈 string을 target으로 바꾸는 경우 삽입할 연산 (0 -> target)
    for (int i = 1; i <= n; i++) {
        editDist[i][0] = editDist[i - 1][0] + insertCost;

        inputTmp = (wstring)L"insert  : (\"" + target[i - 1] + (wstring)L"\")\n";
        saveEdit[i][0] = saveEdit[i - 1][0] + inputTmp;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            //비교하는 두 문자가 같은 경우
            if (source[j - 1] == target[i - 1]) {
                editDist[i][j] = editDist[i - 1][j - 1]; //DP를 위한 배열 연산
                saveEdit[i][j] = saveEdit[i - 1][j - 1]; //편집 과정 저장

            }

            //두 문자가 다른 경우 각각의 cost를 고려한 경우를 비교해 최소를 선택
            else {
                switch (getMinIdx(editDist[i][j - 1] + deleteCost, editDist[i - 1][j] + insertCost, editDist[i - 1][j - 1] + replaceCost)) {
                case 0: //delete
                    editDist[i][j] = editDist[i][j - 1] + deleteCost; //DP를 위한 배열 연산
                    inputTmp = (wstring)L"delete  : (\"" + source[j - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i][j - 1] + inputTmp; //편집 과정 저장 (이전 결과에 새로운 편집 결과 더해서 저장)
                    break;
                case 1: //insert
                    editDist[i][j] = editDist[i - 1][j] + insertCost; //DP를 위한 배열 연산
                    inputTmp = (wstring)L"insert  : (\"" + target[i - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i - 1][j] + inputTmp; //편집 과정 저장 (이전 결과에 새로운 편집 결과 더해서 저장)
                    break;
                case 2: //replace
                    editDist[i][j] = editDist[i - 1][j - 1] + replaceCost; //DP를 위한 배열 연산
                    inputTmp = (wstring)L"replace : (\"" + source[j - 1] + (wstring)L"\" to \"" + target[i - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i - 1][j - 1] + inputTmp; //편집 과정 저장 (이전 결과에 새로운 편집 결과 더해서 저장)
                    break;
                }
            }
        }
    }
    printLev(source, target, editDist); //DP를 위한 2차원 배열 출력
    wcout << saveEdit[n][m] << endl; //편집과정 출력
    return editDist[n][m]; //편집거리 반환
}

int main() {
    locale::global(locale(""));

    wstring S = L"Levenshtein";
    wstring T = L"Meilenstein";

    cout << "source를 target으로 변환하는 편집거리 = " << levDist(S, T, INSERTCOST, DELETECOST, REPLACECOST) << endl;
    cout << "\n12204284 김동영" << endl;

    return 0;
}

//input data
//wstring S = L"GUMBO";
//wstring T = L"GAMBOL";
//wstring S = L"Levenshtein";
//wstring T = L"Meilenstein";
//wstring S = L"TACTG";
//wstring T = L"CATGACTG";
//wstring S = L"데이타마이닝";
//wstring T = L"데이터베에스설계";


////편집 과정을 저장하지 않는 levDist version
//double levDist(wstring source, wstring target, double insertCost, double deleteCost, double replaceCost) {
//
//    size_t m = source.length();
//    size_t n = target.length();
//
//    // 동적 계획법을 이용하기 위한 2차원 테이블 생성, 편집 내용을 저장하기 위한 테이블 작성
//    vector<vector<double>> editDist(n + 1, vector<double>(m + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
//
//    wstring inputTmp;
//
//    editDist[0][0] = 0; //최소의 base case
//
//    //i = 행 방향의 idx count (target의 길이)
//    //j = 열 방향의 idx count (source의 길이)
//
//    //source를 빈 string으로 바꾸는 경우 삭제할 연산 (source -> 0)
//    for (int j = 1; j <= m; j++) {
//        editDist[0][j] = editDist[0][j - 1] + deleteCost; // Min. operations = i
//    }
//
//    //빈 string을 target으로 바꾸는 경우 삽입할 연산 (0 -> target)
//    for (int i = 1; i <= n; i++) {
//        editDist[i][0] = editDist[i - 1][0] + insertCost;
//    }
//
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//
//            //비교하는 두 문자가 같은 경우
//            if (source[j - 1] == target[i - 1]) {
//                editDist[i][j] = editDist[i - 1][j - 1];
//            }
//
//            //두 문자가 다른 경우 각각의 cost를 고려한 경우를 비교해 최소를 선택
//            else {
//                switch (getMinIdx(editDist[i][j - 1] + deleteCost, editDist[i - 1][j] + insertCost, editDist[i - 1][j - 1] + replaceCost)) {
//                case 0:
//                    editDist[i][j] = editDist[i][j - 1] + deleteCost;
//                    break;
//                case 1:
//                    editDist[i][j] = editDist[i - 1][j] + insertCost;
//                    break;
//                case 2:
//                    editDist[i][j] = editDist[i - 1][j - 1] + replaceCost;
//                    break;
//                }
//            }
//        }
//    }
//    printLev(source, target, editDist);
//
//    return editDist[n][m];
//}