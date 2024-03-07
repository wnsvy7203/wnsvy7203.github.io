#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define MAX 100001

using namespace std;

int T, n;
int arr[MAX];
bool done[MAX];

void dfs(int idx)
{
    vector<int> visited;
    visited.push_back(idx);

    stack<int> stk;
    stk.push(idx);

    while (!stk.empty())
    {
        int student = stk.top();
        stk.pop();

        int next = arr[student];

        if (next != idx && find(visited.begin(), visited.end(), next) == visited.end())
        {
            stk.push(arr[student]);
            visited.push_back(arr[student]);
        }
        else if (next == idx)
        {
            visited.push_back(idx);
        }
    }

    if (visited[0] == visited[visited.size()-1])
        for (int num : visited)
            done[num] = 1;
}

void find_answer()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!done[i])
            ans++;

    cout << ans << '\n';
}

void init()
{
    cin >> T;
    while (T--)
    {
        fill_n(&arr[1], n, 0);
        fill_n(&done[1], n, false);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];

            if (arr[i] == i)
                done[i] = 1;
        }

        for (int i = 1; i <= n; i++)
            if (!done[i] && arr[i] != i)
                dfs(i);

        find_answer();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}
