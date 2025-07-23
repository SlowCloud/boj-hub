#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int res = 1e9;
vector<tuple<int, int, int>> colors;
int A, B, C;

void check(int a, int b, int c) {
	res = min(res, abs(A - a) + abs(B - b) + abs(C - c));
}

void dfs(int i, int n, int a, int b, int c) {
	if (n > 7) return;
	if(n > 1) check(a / n, b / n, c / n);
	if (i >= colors.size()) return;
	dfs(i + 1, n, a, b, c);
	auto [aa, bb, cc] = colors[i];
	dfs(i + 1, n + 1, a + aa, b + bb, c + cc);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 0, N) {
		int a, b, c; cin >> a >> b >> c;
		colors.push_back({ a,b,c });
	}
	cin >> A >> B >> C;

	dfs(0, 0, 0, 0, 0);

	cout << res;

}
