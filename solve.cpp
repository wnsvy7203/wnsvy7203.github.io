#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cap = 4;
int n = 5;
vector<int> deliveries = {1, 0, 3, 1, 2};
vector<int> pickups = {0, 3, 0, 4, 0};

long long solution() {
    long long answer = 0;
    
    // d: delivery, p: pickup
    int d = n-1, p = n-1;
    while (1)
    {
        bool flag_d = 1, flag_p = 1;
        for (int i = n-1; i >= 0; i--)
        {
            if (deliveries[i])
            {
                d = i;
                break;
            }

            if (!i)
                flag_d = 0;
        }
        
        for (int i = n-1; i >= 0; i--)
        {
            if (pickups[i])
            {
                p = i;
                break;
            }

            if (!i)
                flag_p = 0;
        }
        
        if (!flag_d && !flag_p)
            break;

        n = max(d, p);
        answer += (n+1) * 2;
        
        // 현재 트럭에 담고 있는 d, p
        int now_d = 0, now_p = 0;
                
        for (int i = d; i >= 0; i--)
        {
            if (!deliveries[i])
                continue;

            if (now_d + deliveries[i] >= cap)
            {
                deliveries[i] -= (cap - now_d);
                now_d += (cap - now_d);
            }
            else
            {
                now_d += deliveries[i];
                deliveries[i] = 0;
            }

            if (now_d == cap)
                break;
        }
        
        for (int i = p; i >= 0; i--)
        {
            if (!pickups[i])
                continue;

            if (now_p + pickups[i] >= cap)
            {
                pickups[i] -= (cap - now_p);
                now_p += (cap - now_p);
            }
            else
            {
                now_p += pickups[i];
                pickups[i] = 0;
            }

            if (now_p == cap)
                break;
        }
    }
    
    return answer;
}

int main()
{
    cout << solution();
}