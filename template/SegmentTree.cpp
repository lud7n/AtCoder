#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using V = vector<ll>;

class SegmentTree
{
public:
    int dat[300009], size = 1;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        for (int i = 1; i < size * 2; i++)
            dat[i] = 0;
    }

    // クエリ１に対する処理
    void update(int pos, int x)
    {
        pos = pos + size - 1;
        dat[pos] = x;
        while (pos >= 2) // 一段上はu/2の商
        {
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
            // 1番上に来るまで最大値を更新し続ける
        }
    }

    // クエリ２に対する処理
    int query(int l, int r, int a, int b, int u)
    {
        if (r <= a or b <= l)
            return -1000000000;
        if (l <= a and b <= r)
            return dat[u];
        int m = (a + b) / 2;
        int ans_l = query(l, r, a, m, u * 2);
        int ans_r = query(l, r, m, b, u * 2 + 1);
        return max(ans_l, ans_r);
    }
};

int n, q;
SegmentTree z;

int main()
{
    cin >> n >> q;

    z.init(n);

    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int pos, x;
            cin >> pos >> x;
            z.update(pos, x);
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            int answer = z.query(l, r, 1, z.size + 1, 1);
            cout << answer << endl;
        }
    }

    return 0;
}