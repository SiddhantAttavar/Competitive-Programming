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
const int MOD = (int) 1e9 + 7; //998244353

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
};

int add(int i, SegTree<pair<int, int>> &s, vector<int> &a, map<int, int> &m, vector<int> &f) {
    int k = m[a[i]];
    f[k]++;
    if (f[k] > 1) {
        return 0;
    }

    int j = s.query(0, k).first;
    int x = s.query(k, m.size() - 1).second;
    s.upd(k, {1, a[i]});
    return (j + 1) * a[i] + x;
}

int remove(int i, SegTree<pair<int, int>> &s, vector<int> &a, map<int, int> &m, vector<int> &f) {
    int k = m[a[i]];
    f[k]--;
    if (f[k]) {
        return 0;
    }

    s.upd(k, {0, 0});
    int j = s.query(0, k).first;
    int x = s.query(k, m.size() - 1).second;
    return (j + 1) * a[i] + x;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrPut(a);

        set<int> b(a.begin(), a.end());
        int i = 0;
        map<int, int> m;
        for (int x : b) {
            m[x] = i;
            i++;
        }

        int q;
        input(q);
        vector<pair<pair<int, int>, int>> v(q);
        range(i, 0, q) {
            int l, r;
            input(l, r);

            v[i] = {{l - 1, r - 1}, i};
        }
        sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
            return make_pair(a.first.first / 100, a.first.second) < make_pair(b.first.first / 100, b.first.second);
        });

        SegTree<pair<int, int>> t(m.size(), {0, 0}, [](pair<int, int> a, pair<int, int> b) {
            return make_pair(a.first + b.first, a.second + b.second);
        });

        int l = 0, r = -1, z = 0;
        vector<int> f(m.size(), 0);
        vector<int> res(q);
        for (pair<pair<int, int>, int> p : v) {
            int s, e, i = p.second;
            tie(s, e) = p.first;

            while (r < e) {
                r++;
                z += add(r, t, a, m, f);
            }

            while (s < l) {
                l--;
                z += add(l, t, a, m, f);
            }

            while (l < s) {
                z -= remove(l, t, a, m, f);
                l++;
            }

            while (e < r) {
                z -= remove(r, t, a, m, f);
                r--;
            }

            res[i] = z;
        }

        for (int i : res) {
            print(i);
        }
    }
}
