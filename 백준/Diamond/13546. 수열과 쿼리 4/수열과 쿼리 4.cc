#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FAST cin.tie(0)->sync_with_stdio(0);
#define endl '\n'
#define INPUT freopen("input.txt", "rt", stdin)

using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i,a,b) for(int i=a;i<b;i++)
#define outside(x,y,R,C) (min(x,y) < 1 || R < x || C < y)
#define zoutside(x,y,R,C) (min(x,y) < 0 || R <= x || C <= y)
#define nx(x,i) x + "1102"[i] - '1'
#define ny(y,i) y + "0211"[i] - '1'

constexpr int sq = 300;
constexpr int sz = 111'000 / 300 + 1;

struct Query {
	int i, l, r;
	constexpr bool operator < (const Query& q) const {
		if (l / sq != q.l / sq) return l / sq < q.l / sq;
		return r < q.r;
	}
};

vector<Query> qs;

int bucket[sz]; // |x-y|의 크기 개수의 sqrt
int cnt[111'111]; // |x-y|의 크기의 개수
int arr[100'001]; // i 위치의 v
list<int> pos[100'001]; // 값 v의 인덱스 저장

void add(int i, bool left) {
	int v = arr[i];
	int now = 0;
	auto& dq = pos[v];
	if (dq.size()) {
		now = dq.back() - dq.front();
		bucket[now / sq]--; cnt[now]--;
	}
	if (left) dq.push_front(i);
	else dq.push_back(i);
	now = dq.back() - dq.front();
	bucket[now / sq]++; cnt[now]++;
}

void sub(int i, bool left) {
	int v = arr[i];
	int now = 0;
	auto& dq = pos[v];
	now = dq.back() - dq.front();
	bucket[now / sq]--; cnt[now]--;
	if (left) dq.pop_front();
	else dq.pop_back();
	if (dq.size()) {
		now = dq.back() - dq.front();
		bucket[now / sq]++; cnt[now]++;
	}
}

int res[100'001];

int query() {
	for (int i = sz - 1; i >= 0; i--) {
		if (bucket[i] == 0) continue;
		for (int j = sq - 1; j >= 0; j--) {
			if (cnt[i * sq + j]) return i * sq + j;
		}
	}
	return 0;
}

int main() {
	FAST;

	int N, K; cin >> N >> K;

	For(i, 0, N) {
		cin >> arr[i];
	}

	int M; cin >> M;
	For(i, 0, M) {
		int a, b; cin >> a >> b;
		qs.push_back({ i,a - 1,b - 1 });
	}
	sort(all(qs));

	int l, r;
	l = qs[0].l; r = qs[0].r;
	For(i, l, r + 1) add(i, 0);
	res[qs[0].i] = query();

	For(i, 1, qs.size()) {
		auto& q = qs[i];
		while (q.l < l) add(--l, 1);
		while (r < q.r) add(++r, 0);
		while (l < q.l) sub(l++, 1);
		while (q.r < r) sub(r--, 0);
		res[q.i] = query();
	}

	For(i, 0, M) cout << res[i] << ' ';

}