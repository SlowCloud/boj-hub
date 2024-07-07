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


int N, M, L, K;
vector<ii> dots;

int calc(int x, int y) {
	int cnt = 0;
	for (ii& d : dots) {
		if (x <= d.first && d.first <= x + L && y <= d.second && d.second <= y + L) cnt++;
	}
	return cnt;
}

int main() {
	FAST;
	
	get4(N, M, L, K);

	ra(i, 0, K) {
		int a, b; get2(a, b);
		dots.emplace_back(a, b);
	}

	int mx = 0;
	ra(i, 0, K) {
		ra(j, 0, K) {
			mx = max(mx, calc(dots[i].first, dots[j].second));
		}
	}

	cout << K - mx;

} // main
