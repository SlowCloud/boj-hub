#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0);

#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Dot {
	ll first, second;
	ll p, q;
	bool operator < (Dot& d) {

		if (q * d.p != p * d.q) {
			return q * d.p < p * d.q;
		}

		if (second != d.second) return second < d.second;
		return first > d.first;
	}
};

vector<Dot> dots;
stack<int> st;
Dot root;

ll ccw(Dot& a, Dot& b, Dot& c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

int main() {
	FAST; NOTIE;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		ll a, b; cin >> a >> b;
		dots.push_back({ a,b });
	}

	// 좌하단 점부터 먼저 오도록 함.
	sort(all(dots));

	for (int i = 1; i < dots.size(); i++) {
		dots[i].p = dots[i].first - dots[0].first;
		dots[i].q = dots[i].second - dots[0].second;
	}

	sort(dots.begin() + 1, dots.end());

	st.push(0);
	st.push(1);
	for (int i = 2; i < dots.size(); i++) {

		while (st.size() >= 2) {
			int a, b;
			a = st.top(); st.pop();
			b = st.top();
			if (ccw(dots[b], dots[a], dots[i]) > 0) {
				st.push(a); break;
			}
		}

		st.push(i);
	}

	cout << st.size();

} // main