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

vector<int> G[500'001];
int deg[500'001], stop[500'001], vst[500'001];

int main() {
	FAST;

	int N; cin >> N;

	ra(i, 1, N) {
		int u, v; get2(u, v);
		G[u].push_back(v); G[v].push_back(u);
		deg[u]++; deg[v]++;
	}


	ra(t, 0, 2) {

		// 차수가 1인 정점 체크
		queue<int> q;
		ra(i, 1, N + 1) {
			stop[i] = deg[i] > 2; // 다음 레벨이 될 점에서 정지
			if (deg[i] == 1) {
				q.push(i); vst[i] = 1; deg[i]--;
			}
		}

		// 차수 2인 정점 연속체크
		while (q.size()) {
			int now = q.front(); q.pop();
			for (int next : G[now]) {
				deg[next]--;
				if (vst[next] || deg[next] > 1 || stop[next]) continue;
				deg[next]--;
				q.push(next); vst[next] = 1;
			}
		}

	}

	ra(i, 1, N + 1) if (deg[i] >= 3) {
		cout << "NO"; return 0;
	}
	cout << "YES";

} // main
