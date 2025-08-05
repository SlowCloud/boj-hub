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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, F; cin >> N >> F;
	N -= N % 100;

	int now = 1e9;
	FOR(i, 0, 100) {
		int tmp = N + i;
		if (tmp % F == 0) {
			now = tmp; break;
		}
	}

	string res = to_string(now);
	cout << setw(2) << setfill('0') << res.substr(max(0, (int)res.size() - 2));

}
