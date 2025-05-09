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

int convert(const string& s) {
	assert(s.size() == 2);
	int c = s[0] - 'A';
	int r = s[1] - '1';
	return (r + c) & 1;
}

int convert(int n) {
	n--;
	int r = n / 8;
	int c = n % 8;
	return (r + c) & 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int n; cin >> n;
		cout << (convert(s) == convert(n) ? "YES" : "NO") << endl;
	}

}

