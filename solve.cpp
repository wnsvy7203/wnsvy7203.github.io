#include <iostream>
#include <vector>

using namespace std;

int N, M;
int travels[1000], par[201];

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
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        par[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            bool flag;
            cin >> flag;
            if (flag && (i < j))
                union_sets(i, j);
        }
    
    for (int i = 0; i < M; i++)
        cin >> travels[i];
}

void find_answer()
{
    int root = find(travels[0]);
    for (int i = 1; i < M; i++)
        if (find(travels[i]) != root)
        {
            cout << "NO";
            return;
        }

    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}