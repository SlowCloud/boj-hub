
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0);
constexpr int INF = 2e9;
constexpr long long LLINF = 9e18;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define PI 3.141592653589793


// i번째 사건을 해결했을 때의 위치
vector<ii> lcar, rcar;

// lcar가 마지막으로 있는 위치, rcar가 마지막으로 있는 위치
int dp[1'001][1'001];

// 경찰차가 i,j 위치에 있을 때, 다음 위치를 가리킴
ii movement[1'001][1'001];

int N, W;

int dist(int before, int now, vector<ii>& v) {
	return abs(v[before].first - v[now].first) + abs(v[before].second - v[now].second);
}

// nth번째 사건을 해결해야 할 때, l의 위치 인덱스와 r의 위치 인덱스
int recur(int nth, int l, int r) {
	int& ret = dp[l][r];
	if (nth > W) return ret = 0;
	if (ret != -1) return ret;

	ret = INF;

	int lmove = dist(l, nth, lcar) + recur(nth + 1, nth, r);
	int rmove = dist(r, nth, rcar) + recur(nth + 1, l, nth);

	if (lmove < rmove) {
		ret = lmove; movement[l][r] = {nth, r};
	}
	else {
		ret = rmove; movement[l][r] = { l, nth };
	}

	return ret;
}

int main() {
	FAST; NOTIE;

	cin >> N >> W;

	lcar.resize(W + 1); rcar.resize(W + 1);
	lcar[0] = { 1,1 };
	rcar[0] = { N, N };

	for (int i = 1; i <= W; i++) {
		int a, b; cin >> a >> b;
		lcar[i].first = a; lcar[i].second = b;
		rcar[i] = lcar[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << recur(1, 0, 0) << endl;

	ii now = { 0,0 };
	for (int i = 1; i <= W; i++) {
		int& l = now.first, & r = now.second;
		ii& next = movement[l][r];
		if (now.first < next.first) cout << 1;
		else cout << 2;
		cout << endl;
		now = next;
	}

} // main
