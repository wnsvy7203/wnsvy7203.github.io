// 160ms

#include <iostream>

using namespace std;

int N, M;
int par[2001], enemy[2001];

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
}

void find_answer()
{
    while (M--)
    {
        int A, B;
        cin >> A >> B;

        if (find(A) == find(B))
        {
            cout << 0;
            return;
        }

        if (enemy[A])
            union_sets(enemy[A], B);
        else
            enemy[A] = B;
        
        if (enemy[B])
            union_sets(enemy[B], A);
        else
            enemy[B] = A;
    }

    cout << 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}