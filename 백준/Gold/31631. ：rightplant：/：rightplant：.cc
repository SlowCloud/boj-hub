#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int calc(const vector<int>& v) {

	int res = 0;
	FOR(i, 0, v.size()) {
		vector<int> cp = v;

		int d = 1;
		int score = 0;
		int idx = i;
		int height = v[i];

		while (1) {
			idx += d;
			if (idx < 0 || idx >= v.size()) break;
			if (cp[idx] > height) {
				cp[idx]--; score++; d *= -1;
			}
		}

		res += score;

	}

	return res;
}

void test(int N) {
	vector<int> v(N);
	iota(all(v), 1);

	int score = 0;
	vector<vector<int>> arrs;
	do {
		int now = calc(v);
		if (now > score) {
			score = now;
			arrs = { v };
		}
		else if (now == score) {
			arrs.push_back(v);
		}
	} while (next_permutation(all(v)));

	cout << score << endl;
	for (auto& arr : arrs) {
		for (auto& i : arr) cout << i << ' '; cout << endl;
	}
	cout << "------" << endl;

}

/*

N이 홀수라면 왼쪽으로 2번 오른쪽으로 2번 넣으면 된다.
N이 짝수라면 1을 넣고 진행하면 된다.

큰 수가 오른쪽으로 나오도록 출력하면 끝.

*/

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N; cin >> N;

	deque<int> dq;

	int d = 1;
	int cnt = 2;

	if (N % 2 == 0) {
		dq.push_back(1);
	}

	FOR(i, 1 + !(N % 2), N + 1) {
		if (d) dq.push_front(i);
		else dq.push_back(i);
		cnt--;
		if (cnt == 0) {
			cnt = 2; d ^= 1;
		}
	}

	if (dq.front() < dq.back()) {
		while (dq.size()) {
			cout << dq.front() << ' '; dq.pop_front();
		}
	}
	else {
		while (dq.size()) {
			cout << dq.back() << ' '; dq.pop_back();
		}
	}

}

