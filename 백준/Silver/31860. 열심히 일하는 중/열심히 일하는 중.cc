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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K; cin >> N >> M >> K;

	vector<int> D(N);
	for (auto& i : D) cin >> i;

	priority_queue<int> pq;
	for (const auto& i : D) pq.push(i);

	vector<ll> res;
	ll prev = 0;

	while (pq.size()) {
		ll now = pq.top(); pq.pop();
		ll today = prev / 2 + now;

		res.push_back(today);
		prev = today;
		if (now - M > K) pq.push(now - M);
	}

	cout << res.size() << endl;
	for (const auto& i : res) cout << i << ' ';

}
