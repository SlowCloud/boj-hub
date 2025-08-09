#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int date[22];

void check_time(int x, int y) {
	if (x < 0 || 23 < x) {
		cout << "No" << endl; return;
	}
	if (y < 0 || 59 < y) {
		cout << "No" << endl; return;
	}

	cout << "Yes" << endl;
}

void check_date(int x, int y) {
	if (x < 1 || 12 < x) {
		cout << "No" << endl; return;
	}
	if (y < 1 || date[x] < y) {
		cout << "No" << endl; return;
	}
	cout << "Yes" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fill(date, date + 22, 30);
	date[2] = 29;
	for (int month : {1, 3, 5, 7, 8, 10, 12}) {
		date[month] = 31;
	}


	int T; cin >> T;
	while (T--) {
		int x, y; cin >> x >> y;

		check_time(x, y);
		check_date(x, y);

	}

}
