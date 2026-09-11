#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: 1D range increment and sum query.
 * Source: USACO Counting Haybales
 	* https://codeforces.com/blog/entry/82400
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
// #pragma once

template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be power of 2
	const T ID1; T (*cmb)(T a, T b);
	vector<T> seg; vector<U> lazy;
	void (*push)(int,int,int,vector<T>&,vector<U>&) = 
		[&](int ind,int L,int R,vector<T>&seg,vector<U>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	}; // recalc values for current node
	LazySeg(T id1, U id2, T _cmb(T, T), void _push(int,int,int,vector<T>&,vector<U>&)):
		ID1(id1),cmb(_cmb),push(_push),seg(2*SZ,id1),lazy(2*SZ,id2){}
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,U inc,int ind=1,int L=0, int R=SZ-1) {
		push(ind,L,R,seg,lazy); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R,seg,lazy); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
		push(ind,L,R,seg,lazy); if (lo > R || L > hi) return ID1;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
	int find_max(int ind = 1, int L = 0, int R = SZ - 1) {
		push(ind, L, R, seg, lazy);
		if (L == R) {
			return L;
		}
		int M = (L + R) / 2;
		if (seg[2 * ind] + lazy[2 * ind] > seg[2 * ind + 1] + lazy[2 * ind + 1]) {
			return find_max(2 * ind, L, M);
		}
		return find_max(2 * ind + 1, M + 1, R);
	}
	int first_at_least(int k, int i, int ind = 1, int L = 0, int R = SZ - 1) {
		push(ind, L, R, seg, lazy);
		if (seg[ind] < k or R < i) {
			return -1;
		}
		if (L == R) {
			return L;
		}
		int M = (L + R) / 2;
		int x = first_at_least(k, i, 2 * ind, L, M);
		if (x != -1) {
			return x;
		}
		return first_at_least(k, i, 2 * ind + 1, M + 1, R);
	}
	int last_at_least(int k, int i, int ind = 1, int L = 0, int R = SZ - 1) {
		push(ind, L, R, seg, lazy);
		if (seg[ind] < k or L > i) {
			return -1;
		}
		if (L == R) {
			return L;
		}
		int M = (L + R) / 2;
		int x = last_at_least(k, i, 2 * ind + 1, M + 1, R);
		if (x != -1) {
			return x;
		}
		return last_at_least(k, i, 2 * ind, L, M);
	}
};

void solve() {
    int n, q;
	cin >> n >> q;

	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}

	int z = accumulate(all(a), 0ll);
	LazySeg<int, int, 1 << 18> seg(0, 0, [](int a, int b) {
		return max(a, b);
	}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
		/// modify values for current node
		seg[ind] += lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	});
	rep(i, 0, n) {
		seg.seg[i + (1 << 18)] = a[i];
	}
	seg.build();

	LazySeg<int, int, 1 << 18> pref(0, 0, [](int a, int b) {
		return a + b;
	}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	});
	int p = 0;
	rep(i, 0, n) {
		p = max(p, a[i]);
		pref.seg[i + (1 << 18)] = p;
	}
	pref.build();

	LazySeg<int, int, 1 << 18> suff(0, 0, [](int a, int b) {
		return a + b;
	}, [](int ind,int L,int R,vector<int>&seg,vector<int>&lazy) {
		/// modify values for current node
		seg[ind] += (R-L+1)*lazy[ind]; // dependent on operation
		if (L != R) {lazy[2*ind] += lazy[ind]; lazy[2*ind+1] += lazy[ind];}
		lazy[ind] = 0; /// prop to children
	});
	int s = 0;
	for (int i = n - 1; i >= 0; i--) {
		s = max(s, a[i]);
		suff.seg[i + (1 << 18)] = s;
	}
	suff.build();

	int i = seg.find_max();
	cout << pref.query(0, i) + suff.query(i + 1, n - 1) - z << endl;

	while (q--) {
		int l, r;
		cin >> l >> r;

		l--;
		r--;
		z += r - l + 1;
		
		int p = seg.first_at_least(pref.query(l, l), l);
		int q = seg.first_at_least(pref.query(r, r) + 1, r + 1);
		if (p != -1 and p <= r) {
			if (q == -1) {
				q = n - 1;
			}
			else {
				q--;
			}
			// cout << p << ' ' << q << endl;
			pref.upd(p, q, 1);
		}
		
		p = seg.last_at_least(suff.query(r, r), r);
		q = seg.last_at_least(suff.query(l, l) + 1, l - 1);
		if (p != -1 and p >= l) {
			if (q == -1) {
				q = 0;
			}
			else {
				q++;
			}
			suff.upd(q, p, 1);
		}
		seg.upd(l, r, 1);
		
		int i = seg.find_max();
		// cout << i << 'd' << endl;
		// cout << pref.query(0, i) << endl;
		cout << pref.query(0, i) + suff.query(i + 1, n - 1) - z << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
