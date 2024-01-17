// 128ms

#include <iostream>
#include <vector>

#define MAX 4'000'001

using namespace std;

int N, ans;
bool nums[MAX];
vector<int> prime;

void eratos()
{
    fill_n(nums, MAX, true);
    nums[0] = nums[1] = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (nums[i])
            prime.push_back(i);
        for (int j = i*2; j < MAX; j += i)
            nums[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    eratos();

    for (int i = 0; i < prime.size(); i++)
    {
        int sum = 0;

        if (prime[i] > N)
            break;

        for (int j = i; j < prime.size(); j++)
        {
            sum += prime[j];
            if (sum == N)
                ans++;
            else if (sum > N)
                break;
        }
    }

    cout << ans;
}