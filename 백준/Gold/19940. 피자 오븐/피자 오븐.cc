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


int vst[66];
int dp[66][5];
int m[5];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fill(vst, vst + 66, -1);
	m[0] = 60;
	m[1] = 10;
	m[2] = -10;
	m[3] = 1;
	m[4] = -1;

	queue<int> q;
	q.push(0);
	vst[0] = 0;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 4; i >= 0; i--) {
			int next = now + m[i];
			if (next < 0 || next >= 66 || vst[next] != -1) continue;
			vst[next] = vst[now] + 1;
			FOR(j, 0, 5) dp[next][j] = dp[now][j];
			dp[next][i]++;
			q.push(next);
		}
	}

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int tmp = N / 60; N %= 60;
		cout << tmp + dp[N][0] << ' ';
		FOR(i, 1, 5) cout << dp[N][i] << ' ';
		cout << endl;
	}

}
