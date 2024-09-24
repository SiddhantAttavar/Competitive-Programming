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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

template<class T> struct SegTree { // cmb(ID,b) = b
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
	int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
		if (r < lo || val > seg[ind]) return -1;
		if (l == r) return l;
		int m = (l+r)/2;
		int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
		return first_at_least(lo,val,2*ind+1,m+1,r);
	}
};

int checker(vector<int> a) {
	int res = 0;
	range(i, 0, 1 << a.size()) {
		vector<int> v;
		range(j, 0, a.size()) {
			if ((1 << j) & i) {
				v.push_back(a[j]);
			}
		}

		if (v.size() % 2) {
			continue;
		}

		range(j, 0, 1 << v.size()) {
			vector<int> x, y;
			range(k, 0, v.size()) {
				if ((1 << k) & j) {
					x.push_back(v[k]);
				}
				else {
					y.push_back(v[k]);
				}
			}
			res += x == y;
		}
	}
	return res - 1;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		// int n = rng() % 5;
		
		vector<int> a(2 * n);
		arrPut(a);
		// vector<int> a(2 * n);
		// range(i, 0, n) {
		// 	a[2 * i] = i + 1;
		// 	a[2 * i + 1] = i + 1;
		// }
		// shuffle(a.begin(), a.end(), rng);

		SegTree<int> s(2 * n, 0, [](int x, int y) {
			return (x + y) % MOD;
		});

		vector<int> v(n, -1), res(n, 0);
		range(i, 0, 2 * n) {
			a[i]--;
			if (v[a[i]] == -1) {
				v[a[i]] = i;
				res[a[i]] = s.query(0, i);
			}
			else {
				res[a[i]] = (res[a[i]] + s.query(0, v[a[i]]) + 2) % MOD;
				s.upd(v[a[i]], res[a[i]]);
			}
		}

		print(s.query(0, 2 * n - 1));
	}
}
