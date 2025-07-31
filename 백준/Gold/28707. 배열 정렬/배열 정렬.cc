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


map<string, int> vst;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	
	string now;
	FOR(i, 0, N) {
		int n; cin >> n;
		now.push_back(n + '0');
	}

	vector<tuple<int, int, int>> v;
	int M; cin >> M;
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a - 1,b - 1,c });
	}

	string target = now;
	sort(all(target));

	vst[now] = 0;
	queue<string> q; q.push(now);
	while (q.size()) {
		auto now = q.front(); q.pop();
		for (const auto& [a, b, c] : v) {
			string next = now;
			swap(next[a], next[b]);
			if (vst.find(next) != vst.end() && vst[next] <= vst[now] + c) continue;
			vst[next] = vst[now] + c;
			q.push(next);
		}
	}
	
	if (vst.find(target) == vst.end()) {
		cout << -1;
	}
	else {
		cout << vst[target];
	}

}
