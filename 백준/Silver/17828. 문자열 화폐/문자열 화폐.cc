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

	int N, X; cin >> N >> X;

	if (N > X || N * 26 < X) {
		cout << '!'; exit(0);
	}

	vector<int> v;
	int tmp = X - N;
	while (tmp > 0) {
		if (tmp / 25) v.push_back(25);
		else v.push_back(tmp);
		tmp -= v.back();
	}

	v.resize(N);

	for (auto i = v.crbegin(); i != v.crend(); i++) {
		char c = *i + 'A';
		cout << c;
	}

}
