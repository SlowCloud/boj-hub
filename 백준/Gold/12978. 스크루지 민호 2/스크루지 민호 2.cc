
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

vector<int> G[111'111];

// 정점 i에 경찰서를 세웠을 때, 해당 서브트리에서의 최소 경찰소 개수.
ll dp[111'111][2];


void dfs(int now, int prev) {

	bool vst = false;
	for (int next : G[now]) {
		if (prev == next) continue;
		vst = true;
		dfs(next, now);
	}

	if (vst == 0) {
		dp[now][0] = 1;
		dp[now][1] = 0;
		return;
	}

	// 0: 현재 위치에 경찰서가 있는 경우.
	ll cnt_0 = 1;
	for (int next : G[now]) {
		if (prev == next) continue;
		cnt_0 += min(dp[next][0], dp[next][1]);
	}
	dp[now][0] = cnt_0;

	// 1: 경찰서 없음
	ll cnt_1 = 0;
	for (int next : G[now]) {
		if (prev == next) continue;
		cnt_1 += dp[next][0];
	}
	dp[now][1] = cnt_1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(_, 1, N) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, -1);

	cout << min(dp[1][0], dp[1][1]);

}
