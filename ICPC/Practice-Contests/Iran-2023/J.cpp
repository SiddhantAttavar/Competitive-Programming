#include <bits/stdc++.h>

using namespace std;

 

#define int long long

#define ll long long

#define endl '\n'

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define all(x) begin(x), end(x)

#define sz(x) ((ll)((x).size()))

typedef pair<int, int> pii;

typedef vector<int> vi;

 

template<class T, class U, int SZ> struct LazySeg {

    const T ID1;

    T (*cmb)(T a, T b);

    vector<T> seg; vector<U> lazy;

    void (*push)(int, int, int, vector<T>&, vector<U>&);

   

    LazySeg(T id1, U id2, T _cmb(T, T), void _push(int, int, int, vector<T>&, vector<U>&)) : ID1(id1), cmb(_cmb), seg(2*SZ, id1), lazy(2*SZ, id2), push(_push) {}

   

    void pull(int ind) { seg[ind] = cmb(seg[2*ind], seg[2*ind + 1]); }

    void build() { for(int i = SZ - 1; i >= 1; i--) { pull(i); }}

   

    void upd(int lo, int hi, U inc, int ind = 1, int L = 0, int R = SZ-1) {

        push(ind, L, R, seg, lazy);

        if(hi < L || R < lo) { return; }

        if(lo <= L && R <= hi) {

            lazy[ind] += inc; // accumulate (range add)

            push(ind, L, R, seg, lazy);

            return;

        }

        int M = (L + R)/2;

        upd(lo, hi, inc, 2 * ind, L, M);

        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);

        pull(ind);

    }

   

    T query(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {

        push(ind, L, R, seg, lazy);

        if(lo > R || L > hi) { return ID1; }

        if(lo <= L && R <= hi) { return seg[ind]; }

        ll M = (L+R)/2;

        return cmb(query(lo, hi, 2*ind, L, M), query(lo, hi, 2*ind + 1, M+1, R));

    }

};

 

void solve() {

    ll n, k; cin >> n >> k;

    vector<ll> a(n);

    for(ll i = 0; i < n; i++) { cin >> a[i]; }

   

    ll nw = n-k+1; // num of windows of len k

    const ll SZ = (1LL << 18);

   

    LazySeg<ll, ll, SZ> sgt(0, 0, [](ll x, ll y) -> ll { return max(x, y); },

        [](int ind, int L, int R, vector<int>& seg, vector<int>& lazy) -> void {

            if(lazy[ind] == 0) { return; }

            seg[ind] += lazy[ind];

            if(L != R) {

                lazy[2*ind] += lazy[ind];

                lazy[2*ind + 1] += lazy[ind];

            }

            lazy[ind] = 0;

        }

    );

   

    vector<ll> ord(n); for(ll i = 0; i < n; i++) { ord[i] = i; }

    sort(all(ord), [&](ll i, ll j) -> bool {

        if(a[i] != a[j])  { return a[i] < a[j]; }

        else { return i < j; }

    });

   

    vector<ll> ans(n);

   

   

    auto LB = [&](ll idx) -> ll {

        return max(0LL, idx - k + 1);  

    };

    auto RB = [&](ll idx) -> ll {

        return min(idx, nw - 1);

    };  

   

    ll L = 0;

    while(L < n) {

        ll R = L;

        while(R < n && a[ord[L]] == a[ord[R]]) {

            R++;

        }

        // a[ord[R]] is diff now.

       

        for(ll t = L; t < R; t++) {

            ll idx = ord[t];

            sgt.upd(LB(idx), RB(idx), 1);

        }

        // fill answers for this number

        for(ll t = L; t < R; t++) {

            ll idx = ord[t];

            ans[idx] = k + 1 - sgt.query(LB(idx), RB(idx));

        }

       

        L = R;

    }

   

    for(ll i = 0; i < n; i++) { cout << ans[i] << " "; }

    cout << endl;

}

 

signed main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;

    // cin >> t; // comment out if reqd.

    while (t--) {solve();}

}
