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

	int N, Q; cin >> N >> Q;

	vector<pii> dots(N); // taste, size
	for (auto& dot : dots) cin >> dot.first;
	for (auto& dot : dots) cin >> dot.second;

	sort(all(dots));

	vector<pii> queries(Q);
	FOR(i, 0, Q) {
		int n; cin >> n;
		queries[i] = { n, i };
	}
	sort(rall(queries));

	vector<int> res(Q);

	int now = N - 1;
	int big = -1;
	int cnt = 0;

	for (const auto& query : queries) {
		const auto& [q, idx] = query;

		while (now >= 0 && dots[now].first >= q) {
			const auto& dot = dots[now]; now--;
			if (big < dot.second) {
				big = dot.second; cnt = 1;
			}
			else if (big == dot.second) {
				cnt++;
			}
		}

		res[idx] = cnt;
	}

	for (const auto& i : res) cout << i << ' ';

}
