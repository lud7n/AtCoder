#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<ll>;

int main()
{
    ll r, c, sx, sy, gx, gy;
    cin >> r >> c >> sx >> sy >> gx >> gy;
    sy--, sx--, gy--, gx--;
    char a[r][c];
    rep(i, r) rep(j, c) cin >> a[i][j];
    queue<P> que;
    queue<int> que_cnt;
    que.push(make_pair(sx, sy));
    que_cnt.push(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dist[210][210];

    memset(dist, -1, sizeof(dist));
    dist[sx][sy] = 1;

    ll ans = 0, answer = 10000000000;
    bool ok = false;

    while (!que.empty())
    {
        P cur = que.front();
        que.pop();
        ans = que_cnt.front();
        que_cnt.pop();
        int x = cur.first;
        int y = cur.second;
        ans++;

        rep(dir, 4)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx == gx and ny == gy)
            {
                answer = min(ans, answer);
            }
            if (nx < 0 or nx >= r or ny < 0 or ny >= c) // 場外
                continue;
            if (a[nx][ny] == '#')
                continue;
            if (dist[nx][ny] == -1)
            {
                // cout << nx << " " << ny << endl;
                // ans++;
                dist[nx][ny] = dist[x][y] + 1;
                que.push(make_pair(nx, ny));
                que_cnt.push(ans);
            }
        }
    }
    cout << answer << endl;

    return 0;
}