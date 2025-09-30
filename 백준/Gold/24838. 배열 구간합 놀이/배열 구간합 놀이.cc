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


constexpr ll MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {

		int N, M; cin >> N >> M;

		vector<ll> A(N);
		for (auto& i : A) cin >> i;

		vector<pll> xy(M);
		for (auto& p : xy) cin >> p.first >> p.second, p.first--, p.second--;

		vector<int> cnt(N + 1);
		for (const auto& p : xy) {
			cnt[p.first]++;
			cnt[p.second + 1]--;
		}

		FOR(i, 1, cnt.size()) {
			cnt[i] += cnt[i - 1];
		}

		vector<ll> v;
		FOR(i, 0, cnt.size() - 1) {
			v.push_back(cnt[i]);
		}
		sort(rall(v));

		ll maximum = 0;
		sort(rall(A));
		FOR(i, 0, A.size()) {
			maximum += A[i] * v[i];
		}

		map<int, int> cntcnt;
		for (const auto& i : v) cntcnt[i]++;

		ll possibles = 1;
		for (const auto& p : cntcnt) {
			ll n = p.second;
			do {
				possibles *= n;
				possibles %= MOD;
			} while (--n);
		}

		cout << maximum << ' ' << possibles << endl;

	}

}
