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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define compress(v) v.erase(unique(all(v)), v.end())
#define For(i,a,b) for(int i=a;i<b;i++)
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
#define nx(x,i) x + "1102"[i] - '1'
#define ny(y,i) y + "0211"[i] - '1'

vll seg(1 << 18);

void add(int i, int v, int n = 1, int s = 0, int e = 1 << 16) {
	if (i < s || e < i) return;
	if (s == e) {
		seg[n] += v; return;
	}

	int m = s + e >> 1;

	add(i, v, n << 1, s, m);
	add(i, v, n << 1 | 1, m + 1, e);

	seg[n] = seg[n << 1] + seg[n << 1 | 1];
}

int query(int rest, int n = 1, int s = 0, int e = 1 << 16) {
	if (s == e) {
		return s;
	}
	int m = s + e >> 1;
	if (seg[n << 1] >= rest) return query(rest, n << 1, s, m);
	else return query(rest - seg[n << 1], n << 1 | 1, m + 1, e);
}

int main() {
	FAST;
	
	int N, K; get2(N, K);

	queue<int> q;
	ll res = 0;
	For(i, 1, K) {
		ll n; cin >> n; q.push(n);
		add(n, 1);
	}
	For(i, K, N + 1) {
		ll n; cin >> n;
		add(n, 1);
		res += query((K + 1) / 2);
		q.push(n);
		add(q.front(), -1); q.pop();
	}

	cout << res;

} // main
