#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i,a,b) for(auto i=a;i<b;i++)
#define endl '\n'


int vst[2222];
int dp[2222];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	queue<int> q; q.push(0); vst[0] = 1;
	while(q.size()) {
		int now = q.front(); q.pop();
		for(int next : vector<int>{now - 4, now + 9, now + 14, now + 18}) {
			if(next < 0 || next >= 2222) continue;
			if(vst[next]) continue;
			vst[next] = 1;
			q.push(next);
			dp[next] = dp[now] + 1;
		}
	}

	string s; cin >> s;
	string l, r;
	bool flag = false;
	FOR(i,0,s.size()) {
		char c = s[i];
		if(c == '.') {
			flag = true; continue;
		}
		(flag?r:l).push_back(c);
	}

	ll target = 0;

	if(r.size()) {
		if(r != "0") {
			if(r != "5") {
				cout << -1; exit(0);
			}
			target++;
		}
	}
	target += stoll(l) * 2;

	ll res = 0;

	if(target > 2000) {
		ll tmp = target - 2000;
		res += tmp / 18;
		tmp -= tmp % 18;
		target -= tmp;
	}

	cout << res + dp[target] << endl;

}
