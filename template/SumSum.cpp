using namespace std;

#include <bits/stdc++.h>

#define ll long long

template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
using vi = vector<int>;
using vl = vector<long long>;
using vd = V<double>;
using vs = V<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;

template <typename T, typename U>
struct P : pair<T, U>
{
    template <typename... Args>
    P(Args... args) : pair<T, U>(args...) {}

    using pair<T, U>::first;
    using pair<T, U>::second;

    P &operator+=(const P &r)
    {
        first += r.first;
        second += r.second;
        return *this;
    }
    P &operator-=(const P &r)
    {
        first -= r.first;
        second -= r.second;
        return *this;
    }
    P &operator*=(const P &r)
    {
        first *= r.first;
        second *= r.second;
        return *this;
    }
    template <typename S>
    P &operator*=(const S &r)
    {
        first *= r, second *= r;
        return *this;
    }
    P operator+(const P &r) const { return P(*this) += r; }
    P operator-(const P &r) const { return P(*this) -= r; }
    P operator*(const P &r) const { return P(*this) *= r; }
    template <typename S>
    P operator*(const S &r) const
    {
        return P(*this) *= r;
    }
    P operator-() const { return P{-first, -second}; }
};
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
using pl = P<long long, long long>;
using pi = P<int, int>;
using vp = V<pl>;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), v.rend()
#define each(i, v) for (auto i : v)
#define each2(x, y, v) for (auto [x, y] : v)
#define rep(i, N) for (long long i = 0; i < (long long)(N); i++)
#define repr(i, N) for (long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i, N) for (long long i = 1; i <= (long long)(N); i++)
#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)
#define reg(i, a, b) for (long long i = (a); i < (b); i++)
#define regr(i, a, b) for (long long i = (b) - 1; i >= (a); i--)
// #define fi first
// #define se second

#define in(a) cin >> a
#define out2(a, b) cout << a << b
#define out(a) cout << a << "\n"
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
#define pb push_back

int main()
{
    ll n;
    in(n);
    vl lx(n), ly(n), rx(n), ry(n);
    rep(i, n) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];

    vvl sum(1010, vl(1010));
    // 二次元累積和

    rep(i, 1010) rep(j, 1010)
    {
        sum[i][j] = 0;
    }

    rep(i, n)
    {
        // 長方形の四隅を加算, 減算していく
        sum[lx[i]][ly[i]] += 1;
        sum[lx[i]][ry[i]] -= 1;
        sum[rx[i]][ly[i]] -= 1;
        sum[rx[i]][ry[i]] += 1;
    }

    // y軸方向
    rep(i, 1010)
    {
        rep(j, 1010)
        {
            if (j)
            {
                sum[i][j] = sum[i][j - 1] + sum[i][j];
            }
        }
    }

    // x軸方向
    rep(i, 1010)
    {
        rep(j, 1010)
        {
            if (j)
            {
                sum[j][i] = sum[j - 1][i] + sum[j][i];
            }
        }
    }

    // 確認用
    //  rep(i, 10)
    //  {
    //      rep(j, 10)
    //      {
    //          cout << sum[i][j] << "  ";
    //      }
    //      cout << endl;
    //  }

    vl ans(n + 1);

    rep(i, 1010)
    {
        rep(j, 1010)
        {
            ans[sum[i][j]]++;
        }
    }

    rep(i, n) cout << ans[i + 1] << endl;

    return 0;
}
