#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define FOR(i,a,b) for(auto i=a;i<b;i++)



int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll x1,y1,r1; cin >> x1>>y1>>r1;
	ll x2,y2,r2; cin >> x2>>y2>>r2;

	ll x = x1-x2;
	ll y = y1-y2;
	ll r = r1+r2;

	cout << (r*r > x*x + y*y? "YES":"NO");

}
