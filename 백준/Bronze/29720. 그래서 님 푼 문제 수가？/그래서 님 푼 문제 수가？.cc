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



int main() {
	FAST;

	int N, M, K; get3(N, M, K);

	int mn = N - M * K;
	prt2(max(mn, 0), mn + M - 1);

} // main
