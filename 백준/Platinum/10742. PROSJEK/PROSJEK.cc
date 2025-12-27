#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR_(type,i, a, b) for(type i=a;i<b;i++)
#define FOR(i,a,b) FOR_(int,i,a,b)
#define FORLL(i,a,b) FOR_(ll,i,a,b)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

constexpr auto endl = '\n';

// https://dmoj.ca/problem/coci14c7p5/editorial
// 에디토리얼을 읽고 풀이하였음

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K; cin >> N >> K;
	vector<ll> v(N + 1);
	FOR(i, 1, N + 1) {
		cin >> v[i];
		v[i] *= 1e7;
		v[i] += v[i - 1];
	}

	ll l = 1e7, r = 1e13, m;
	while (l <= r) {
		m = l + r >> 1;

		ll left = 0;
		bool possible = false;
		FORLL(i, K, N + 1) {
			left = min(left, v[i - K] - m * (i - K));
			ll right = v[i] - m * i;
			if (right >= left) {
				possible = true; break;
			}
		}

		if(possible) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}

	}

	cout << (r / 10'000'000) << '.' << setfill('0') << setw(7) << (r % 10'000'000);


}
