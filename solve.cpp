#include <iostream>
#include <vector>

using namespace std;

long long A, B, ans;
long long dp[63];

long long one(long long n)
{
    long long res = n & 1;
    for (int i = 63; i > 0; i--)
        if (n & (1LL << i))
        {
            res += dp[i-1] + (n - (1LL << i) + 1);
            n -= 1LL << i;
        }
    
    return res;
}

void dynamic()
{
    dp[0] = 1;
    for (int i = 1; i < 63; i++)
        dp[i] = dp[i-1] * 2 + (1LL << i);
}

void init()
{
    cin >> A >> B;
}

void find_answer()
{
    cout << one(B) - one(A-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dynamic();
    init();
    find_answer();
}