#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// bit全探索のテンプレート

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool ok = false;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((b >> i) & 1)
            {
                // 1bitずつ見ていって、１のやつだけ選ぶ
                sum += a[i];
            }
        }
        if (sum == k)
            ok = true;
    }
    if (ok ? cout << "Yes" : cout << "No")
        ;
    return 0;
}
