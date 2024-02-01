#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, ans;
int candy[30001], par[30001], group[30001], dp[30001][3001];

int find(int x)
{
    if (par[x] == x)
        return x;
    
    return par[x] = find(par[x]);
}

void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);
    
    par[y] = x;
}

void init()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> candy[i];
        par[i] = i;
        group[i] = 1;
    }

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
    {
        if (par[i] == i)
            continue;

        int root = find(i);
        candy[root] += candy[i];
        group[root] += group[i];
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            dp[i][j] = dp[i-1][j];

            if (j >= group[i])
                dp[i][j] = max(dp[i][j], dp[i][j-group[i]] + candy[i]);
        }
    }

    cout << dp[N][K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}