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

	regex r(".*FBI.*");
	string s;
	int cnt = 0;
	bool check = false;
	while (getline(cin, s)) {
		cnt++;
		if (regex_match(s, r)) {
			check = true;
			cout << cnt << ' ';
		}
	}

	if(!check) cout << "HE GOT AWAY!";

}
