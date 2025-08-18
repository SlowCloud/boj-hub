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

	stack<int> mul, res;

	int cnt = 0;
	char prev = '-';
	for (char c : s) {
		if (isdigit(c)) {
			cnt++;
		}
		else {
			if (c == '(') {
				res.push(cnt - 1);
				mul.push(prev - '0');
				cnt = 0;
			}
			else {
				cnt *= mul.top(); mul.pop();
				cnt += res.top(); res.pop();
			}
		}
		prev = c;
	}

	cout << cnt;

}
