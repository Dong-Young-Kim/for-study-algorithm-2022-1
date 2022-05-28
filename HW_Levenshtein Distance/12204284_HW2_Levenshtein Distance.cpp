#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Utility function to find the minimum of three numbers
int returnMin(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2) {

    int m = str1.length();
    int n = str2.length();

    // Create a table to store results of subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //크기가 (m+1) * (n+1)인 2차원 배열을 생성한 후 모두 0으로 초기화

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
            else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider
            // all possibilities and find the minimum
            else
                dp[i][j] = 1 + returnMin(dp[i][j - 1], // Insert
                                         dp[i - 1][j], // Remove
                                         dp[i - 1][j - 1]); // Replace
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }printf("\n");

    return dp[m][n];
}

// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2) << endl;

    return 0;
}