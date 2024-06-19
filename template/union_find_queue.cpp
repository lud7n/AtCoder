#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    // グラフが連結しているかどうか？
    // 添字が0からになっているから注意
    vector<bool> reach(n);
    queue<int> que;
    reach[0] = true;
    que.push(0);
    while (!que.empty())
    {
        const int u = que.front();
        que.pop();
        for (const int v : graph[u])
        {
            if (!reach[v])
            {
                reach[v] = true;
                que.push(v);
            }
        }
    }
    rep(i, n)
    {
        if (!reach[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}