#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define FOR(i,a,b) for(auto i=a;i<b;i++)


int vst[2'222'222];
ll cnt[2'222'222];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll a,b; cin >>a>>b;

	queue<ll> q; q.push(a);
	vst[a]= 1;
	while(q.size()) {
		ll now = q.front(); q.pop();
		for(ll next : vector<ll>{now + 1, now * 2}) {
			if(next >= 2'222'222) continue;
			if(vst[next]) continue;
			vst[next] = 1;
			cnt[next] = cnt[now] + 1;
			q.push(next);
		}
	}

	cout << cnt[b];

}
