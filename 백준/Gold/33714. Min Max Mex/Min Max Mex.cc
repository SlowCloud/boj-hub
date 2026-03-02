#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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


map<int, int> cnt;
vector<int> elements;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; read(N, K);

	FOR(i, 0, N) {
		int n; cin >> n;
		cnt[n]++;
		elements.push_back(n);
	}
	unique(elements);

	// smallest mex(A)
	{
		int res = INT_MAX;
		if (cnt.begin()->first > 0) {
			res = 0;
		}
		else {
			for (const auto [first, second] : cnt) {
				if (cnt.count(first + 1) == 0) {
					res = first + 1; break;
				}
			}
		}

		for (const auto [first, second] : cnt) {
			if (first > res) break;
			if (second <= K) {
				res = first;
				break;
			}
		}

		cout << res << endl;
	}

	// biggest mex(A)
	{
		int l, r, m;
		l = 0, r = 1e9 + 222'222;
		while (l <= r) {
			m = l + r >> 1;

			int cnt = count_less_than(elements, m);

			if (m <= K + cnt) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		cout << r;

	}

}
