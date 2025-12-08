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

	string s; cin >> s;
	queue<int> q;
	for (const char& c : s) {
		q.push(c - '0');
	}

	int now = 1;
	do {
		for (const char& c : to_string(now)) {
			int tmp = c - '0';
			if (q.size() && tmp == q.front()) {
				q.pop();
			}
		}

		if (q.empty()) break;

		now++;

	} while (1);

	cout << now;

}
