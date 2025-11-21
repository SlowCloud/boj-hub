#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
	cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;

    vector<ll> v(N); for (auto& i : v) cin >> i;

    ll l, r, m;
    l = 1, r = 1'000'000'000'000;
    while (l <= r) {
        m = l + r >> 1;

        ll res = 0;
        for (const auto& i : v) res += m / i;

        if (res < M) l = m + 1;
        else r = m - 1;
    }

    cout << l << endl;

}
