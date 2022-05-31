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

double editDistDP(wstring source, wstring target, double insertCost, double deleteCost, double replaceCost) {

    size_t m = source.length();
    size_t n = target.length();

    // 동적 계획법을 이용하기 위한 2차원 테이블 생성, 편집 내용을 저장하기 위한 테이블 작성
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
    vector<vector<wstring>> saveEdit(n + 1, vector<wstring>(m + 1, L"Edit\n──────────────────────\n")); //해당 위치까지 이동한 경로를 저장하는 string 배열
    wstring inputTmp;

    dp[0][0] = 0; //최소의 base case

    //i = 행 방향의 idx count (target의 길이)
    //j = 열 방향의 idx count (source의 길이)

    //source를 빈 string으로 바꾸는 경우 삭제할 연산 (source -> 0)
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + deleteCost; // Min. operations = i

        inputTmp = (wstring)L"-> (delete \"" + source[j - 1] + (wstring)L"\")\n";
        saveEdit[0][j] = saveEdit[0][j - 1] + inputTmp;
    }

    //빈 string을 target으로 바꾸는 경우 삽입할 연산 (0 -> target)
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + insertCost;

        inputTmp = (wstring)L"insert  : (\"" + target[i - 1] + (wstring)L"\")\n";
        saveEdit[i][0] = saveEdit[i - 1][0] + inputTmp;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            //비교하는 두 문자가 같은 경우
            if (source[j - 1] == target[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                saveEdit[i][j] = saveEdit[i - 1][j - 1];

            }

            //두 문자가 다른 경우 각각의 cost를 고려한 경우를 비교해 최소를 선택
            else {
                switch (getMinIdx(dp[i][j - 1] + deleteCost, dp[i - 1][j] + insertCost, dp[i - 1][j - 1] + replaceCost)) {
                case 0:
                    dp[i][j] = dp[i][j - 1] + deleteCost;
                    inputTmp = (wstring)L"delete  : (\"" + source[j - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i][j - 1] + inputTmp;
                    break;
                case 1:
                    dp[i][j] = dp[i - 1][j] + insertCost;
                    inputTmp = (wstring)L"insert  : (\"" + target[i - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i - 1][j] + inputTmp;
                    break;
                case 2:
                    dp[i][j] = dp[i - 1][j - 1] + replaceCost;
                    inputTmp = (wstring)L"replace : (\"" + source[j - 1] + (wstring)L"\" to \""  + target[i - 1] + (wstring)L"\")\n";
                    saveEdit[i][j] = saveEdit[i - 1][j - 1] + inputTmp;
                    break;
                }
            }
        }
    }
    printLev(source, target, dp);
    wcout << saveEdit[n][m] << endl;
    return dp[n][m];
}

int main() {
    std::locale::global(std::locale(""));

    //wstring S = L"Levenshtein";
    //wstring T = L"Meilenstein";
    wstring S = L"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세 무궁화 삼천리 화려 강산 대한 사람 대한으로 길이 보전하세";
    wstring T = L"남산 위에 저 소나무 철갑을 두른 듯 바람 서리 불변함은 우리 기상일세 무궁화 삼천리 화려 강산 대한 사람 대한으로 길이 보전하세";

    cout << "source를 target으로 변환하는 편집거리 = " << editDistDP(S, T, INSERTCOST, DELETECOST, REPLACECOST) << endl;

    return 0;
}