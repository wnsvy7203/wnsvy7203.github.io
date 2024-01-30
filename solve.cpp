#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int par[101];
double ans;
vector<pair<double, double>> coord;
vector<tuple<double, int, int>> edges;

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
    
    par[y] = x;
}

double dist(pair<double, double> x, pair<double, double> y)
{
    double d1 = (x.first - y.first) * (x.first - y.first);
    double d2 = (x.second - y.second) * (x.second - y.second); 
    return sqrt(d1 + d2);
}

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double r, c;
        cin >> r >> c;
        coord.push_back({r, c});
    }

    vector<int> v;
    for (int i = 0; i < n-2; i++)
        v.push_back(0);
    for (int i = 0; i < 2; i++)
        v.push_back(1);
    
    do
    {
        int first = n, second = n;
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                if (first == n)
                    first = i;
                else
                    second = i;
        }

        double cost = dist(coord[first], coord[second]);
        edges.push_back({cost, first, second});
    } while (next_permutation(v.begin(), v.end()));

    sort(edges.begin(), edges.end());
    
    for (int i = 1; i < n; i++)
        par[i] = i;
}

void kruskal()
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (find(get<1>(edges[i])) != find(get<2>(edges[i])))
        {
            union_sets(get<1>(edges[i]), get<2>(edges[i]));
            ans += get<0>(edges[i]);
        }
    }

    cout.precision(2);
    cout << fixed << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    kruskal();
}