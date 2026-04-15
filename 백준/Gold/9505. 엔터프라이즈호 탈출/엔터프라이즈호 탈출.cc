
#pragma GCC optimize("O3")

// gcc things
// #include <ext/rope>

#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
#include <ranges>
#include <chrono>
#include <random>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define endl '\n'

constexpr inline ll powll(ll n, ll k, ll mod = static_cast<ll>(1e9) + 7) {
	ll r = 1 % mod;
	while (k) {
		if (k & 1) r = (r * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}
	return r;
};

template <typename T>
constexpr inline auto OUT(const T R, const T C) {
	return [=](const T x, const T y) -> bool { return (min(x,y) < 0 || x >= R  || y >= C); };
}

template <typename ...Args>
constexpr inline void read(Args&... args) {
	(std::cin >> ... >> args);
}

template <typename ...Args>
constexpr inline void write(Args&& ...args) {
	(std::cout << ... << args);
}

template <typename T>
constexpr inline void unique(vector<T>& v) {
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
}

///////////////////////////////////////////////////////////////////////

map<char, int> w;
char m[1111][1111];
int d[1111][1111];

void solve() {

	w.clear();
	memset(d, -1, sizeof d);

	int K, W, H; read(K, W, H);

	FOR(_, 0, K) {
		char c; int n; read(c, n);
		w[c] = n;
	}

	int sx, sy;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> m[i][j];
			if (m[i][j] == 'E') {
				sx = i; sy = j;
			}
		}
	}

	priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<>> q; q.push({ 0,sx,sy });

	auto out = OUT(H, W);

	while (q.size()) {
		auto [ww, x, y] = q.top(); q.pop();
		if (d[x][y] == -1 || d[x][y] > ww) {
			d[x][y] = ww;
		}
		else {
			continue;
		}

		FOR(i, 0, 4) {
			int nx = x + "1102"[i] - '1';
			int ny = y + "0211"[i] - '1';
			if (out(nx, ny)) {
				cout << ww << endl; return;
			}
			auto tmp = ww + w[m[nx][ny]];
			if(d[nx][ny] == -1 || d[nx][ny] > tmp) q.push({tmp, nx, ny});
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) solve();

}
