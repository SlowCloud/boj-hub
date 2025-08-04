#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



constexpr int sq = 400;
constexpr int sz = 1'111'111;
constexpr int bucket_sz = sz / sq;

struct Query {
	int i, l, r;
	bool operator < (const Query& q) const {
		if (l / sq != q.l / sq) return l < q.l;
		return r < q.r;
	}
};
vector<Query> qs;

int bucket[bucket_sz]; // cnt의 sqrt
int cnt[sz]; // 합이 0인 누적합의 길이의 개수

list<int> dq[sz]; // 각 누적합별 인덱스를 저장하는 덱
int A[sz]; // 누적합
int res[sz]; // 결과

void add(int idx, bool left) {
	auto& q = dq[A[idx]];
	if (q.size()) {
		int now = q.back() - q.front();
		cnt[now]--; bucket[now / sq]--;
	}
	if (left) q.push_front(idx);
	else q.push_back(idx);
	int now = q.back() - q.front();
	cnt[now]++; bucket[now / sq]++;
}

void sub(int idx, bool left) {
	auto& q = dq[A[idx]];
	int now = q.back() - q.front();
	cnt[now]--; bucket[now / sq]--;
	if (left) q.pop_front();
	else q.pop_back();
	if (q.size()) {
		int now = q.back() - q.front();
		cnt[now]++; bucket[now / sq]++;
	}
}

int query() {

	for (int i = bucket_sz - 1; i >= 0; i--) {
		if (bucket[i] == 0) continue;
		for (int j = sq - 1; j >= 0; j--) {
			if (i * sq + j >= sz) continue; // 크기 건너뜀;
			if (cnt[i * sq + j]) return i * sq + j;
		}
	}
	return 0;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] += A[i - 1]; A[i] %= K;
		A[i] += K; A[i] %= K;
	}

	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int a, b; cin >> a >> b;
		qs.push_back({ i,a - 1,b });
	}
	sort(all(qs));

	int l, r;
	l = qs[0].l; r = qs[0].r;
	FOR(i, l, r + 1) add(i, 0);
	res[qs[0].i] = query();

	FOR(i, 1, qs.size()) {
		auto& q = qs[i];
		while (q.l < l) add(--l, 1);
		while (r < q.r) add(++r, 0);
		while (l < q.l) sub(l++, 1);
		while (q.r < r) sub(r--, 0);
		res[q.i] = query();
	}

	FOR(i, 0, Q) cout << res[i] << ' ';

}
