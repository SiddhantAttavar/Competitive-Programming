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
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

struct Tree {
	typedef vector<int> T;
	T unit = {1, 0, 0, 0, 0, 0, 0, 0};
	T f(T a, T b) {
        vector<int> res(8, 0);
        range(i, 0, 8) {
            range(j, 0, 8) {
                res[i ^ j] = (res[i ^ j] + a[i] * b[j]) % MOD;
            }
        }
        return res;
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = {}) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    int N = 2e5;
    vector<int> dp(N, 0);
    range(i, 1, N + 1) {
        set<int> s;
        int o = i;
        while (o) {
            if (o % 10) {
                s.insert(dp[i - o % 10]);
            }
            o /= 10;
        }
        while (s.count(dp[i])) {
            dp[i]++;
        }
    }

    int n;
    input(n);

    vector<int> a(n);
    arrput(a);

    Tree s(n, vector<int>(8, 0));
    range(i, 0, n) {
        vector<int> v(8, 0);
        v[0] = 1;
        v[dp[a[i]]]++;
        s.update(i, v);
    }

    int q;
    input(q);
    while (q--) {
        int o, x, y;
        input(o, x, y);

        if (o == 1) {
            print((mod_pow(2, y - x + 1) - s.query(x - 1, y)[0] + MOD) % MOD);
        }
        else {
            vector<int> v(8, 0);
            v[0] = 1;
            v[dp[y]]++;
            s.update(x - 1, v);
        }
    }
}
