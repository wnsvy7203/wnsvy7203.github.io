#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 300000

using namespace std;

int N, K;
vector<pair<int, int>> MV(MAX);
vector<int> C(MAX);

void init()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> MV[i].first >> MV[i].second;

    for (int i = 0; i < K; i++)
        cin >> C[i];

    sort(MV.begin(), MV.begin()+N);
    sort(C.begin(), C.begin()+K);
}

void find_answer()
{
    int ans = 0;
    while (!C.empty())
    {

    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}
