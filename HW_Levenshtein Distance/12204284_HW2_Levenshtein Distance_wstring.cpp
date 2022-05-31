#include <iostream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

#define INSERTCOST  0.7
#define DELETECOST  0.5
#define REPLACECOST 0.3


// Utility function to find the minimum of three numbers
inline double threeMin(double x, double y, double z) { return min(min(x, y), z); }

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


int editDistDP(wstring source, wstring target, double insertCost, double deleteCost, double replaceCost) {

    int m = source.length();
    int n = target.length();

    // Create a table to store results of subproblems
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
    vector<vector<string>> saveEdit(n + 1, vector<string>(m + 1)); //해당 위치까지 이동한 경로를 저장하는 string 배열

    dp[0][0] = 0; //최소의 base case

    //i = 행 방향의 idx count (target의 길이)
    //j = 열 방향의 idx count (source의 길이)

    //source를 빈 string으로 바꾸는 경우 삭제할 연산 (source -> 0)
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] + deleteCost; // Min. operations = i
    }

    //빈 string을 target으로 바꾸는 경우 삽입할 연산 (0 -> target)
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + insertCost;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            //비교하는 두 문자가 같은 경우
            if (source[j - 1] == target[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            //두 문자가 다른 경우 각각의 cost를 고려한 경우를 비교해 최소를 선택
            else {
                dp[i][j] = threeMin(dp[i][j - 1] + deleteCost, // Delete
                    dp[i - 1][j] + insertCost, // Insert
                    dp[i - 1][j - 1] + replaceCost); // Replace
            }
        }
    }
    printLev(source, target, dp);

    return dp[n][m];
}



int main() {
    std::locale::global(std::locale(""));

    wstring S = L"Levenshtein";
    wstring T = L"Meilenstein";

    cout << "source를 target으로 변환하는 편집거리 = " << editDistDP(S, T, INSERTCOST, DELETECOST, REPLACECOST) << endl;

    return 0;
}