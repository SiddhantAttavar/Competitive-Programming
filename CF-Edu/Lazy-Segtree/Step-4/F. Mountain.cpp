#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

class SparseSegtree {
  private:
	struct Node {
		pair<int, int> seg = {0, 0};
		int lazy = 1e18;
		int left = -1;
		int right = -1;
	};
	vector<Node> tree;
	const int n;
	int timer = 0;

	pair<int, int> comb(pair<int, int> a, pair<int, int> b) {
		return {a.first + b.first, max(a.second, a.first + b.second)};
	}

	void push(int cur, int l, int r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(Node());
		}
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(Node());
		}

		if (tree[cur].lazy == 1e18) {
			return;
		}

		tree[cur].seg = {(r - l + 1) * tree[cur].lazy, max(0ll, (r - l + 1) * tree[cur].lazy)};

		if (l == r) {
			tree[cur].lazy = 1e18;
			return;
		}

		tree[tree[cur].left].lazy = tree[cur].lazy;
		tree[tree[cur].right].lazy = tree[cur].lazy;
		tree[cur].lazy = 1e18;
	}

	void update(int cur, int l, int r, int ql, int qr, int val) {
		push(cur, l, r);
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			tree[cur].lazy = val;
			push(cur, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(tree[cur].left, l, m, ql, qr, val);
		update(tree[cur].right, m + 1, r, ql, qr, val);
		tree[cur].seg = comb(tree[tree[cur].left].seg, tree[tree[cur].right].seg);
	}

	int query(int cur, int l, int r, int h) {
		push(cur, l, r);
		if (tree[cur].seg.second <= h) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		int x = query(tree[cur].left, l, m, h);
		if (x != -1) {
			return x;
		}
		return query(tree[cur].right, m + 1, r, h - tree[tree[cur].left].seg.first);
	}

  public:
	SparseSegtree(int n, int q = 0) : n(n) {
		if (q > 0) { tree.reserve(2 * q * __lg(n)); }
		tree.push_back(Node());
	}

	void update(int ql, int qr, int val) { update(0, 0, n - 1, ql, qr, val); }

	int query(int h) { return query(0, 0, n - 1, h); }
};

int32_t main() {
	setup();

	int n;
	input(n);

	SparseSegtree s(1e9 + 10);
	s.update(n, n, 1e16);

	while (true) {
		char c;
		input(c);

		if (c == 'I') {
			int a, b, d;
			input(a, b, d);
			s.update(a - 1, b - 1, d);
		}
		else if (c == 'Q') {
			int h;
			input(h);
			int x = s.query(h);
			assert(x != -1);
			print(x);
		}
		else {
			break;
		}
	}
}
