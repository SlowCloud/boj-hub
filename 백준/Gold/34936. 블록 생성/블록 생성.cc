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

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Transaction {
	int start;
	int fee;
	bool operator<(const Transaction& other) const {
		if (fee != other.fee) {
			return fee > other.fee;
		}
		else return start < other.start;
	}
	bool operator > (const Transaction& other) const {
		return other < *this;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	priority_queue<Transaction, vector<Transaction>, greater<>> pq;

	int N, T, K;
	cin >> N >> T >> K;

	ll res = 0;
	FOR(i,0,N) {
		int op; cin >> op;
		if (op == 1) {
			int s, f; cin >> s >> f;
			pq.push({ s, f });
		}
		else {
			int t; cin >> t;
			vector<Transaction> temp;
			while (pq.size() && temp.size() < K) {
				Transaction tr = pq.top(); pq.pop();
				if (t - tr.start > T) {
					continue;
				}
				else {
					temp.push_back(tr);
				}
			}
			for (const auto& tr : temp) {
				res += tr.fee;
			}
		}
	}
	cout << res;


}
