#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Node {
	ll v;
	int i;
	bool operator < (const Node& n) const {
		return v > n.v;
	}
	Node(): v(0), i(0) {}
	Node(ll v, int i) : v(v), i(i) {}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;
	ll M; cin >> M;

	vector<ll> P(N), C(N);

	FOR(i, 0, N) {
		cin >> P[i] >> C[i];
	}

	priority_queue<ll, vector<ll>, greater<>> recover;
	priority_queue<Node> cheap, expensive;

	FOR(i, 0, K) {
		recover.push(0ll);
	}

	FOR(i, 0, N) {
		cheap.push({ C[i], i });
		expensive.push({ P[i], i });
	}

	vector<bool> vst(N, 0);
	int cnt = 0;
	while (M && cnt < N) {
		while (vst[cheap.top().i]) cheap.pop();
		while (vst[expensive.top().i]) expensive.pop();

		// 쿠폰값 + 할인값과 원값 비교
		if (recover.top() + cheap.top().v < expensive.top().v) {
			const Node top = cheap.top();
			ll cost = recover.top() + top.v;
			if (M < cost) break;
			M -= cost;
			recover.pop();
			recover.push(P[top.i] - C[top.i]);
			vst[top.i] = true;
		}
		else {
			const Node top = expensive.top();
			ll cost = top.v;
			if (M < cost) break;
			M -= cost;
			vst[top.i] = true;
		}
		cnt++;

	}

	cout << cnt << endl;

}
