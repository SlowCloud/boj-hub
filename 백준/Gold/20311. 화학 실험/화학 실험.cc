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

	int N, K; cin >> N >> K;

	priority_queue<pii> pq; // cnt, type
	FOR(i, 0, K) {
		int n; cin >> n;
		pq.push({ n, i + 1 });
	}

	pii now = pq.top(); pq.pop();
	now.first--;
	vector<int> res = { now.second };

	while (pq.size()) {
		auto next = pq.top(); pq.pop();
		next.first--;
		res.push_back(next.second);
		if (now.first) {
			pq.push(now);
		}
		now = next;
	}

	if (now.first) {
		cout << -1;
	}
	else {
		for (auto& i : res) {
			cout << i << ' ';
		}
	}

}
