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



int main() {

	string s; cin >> s;

	int now = 0;
	int idx = -1;
	FOR(i, 0, s.size()) {
		char c = s[i];
		if (c == '*') {
			idx = i;
		}
		else {
			int tmp = (c - '0') * (i % 2 == 0 ? 1 : 3);
			now += tmp;
		}
	}

	now = (10 - (now % 10)) % 10;
	if (idx % 2 == 0) {
		cout << now;
	}
	else {
		while (now % 3) {
			now += 10;
		}
		cout << now / 3;
	}

}

