#include <iostream>
#include <queue>
#include <tuple>

#define INF 1e9

using namespace std;

int H, W;
int r1 = -1, c1 = -1, r2 = -1, c2 = -1;
char board[100][100];

void init()
{
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < W; j++)
        {
            board[i][j] = str[j];
            
            if (board[i][j] == 'C')
            {
                if (r1 == -1)
                {
                    r1 = i;
                    c1 = j;
                }
                else
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }
}

queue<tuple<int, int, int>> que;
int dist[100][100][4];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
void bfs()
{
    fill_n(&dist[0][0][0], 100 * 100 * 4, INF);
    for (int d = 0; d < 4; d++)
    {
        int r = r1 + dr[d];
        int c = c1 + dc[d];
        int dir = d;

        if (r < 0 || r >= H || c < 0 || c >= W)
            continue;
        
        if (board[r][c] == '*')
            continue;
        
        dist[r][c][d] = 0;
        que.push({r, c, dir});
    }

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int dir = get<2>(que.front());
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            if ((dir == 0 && d == 1) || (dir == 1 && d == 0))
                continue;
            
            if ((dir == 2 && d == 3) || (dir == 3 && d == 2))
                continue;

            int cnt = dist[r][c][dir];
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;

            if (board[nr][nc] == '*')
                continue;

            if (dir != d)
                cnt++;

            if (dist[nr][nc][d] > cnt)
            {
                dist[nr][nc][d] = cnt;
                que.push({nr, nc, d});
            }
        }
    }
}

void find_answer()
{
    int ans = INF;
    for (int d = 0; d < 4; d++)
        ans = min(ans, dist[r2][c2][d]);
    
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    bfs();
    find_answer();
}