// 28ms

#include <iostream>
#include <tuple>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N;
long long liquid[5000];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> liquid[i];
    
    sort(liquid, liquid+N);
}

tuple<long long, long long, long long> ans;
long long comp = 3'000'000'000;
void two_pointer()
{
    for (int i = 0; i < N-2; i++)
    {
        int s = i+1;
        int e = N-1;

        while (s < e)
        {
            long long sum = liquid[i] + liquid[s] + liquid[e];
            if (abs(comp) > abs(sum))
            {
                comp = sum;
                ans = {liquid[i], liquid[s], liquid[e]};
            }

            if (sum < 0)
                s++;
            else if (sum > 0)
                e--;
            else
                return;
        }
    }
}

void find_answer()
{
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    two_pointer();
    find_answer();
}