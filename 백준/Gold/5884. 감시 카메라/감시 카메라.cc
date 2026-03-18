
#if defined(_MSC_VER)
#pragma optmiize("t", on)
#else
#pragma GCC optimize("O2")
#endif

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
constexpr inline int count_less_than(vector<T>& v, T val) {
	return lower_bound(ALL(v), val) - v.begin();
}

// only for sorted unique vector
template <typename T>
constexpr inline int count_less_equal(vector<T>& v, T val) {
	return upper_bound(ALL(v), val) - v.begin();
}

///////////////////////////////////////////////////////////////////////



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	if (N <= 3) {
		cout << 1; exit(0);
	}

	vector<pii> v(N);
	for (auto& p : v) {
		read(p.first, p.second);
	}

	set<int> x, y;
	for (const auto& p : v) {
		x.insert(p.first);
		y.insert(p.second);
	}

	if (x.size() <= 3 || y.size() <= 3) {
		cout << 1; exit(0);
	}

	// x=1, y=2
	for (const auto& xx : x) {
		set<int> tmp;
		for (const auto& p : v) {
			if (p.first != xx) tmp.insert(p.second);
			if (tmp.size() > 2) break;
		}
		if (tmp.size() <= 2) {
			cout << 1; exit(0);
		}
	}
	// x=2, y=1
	for (const auto& yy : y) {
		set<int> tmp;
		for (const auto& p : v) {
			if (p.second != yy) tmp.insert(p.first);
			if (tmp.size() > 2) break;
		}
		if (tmp.size() <= 2) {
			cout << 1; exit(0);
		}
	}

	cout << 0;

}
