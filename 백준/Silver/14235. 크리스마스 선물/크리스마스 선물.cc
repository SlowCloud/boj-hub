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

	int N; cin >> N;

	priority_queue<int> pq;
	while (N--) {
		int n; cin >> n;
		if (n == 0) {
			if (pq.size()) {
				cout << pq.top() << endl; pq.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else {
			while (n--) {
				int m; cin >> m;
				pq.push(m);
			}
		}
	}

}
