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

	int N, H, T; cin >> N >> H >> T;

	priority_queue<int> pq;
	while (N--) {
		int n; cin >> n;
		pq.push(n);
	}

	int cnt = 0;
	while (cnt < T && pq.top() >= H && pq.top() > 1) {
		cnt++;
		int now = pq.top(); pq.pop();
		pq.push(now >> 1);
	}

	if (pq.top() >= H) {
		cout << "NO " << pq.top();
	}
	else {
		cout << "YES " << cnt;
	}

}
