// 516ms

#include <iostream>

#define MAX 100001

using namespace std;

int T, n, ans;
int arr[MAX];
bool visited[MAX], done[MAX];

void dfs(int idx)
{
    visited[idx] = 1;

    int next = arr[idx];
    if (!visited[next])
        dfs(next);
    else if (!done[next])
    {
        ans++;

        for (int i = next; i != idx; i = arr[i])
            ans++;
    }
    
    done[idx] = 1;
}

void find_answer()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
        if (!done[i])
            dfs(i);

    cout << n - ans << '\n';
}

void init()
{
    cin >> T;
    while (T--)
    {
        fill_n(&arr[0], MAX, 0);
        fill_n(&visited[0], MAX, false);
        fill_n(&done[0], MAX, false);

        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        find_answer();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}
