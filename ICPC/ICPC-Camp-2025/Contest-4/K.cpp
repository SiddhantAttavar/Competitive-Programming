#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 998244353, P = 10;

template<class T, class U, int SZ> struct LazySeg { 
	// static_assert(pct(SZ) == 1); // SZ must be pwer of 2
	const T ID1;
	vector<T> seg; vector<U> lazy;
	T (*cmb)(T a, T b);
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
};

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return a * mod_pow(b, MOD - 2) % MOD;
}

LazySeg<tuple<int, int, int>, tuple<int, int, int>, 1 << 18> t({0, 0, 0}, {1, 1, 0}, [](tuple<int, int, int> a, tuple<int, int, int> b) {
    return make_tuple((get<0>(a) + get<0>(b)) % MOD, (get<1>(a) + get<1>(b)) % MOD, get<2>(a) + get<2>(b));
}, [](int ind, int L, int R, vector<tuple<int, int, int>> &seg, vector<tuple<int, int, int>> &lazy) {
    seg[ind] = {
        get<0>(seg[ind]) * get<0>(lazy[ind]) % MOD,
        get<1>(seg[ind]) * get<1>(lazy[ind]) % MOD,
        get<2>(seg[ind]) + (R - L + 1) * get<2>(lazy[ind])
    };
    if (L != R) {
        lazy[2 * ind] = {
            get<0>(lazy[2 * ind]) * get<0>(lazy[ind]) % MOD,
            get<1>(lazy[2 * ind]) * get<1>(lazy[ind]) % MOD,
            get<2>(lazy[2 * ind]) + get<2>(lazy[ind])
        };
        lazy[2 * ind + 1] = {
            get<0>(lazy[2 * ind + 1]) * get<0>(lazy[ind]) % MOD,
            get<1>(lazy[2 * ind + 1]) * get<1>(lazy[ind]) % MOD,
            get<2>(lazy[2 * ind + 1]) + get<2>(lazy[ind])
        };
    }
    lazy[ind] = {1, 1, 0};
});

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        int k = mod_pow(P, a[i]);
        t.seg[i + (1 << 18)] = {k, mod_div(1, k), a[i]};
    }
    t.build();
    
    while (q--) {
        int o, l, r;
        cin >> o >> l >> r;

        l--;
        r--;

        if (o == 1) {
            int x;
            cin >> x;
            int k = mod_pow(P, x);
            t.upd(l, r, {k, mod_div(1, k), x});
        }
        else {
            int z = r - l + 1;
            auto [a, b, x] = t.query(l, r);
            if (z % 2 or x % (z / 2)) {
                cout << "NO\n";
                continue;
            }

            x /= z / 2;
            if (a == b * mod_pow(P, x) % MOD) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}
