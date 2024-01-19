// 8ms

#include <iostream>

#define MAX 100000

using namespace std;

int N, S;
int arr[MAX];
void input()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

int s, e;
int ans = MAX;
void two_pointer()
{
    int sum = 0;
    while (e < N)
    {
        // sum이 S보다 작다면 e만 커질 것이다.
        sum += arr[e];
        
        // S(목표치)에 도달했다면 s번째 인덱스를 빼 주면서 ans를 갱신
        while (sum >= S)
        {
            ans = min(ans, e-s+1);
            sum -= arr[s];
            s++;
        }

        e++;
    }

    // 함정 카드, ans가 한 번도 갱신되지 않았다면 답이 없다는 뜻이므로 조건대로 0 출력
    if (ans == MAX)
        cout << 0;
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    two_pointer();
}