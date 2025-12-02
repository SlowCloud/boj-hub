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


struct Node {
	int a, b, c, d, e;
	Node operator + (const Node& n) const {
		return { a + n.a, b + n.b, c + n.c, d + n.d, e + n.e };
	}
	void operator += (const Node& n) {
		*this = *this + n;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	int a, b, c, d; cin >> a >> b >> c >> d;

	vector<Node> nodes;
	FOR(i, 0, N) {
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		nodes.push_back({ a,b,c,d,e });
	}

	int res = 1e9;
	vector<int> v;
	for (int i = 0; i < (1 << N); i++) {
		Node now = { 0,0,0,0,0 };
		FOR(j, 0, N) {
			if (i & (1 << j)) {
				now += nodes[j];
			}
		}
		if (now.a >= a && now.b >= b && now.c >= c && now.d >= d) {
			vector<int> tmp;
			FOR(j, 0, N) {
				if (i & (1 << j)) tmp.push_back(j + 1);
			}
			if (res > now.e) {
				res = now.e;
				v = tmp;
			}
			else if (res == now.e) {
				if (v.empty()) v = tmp;
				else v = min(v, tmp);
			}
		}
	}

	if (v.empty()) cout << -1;
	else {
		cout << res << endl;
		for (const auto& i : v) cout << i << ' ';
	}


}
