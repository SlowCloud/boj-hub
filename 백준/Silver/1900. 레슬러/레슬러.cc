#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Node {
	int a, b, idx;
	bool operator < (const Node& n) {
		return a + b * n.a < n.a + n.b * a;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<Node> v;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b, i });
	}

	sort(rall(v));

	for (auto& i : v) cout << i.idx + 1 << ' ';

}
