#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Utility function to find the minimum of three numbers
inline int threeMin(int x, int y, int z) { return min(min(x, y), z); }
void printLev(string source, string target, vector<vector<int>> dp) {
    printf("   │   ");
    for (int k = 0; k < source.length(); k++) printf("   %c", source[k]);
    printf("\n───┼───────────────────────\n");
    for (int i = 0; i <= target.length(); i++) {
        if (i > 0) printf(" %c │", target[i - 1]);
        else printf("   │");
        for (int j = 0; j <= source.length(); j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }printf("\n");
}


int editDistDP(string source, string target) {

    int m = target.length();
    int n = source.length();    

    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
    vector<vector<string>> saveEdit(m + 1, vector<string>(n + 1)); //해당 위치까지 이동한 경로를 저장하는 string 배열

    // Fill d[][] in bottom up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, only option is to
            // insert all characters of second string
            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j == 0)
                dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (source[j - 1] == target[i - 1]) dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + threeMin(dp[i][j - 1], // Delete
                                         dp[i - 1][j], // Insert
                                         dp[i - 1][j - 1]); // Replace
        }
    }
    printLev(source, target, dp);

    return dp[m][n];
}

// Driver code
int main()
{
    // your code goes here
    string S = "fsdlds;kfa";
    string T = "ksdjfhdhlsfkuashlaej";

    cout << editDistDP(S, T) << endl;

    return 0;
}

//int editDistDP(string source, string target) {
//
//    int m = target.length();
//    int n = source.length();
//
//    // Create a table to store results of subproblems
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화
//
//    // Fill d[][] in bottom up manner
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            // If first string is empty, only option is to
//            // insert all characters of second string
//            if (i == 0)
//                dp[i][j] = j; // Min. operations = j
//
//            // If second string is empty, only option is to
//            // remove all characters of second string
//            else if (j == 0)
//                dp[i][j] = i; // Min. operations = i
//
//            // If last characters are same, ignore last char
//            // and recur for remaining string
//            else if (source[j - 1] == target[i - 1]) dp[i][j] = dp[i - 1][j - 1];
//
//            // If the last character is different, consider
//            // all possibilities and find the minimum
//            else
//                dp[i][j] = 1 + returnMin(dp[i][j - 1], // Delete
//                    dp[i - 1][j], // Insert
//                    dp[i - 1][j - 1]); // Replace
//        }
//    }
//    printf("   │   ");
//    for (int k = 0; k < n; k++) printf("   %c", source[k]);
//    printf("\n───┼───────────────────────\n");
//    for (int i = 0; i <= m; i++) {
//        if (i > 0) printf(" %c │", target[i - 1]);
//        else printf("   │");
//        for (int j = 0; j <= n; j++) {
//            printf("%3d ", dp[i][j]);
//        }
//        printf("\n");
//    }printf("\n");
//
//    return dp[m][n];
//}