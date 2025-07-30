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

	int N, M; cin >> N >> M;

	priority_queue<int> pq;
	FOR(i, 0, N) {
		int n; cin >> n;
		pq.push(n);
	}

	FOR(i, 0, M) {
		int n; cin >> n;
		if (pq.top() < n) {
			cout << 0; exit(0);
		}
		int now = pq.top(); pq.pop();
		now -= n;
		if (now) pq.push(now);
	}

	cout << 1;

}
