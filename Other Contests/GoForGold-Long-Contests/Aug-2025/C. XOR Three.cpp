#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void insert(int x, vector<pair<int, int>> &tree, vector<int> &s) {
	int u = 0;
	for (int i = 19; i >= 0; i--) {
		s[u]++;
		if (x >> i & 1) {
			if (tree[u].second == -1) {
				tree[u].second = tree.size();
				tree.push_back({-1, -1});
				s.push_back(0);
			}
			u = tree[u].second;
		}
		else {
			if (tree[u].first == -1) {
				tree[u].first = tree.size();
				tree.push_back({-1, -1});
				s.push_back(0);
			}
			u = tree[u].first;
		}
	}
	s[u]++;
}

void erase(int x, vector<pair<int, int>> &tree, vector<int> &s) {
	int u = 0;
	for (int i = 19; i >= 0; i--) {
		s[u]--;
		if (x >> i & 1) {
			u = tree[u].second;
		}
		else {
			u = tree[u].first;
		}
	}
	s[u]--;
}

int get(int x, int y, vector<pair<int, int>> &tree, vector<int> &s) {
	int u = 0, res = 0;
	for (int i = 19; i >= 0; i--) {
		if (x >> i & 1) {
			if (y >> i & 1) {
				if (tree[u].second != -1) {
					res += s[tree[u].second];
				}
				u = tree[u].first;
			}
			else {
				u = tree[u].second;
			}
		}
		else {
			if (y >> i & 1) {
				if (tree[u].first != -1) {
					res += s[tree[u].first];
				}
				u = tree[u].second;
			}
			else {
				u = tree[u].first;
			}
		}

		if (u == -1) {
			break;
		}
	}
	if (u != -1) {
		res += s[u];
	}
	return res;
}

int brute(int m, int n) {
	int res = 0;
	rep(i, 0, 1 << (n - m + 1)) {
		vector<int> v;
		rep(j, 0, n - m + 1) {
			if (i >> j & 1) {
				v.push_back(j + m);
			}
		}
		set<int> s(v.begin(), v.end());
		bool flag = true;
		rep(l, 0, v.size()) {
			rep(r, l + 1, v.size()) {
				if (s.count(v[l] ^ v[r])) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			res = max(res, (int) __builtin_popcount(i));
		}
	}
	return res;
}

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

int32_t main() {
	const int N = 1e6;
	vector<pair<int, int>> tree = {{-1, -1}};
	vector<int> s = {0};
	vector<pair<int, int>> a;
	int l = 1;
	rep(i, 1, N + 1) {
		insert(i, tree, s);
		while (get(i, i, tree, s) != get(i, l - 1, tree, s)) {
			erase(l, tree, s);
			l++;
		}
		a.push_back({l, i});
	}

	vector<pair<pair<int, int>, int>> q;
	setup();
	int t; input(t);
	rep(i, 0, t) {
		int l, r;
		input(l, r);
		q.push_back({{l, r}, i});
	}

	vector<int> res(t, 0);
	sort(q.begin(), q.end());
	int j = 0, k = 0;
	SegTree<int> x(N + 1, 0, [](int a, int b) {
		return max(a, b);
	});
	rep(i, 1, N + 1) {
		while (j < q.size() and q[j].first.first == i) {
			res[q[j].second] = max(res[q[j].second], x.query(q[j].first.first, q[j].first.second) - q[j].first.first + 1);
			j++;
		}
		while (k < a.size() and a[k].first == i) {
			x.upd(a[k].second, a[k].second);
			k++;
		}
	}

	rep(i, 0, N + 1) {
		x.upd(i, 0);
	}
	sort(q.begin(), q.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.first.second < b.first.second;
	});
	sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	});
	j = 0, k = 0;
	rep(i, 1, N + 1) {
		while (k < a.size() and a[k].second == i) {
			x.upd(a[k].first, a[k].second - a[k].first + 1);
			k++;
		}
		while (j < q.size() and q[j].first.second == i) {
			res[q[j].second] = max(res[q[j].second], x.query(q[j].first.first, q[j].first.second));
			j++;
		}
	}

	for (int i : res) {
		print(i);
	}
}

