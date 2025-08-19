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


int cnt[22];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K; cin >> N >> K;

	vector<int> v(N);
	for (auto& i : v) {
		string s; cin >> s;
		i = s.size();
	}

	queue<int> q;
	ll res = 0;

	FOR(i, 1, 1 + K) {
		if (i >= v.size()) break;
		int now = v[i];
		q.push(now);
		cnt[now]++;
	}

	FOR(i, 0, v.size() - 1) {
		res += cnt[v[i]];

		cnt[q.front()]--; q.pop();
		int next_idx = i + K + 1;
		if (next_idx < v.size()) {
			cnt[v[next_idx]]++; q.push(v[next_idx]);
		}
	}

	cout << res;

}
