#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int cnt1[33], cnt2[33];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a, b;
	// while (cin >> a >> b) { // 이거 안되나 보네
	while (getline(cin, a) && getline(cin, b)) {

		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		for (char c : a) cnt1[c - 'a']++;
		for (char c : b) cnt2[c - 'a']++;

		for (char c = 'a'; c <= 'z'; c++) {
			int cnt = min(cnt1[c - 'a'], cnt2[c - 'a']);
			while (cnt--) {
				cout << c;
			}
		}
		cout << endl;

	}

}
