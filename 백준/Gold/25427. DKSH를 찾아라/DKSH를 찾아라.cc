#pragma GCC optimize("Ofast")

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
	return [&](const T x, const T y) -> bool { return (x < 0 || x >= R || y < 0 || y >= C); };
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

// only for sorted unique vector
template <typename T>
[[gnu::always_inline]] constexpr int count_less_than(vector<T>& v, T val) {
	return lower_bound(ALL(v), val) - v.begin();
}

// only for sorted unique vector
template <typename T>
[[gnu::always_inline]] constexpr int count_less_equal(vector<T>& v, T val) {
	return upper_bound(ALL(v), val) - v.begin();
}

///////////////////////////////////////////////////////////////////////



vector<int> idx[4];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	string s; cin >> s;
	int sz = s.size();
	FOR(i, 0, sz) {
		const char &c = s[i];
		if (c == 'D') idx[0].push_back(i);
		if (c == 'K') idx[1].push_back(i);
		if (c == 'S') idx[2].push_back(i);
		if (c == 'H') idx[3].push_back(i);
	}

	ll res = 0;
	FOR(i, 0, idx[0].size()) {
		int j = upper_bound(ALL(idx[1]), idx[0][i]) - idx[1].begin();
		for (;j < idx[1].size();j++) {
			int k = upper_bound(ALL(idx[2]), idx[1][j]) - idx[2].begin();
			for (;k < idx[2].size();k++) {
				int l = upper_bound(ALL(idx[3]), idx[2][k]) - idx[3].begin();
				res += idx[3].size() - l;
			}
		}
	}

	cout << res;

}
