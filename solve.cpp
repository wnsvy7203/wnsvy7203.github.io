#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M;
int A[MAX], par[MAX];

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
    else if (x == y)
        return;
    
    par[y] = x;
    A[x] += A[y];
    A[y] = 0;
}

void begin_war(int x, int y)
{
    x = find(x);
    y = find(y);

    if (A[x] > A[y])
        swap(x, y);
    else if (A[x] == A[y])
    {
        A[x] = 0; par[x] = 0;
        A[y] = 0; par[y] = 0;
        return;
    }

    A[y] -= A[x];
    A[x] = 0;
    par[x] = y;
}

void init()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        par[i] = i;
    }
    
    while (M--)
    {
        int O, P, Q;
        cin >> O >> P >> Q;

        if (O == 1)
            union_sets(P, Q);
        else
            begin_war(P, Q);
    }
}

void find_answer()
{
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= N; i++)
    {
        if (par[i] == i)
        {
            ans.push_back(A[i]);
            cnt++;
        }
    }

    sort(ans.begin(), ans.end());

    cout << cnt << '\n';
    for (int num : ans)
        cout << num << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}