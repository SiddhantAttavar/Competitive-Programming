/* #include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		v[i] = {a[i], i};
	}
	sort(v.begin(), v.end());

	vector<int> x(n);
	rep(i, 0, n) {
		x[v[i].second] = i;
	}

	SegTree<pair<int, int>> s(n, {0, 0}, [](pair<int, int> a, pair<int, int> b) {
		return make_pair(a.first + b.first, a.second + b.second);
	});

	__int128_t res = 0, z = 0;
	rep(i, 0, n) {
		int j = lower_bound(v.begin(), v.end(), make_pair(a[i] - 1, 0ll)) - v.begin();
		int k = lower_bound(v.begin(), v.end(), make_pair(a[i] + 1, (int) 1e9)) - v.begin() - 1;
		res += i * a[i] - z;
		if (j <= k) {
			pair<int, int> p = s.query(j, k);
			res -= p.second * a[i] - p.first;
		}
		s.upd(x[i], {a[i], 1});
		z += a[i];
	}

	print(res);
} */

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

struct Node {
	pair<int, int> x;
	Node *l, *r;
	Node(pair<int, int> _x) : x(_x), l(nullptr), r(nullptr) {}
	Node(Node* _l, Node* _r) : l(_l), r(_r) {
		x = {0, 0};
		if(l) x.first += l->x.first, x.second += l->x.second;
		if(r) x.first += r->x.first, x.second += r->x.second;
	}
	Node(Node *v) : x(v->x), l(v->l), r(v->r) {}
};
const int N = 1e9;
Node* root;
Node* update(Node* node, int l, int r, int pos, pair<int, int> val) {
	if (node == NULL) node = new Node(make_pair(0, 0));
	if(l == r) return new Node(val);
	int m = (l + r)/2;
	if(pos <= m) return new Node(update(node->l, l, m, pos, val),
			node->r);
	return new Node(node->l, update(node->r, m + 1, r, pos, val));
}
pair<int, int> cmb(pair<int, int> a, pair<int, int> b) {
	return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> query(Node* node, int l, int r, int ql, int qr) {
	if(node == NULL || qr < l || ql > r) return {0, 0};
	if(ql <= l && qr >= r) return node->x;
	int m = (l + r)/2;
	return cmb(query(node->l, l, m, ql, qr), query(node->r, m + 1, r, ql, qr));
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int32_t main() {
	setup();
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	root = new Node(make_pair(0, 0));
	__int128_t res = 0, z = 0;
	map<int, int> m;
	rep(i, 0, n) {
		res += i * a[i] - z;
		pair<int, int> p = query(root, 1, 1e9, a[i] - 1, a[i] + 1);
		res -= p.second * a[i] - p.first;
		m[a[i]]++;
		root = update(root, 1, 1e9 , a[i], {a[i] * m[a[i]], m[a[i]]});
		z += a[i];
	}

	print(res);
}
