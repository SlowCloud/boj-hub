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



int dp[60 * 48];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) {
		int n; cin >> n;
		string s; cin >> s;

		int min = stoi(s.substr(0, 2));
		int sec = stoi(s.substr(3, 2));

		sec += min * 60;
		dp[sec] += n == 1 ? -1 : 1;

	}

	FOR(i, 1, 60 * 48) {
		dp[i] += dp[i - 1];
	}

	int a, b; a = b = 0;
	for (auto& i : dp) {
		a += i < 0;
		b += 0 < i;
	}

	cout << setfill('0');
	cout << setw(2) << a / 60 << ':' << setw(2) << a % 60 << endl;
	cout << setw(2) << b / 60 << ':' << setw(2) << b % 60 << endl;

}

