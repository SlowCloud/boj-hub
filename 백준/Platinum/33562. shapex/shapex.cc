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


struct Piece {
	char type = '-';
	char color = '-';
	Piece() {}
	Piece(const string& s) {
		type = s[0];
		color = s[1];
	}
	Piece(char t, char c) {
		type = t; color = c;
	}
	string build() {
		return string(1, type).append(string(1, color));
	}
	bool empty() {
		return type == '-';
	}
	Piece coloring(char c) {
		if (type == '-') return { '-','-' };
		return { type, c };
	}
};

struct Board {
	vector<Piece> pieces;
	Board(const string& s) {
		FOR(i, 0, 4) {
			pieces.push_back(s.substr(i * 2, 2));
		}
	}
	Board(vector<Piece> p) {
		pieces = p;
	}
	string build() {
		string res = "";
		FOR(i, 0, 4) {
			res.append(pieces[i].build());
		}
		return res;
	}
	Board left() {
		vector<Piece> ps = { Piece(), Piece(), pieces[2], pieces[3] };
		return Board(ps);
	}
	Board right() {
		vector<Piece> ps = { pieces[0], pieces[1], Piece(), Piece() };
		return Board(ps);
	}
	bool empty() {
		int cnt = 0;
		for (Piece& p : pieces) cnt += p.empty();
		return cnt == 4;
	}
	Board rotate(int n) {
		vector<Piece> p;
		FOR(i, 0, 4) {
			p.push_back(pieces[(i - n + 4) % 4]);
		}
		return Board(p);
	}
	Board color(char c) {
		vector<Piece> ps;
		for (Piece& piece : pieces) {
			ps.push_back(piece.coloring(c));
		}
		return ps;
	}

	// danger!
	void sum(Board& b) {
		FOR(i, 0, 4) {
			if (pieces[i].empty()) {
				pieces[i] = b.pieces[i];
				b.pieces[i] = Piece();
			}
		}
	}

	bool fit(Board& b) {
		FOR(i, 0, 4) {
			if (!pieces[i].empty() && !b.pieces[i].empty()) return false;
		}
		return true;
	}
};

struct Node {
	vector<Board> boards;
	Node() {
	}
	Node(const string& s) {
		stringstream sstream(s);
		string line;
		while (getline(sstream, line, ':')) {
			boards.push_back(Board(line));
		}
	}
	Node(vector<Board> b) {
		boards = b;
	}
	string build() {
		if (empty()) {
			return "None";
		}
		string res = "";
		for (Board& b : boards) {
			res.append(b.build()).append(":");
		}
		res.pop_back();
		return res;
	}
	vector<Node> slice() {
		vector<Board> l, r;
		for (Board& b : boards) {
			auto ltmp = b.left();
			if (!ltmp.empty()) l.push_back(ltmp);

			auto rtmp = b.right();
			if (!rtmp.empty()) r.push_back(rtmp);
		}
		Node a(l), b(r);
		return { a,b };
	}
	Node rotate(int n) {
		vector<Board> tmp;
		for (Board& b : boards) {
			tmp.push_back(b.rotate(n));
		}
		return Node(tmp);
	}
	Node sum(Node n) {
		vector<Board> bs = boards;
		vector<Board> nbs = n.boards;

		// 여기 버그 분명 있을 것 같은데

		// 겹칠 칸 개수
		int idx = 0;
		while (true) {
			bool check = true;
			// 켭칠 칸을 하나 더 늘렸을 때 알맞게 들어가는지 확인
			FOR(i, 0, nbs.size()) {
				if (-idx - 1 + i >= 0) break;
				if (!bs.at(bs.size() - idx - 1 + i).fit(nbs[i])) {
					check = false; break;
				}
			}
			// 가능하다면 한칸 더 늘림
			if (check) idx++;
			else break;
			// 모든 칸이 겹치면 여기서 멈춤
			if (idx >= bs.size()) break;
		}
		// idx가 nbs보다 커질 수 있음. 여기서 터진듯
		FOR(i, 0, min(idx, (int)nbs.size())) {
			bs.at(bs.size() - idx + i).sum(nbs[i]);
		}
		FOR(i, idx, nbs.size()) {
			bs.push_back(nbs[i]);
		}
		while (bs.size() > 4) {
			bs.pop_back();
		}
		return Node(bs);
	}
	Node color(char c) {
		vector<Board> bs;
		for (auto& b : boards) {
			bs.push_back(b.color(c));
		}
		return Node(bs);
	}
	bool empty() {
		return boards.empty();
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	vector<Node> nodes(101);

	FOR(i, 1, N + 1) {
		string s; cin >> s;
		nodes[i] = Node(s);
	}

	while (M--) {
		int op; cin >> op;
		if (op == 1) {
			int i, j, k; cin >> i >> j >> k;
			if (nodes[i].empty()) {
				nodes[j] = nodes[k] = Node();
				continue;
			}
			vector<Node> sliced = nodes[i].slice();
			nodes[j] = sliced[0];
			nodes[k] = sliced[1];
		}
		else if (op == 2) {
			int i, j, k; cin >> i >> j >> k;
			if (nodes[i].empty()) {
				nodes[j] = Node(); continue;
			}
			nodes[j] = nodes[i].rotate(k);
		}
		else if(op == 3) {
			int i, j, k; cin >> i >> j >> k;
			if (nodes[i].empty() || nodes[j].empty()) {
				nodes[k] = Node(); continue;
			}
			nodes[k] = nodes[i].sum(nodes[j]);
		}
		else {
			int i, j; char k; cin >> i >> j >> k;
			if (nodes[i].empty()) {
				nodes[j] = Node(); continue;
			}
			nodes[j] = nodes[i].color(k);
		}
	}

	cout << nodes[100].build();

}

