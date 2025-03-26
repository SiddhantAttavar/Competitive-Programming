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

template<typename T, int SZ> struct SegTree {
	vector<T> seg; T id;
	T (*cmb) (T, T);
	SegTree(T _id, T _cmb(T, T)):id(_id),seg(2*SZ,id),cmb(_cmb){}
	void build() {for (int i=SZ-1; i >= 0; i--) seg[i]=cmb(seg[2*i],seg[2*i+1]);}
	T query(int l, int r, int s=0, int e=SZ-1, int c=1) {
		if (l > e || r < s) return id;
		if (l <= s && r >= e) return seg[c];
		int mid = (s + e) / 2;
		return cmb(query(l,r, s, mid, 2*c),
			query(l, r, mid + 1, e, 2*c+1));
	}
	void update(int i, T x, int s=0, int e=SZ-1, int c=1) {
		if (s > i || e < i) return;
		if (s == e) {seg[c] = x; return;}
		int mid = (s + e) / 2;
		update(i, x, s, mid, 2*c);
		update(i, x, mid + 1, e, 2*c+1);
		seg[c] = cmb(seg[2*c], seg[2*c+1]);
	}
	int find(int i, int s = 0, int e = SZ - 1, int c = 1) {
		// print(s, e, i);
		if (s > i or seg[c] == 0) {
			return -1;
		}
		if (s == e) {
			return s;
		}
		int m = (s + e) / 2;
		int x = find(i, m + 1, e, 2 * c + 1);
		if (x != -1) {
			return x;
		}
		return find(i, s, m, 2 * c);
	}
};

SegTree<int, 1 << 18> s(0, [](int a, int b) {
	return a + b;
});

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		rep(i, 0, n) {
			int t = min(a[i], b[i]);
			a[i] -= t;
			b[i] -= t;
		}

		rep(i, 0, n) {
			s.update(i, a[i]);
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		rep(i, 0, n) {
			if (!b[i]) {
				continue;
			}

			int k = s.find(i);
			if (k == -1) {
				k = s.find(n - 1);
			}
			if (k != -1) {
				pq.push({(i - k + n) % n, k});
			}
		}

		int res = 1;
		while (s.find(n - 1) != -1) {
			int x, i;
			tie(x, i) = pq.top();
			pq.pop();

			int j = (i + x) % n;
			int t = min(a[i], b[j]);
			if (a[i]) {
				res = max(res, x + 1);
			}
			a[i] -= t;
			s.update(i, a[i]);
			b[j] -= t;
			if (!b[j]) {
				continue;
			}

			int k = s.find(i);
			if (k == -1) {
				k = s.find(n - 1);
			}
			if (k != -1) {
				pq.push({(j - k + n) % n, k});
			}
		}

		print(res);

		rep(i, 0, n) {
			s.update(i, 0);
		}
	}
}
