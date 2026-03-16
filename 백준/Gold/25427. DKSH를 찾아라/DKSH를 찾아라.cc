#pragma GCC optimize("O2")

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
ll dp[4][111'111];


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

	// DKSH

	// H
	for (auto i = idx[3].rbegin(); i != idx[3].rend();i++) {
		dp[3][*i] = 1;
	}
	for (int i = 100'000;i >= 0;i--) {
		dp[3][i] += dp[3][i + 1];
	}

	// S
	for (auto i = idx[2].rbegin(); i != idx[2].rend();i++) {
		dp[2][*i] = dp[3][*i + 1];
	}
	for (int i = 100'000;i >= 0;i--) {
		dp[2][i] += dp[2][i + 1];
	}

	// K
	for (auto i = idx[1].rbegin(); i != idx[1].rend();i++) {
		dp[1][*i] = dp[2][*i + 1];
	}
	for (int i = 100'000;i >= 0;i--) {
		dp[1][i] += dp[1][i + 1];
	}

	// D
	for (auto i = idx[0].rbegin(); i != idx[0].rend();i++) {
		dp[0][*i] = dp[1][*i + 1];
	}
	for (int i = 100'000;i >= 0;i--) {
		dp[0][i] += dp[0][i + 1];
	}

	cout << dp[0][0];

}
