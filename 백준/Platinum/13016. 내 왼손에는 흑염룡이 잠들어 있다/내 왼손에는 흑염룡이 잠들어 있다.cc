#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define FAST cin.tie(0)->sync_with_stdio(0);

#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define compress(v) v.erase(unique(all(v)), v.end())
#define ra(i,a,b) for(int i=a;i<b;i++)
#define iter(i,v) for(auto i:v)
#define sz(v) (int)v.size()
#define get1(a) cin >> a
#define get2(a,b) cin >> a >> b
#define get3(a,b,c) cin >> a >> b >> c
#define get4(a,b,c,d) cin >> a >> b >> c >> d
#define prt1(a) cout << a << endl
#define prt2(a,b) cout << a << ' ' << b << endl
#define prt3(a,b,c) cout << a << ' ' << b << ' ' << c << endl
#define prt4(a,b,c,d) cout << a << ' ' << b << ' ' << c << ' ' << d << endl
#define outside(x,y,R,C) (min(x,y) < 1 || R < x || C < y)

vector<ii> G[50'001];

int d[50'001], Q[50'001], res[50'001];

void spfa(int s) {
	fill(d, d + 50'001, INT_MAX);
	d[s] = 0;

	queue<int> q; q.push(s);

	while (q.size()) {
		int now = q.front(); q.pop(); Q[now] = 0;
		for (ii next : G[now]) {
			if (d[next.second] > d[now] + next.first) {
				d[next.second] = d[now] + next.first;
				if (!Q[next.second]) {
					Q[next.second] = 1; q.push(next.second);
				}
			}
		}
	}
}

int main() {
	FAST;

	int N; cin >> N;
	ra(i, 1, N) {
		int u, v, w; get3(u, v, w);
		G[u].emplace_back(w, v);
		G[v].emplace_back(w, u);
	}

	spfa(1);

	int l, r;
	l = r = 0;

	int longest;

	longest = 0;
	ra(i, 1, N + 1) {
		if (d[i] > longest) {
			longest = d[i]; l = i;
		}
	}

	spfa(l);

	longest = 0;
	ra(i, 1, N + 1) {
		res[i] = d[i];
		if (d[i] > longest) {
			longest = d[i]; r = i;
		}
	}

	spfa(r);
	ra(i, 1, N + 1) {
		cout << max(res[i], d[i]) << endl;
	}

} // main
