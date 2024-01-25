// 4ms

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
// string dp[1001][1001];
int dp[1001][1001];
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str1 >> str2;
    int N = str1.length();
    int M = str2.length();
    
    // string으로 푼 부분
    // for (int i = 1; i <= N; i++)
    //     for (int j = 1; j <= M; j++)
    //         if (str1[i-1] == str2[j-1])
    //             dp[i][j] = dp[i-1][j-1] + str1[i-1];
    //         else
    //         {
    //             if (dp[i-1][j].length() >= dp[i][j-1].length())
    //                 dp[i][j] = dp[i-1][j];
    //             else
    //                 dp[i][j] = dp[i][j-1];
    //         }

    // cout << dp[N][M].length() << '\n' << dp[N][M];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    cout << dp[N][M] << '\n';

    while (dp[N][M])
    {
        if (dp[N][M] == dp[N-1][M])
            N--;
        else if (dp[N][M] == dp[N][M-1])
            M--;
        else
        {
            N--, M--;
            ans += str2[M];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}