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



int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N, K; cin >> N >> K;

	int now = 0;
	int s = -1, e = -1;
	FOR(i, 1, N + 1) {
		int n; cin >> n;
		if ((n | K) == K) {
			now |= n;
			if (s == -1) s = i;
			if (now == K) {
				cout << s << ' ' << i; exit(0);
			}
		}
		else {
			now = 0;
			s = -1;
		}
	}
	
	cout << -1;

}
