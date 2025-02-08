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
const int MOD = 998244353;

struct Tree {
	typedef int T;
	static constexpr T unit = 1;
	T f(T a, T b) { return (a * b) % MOD; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, q;
        input(n, q);

        vector<int> a(n), b(n);
        arrput(a);
        arrput(b);

        vector<int> c(a.begin(), a.end());
        vector<int> d(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        Tree s(n, 1);
        range(i, 0, n) {
            s.update(i, min(c[i], d[i]));
        }

        cout << s.query(0, n);
        while (q--) {
            int o, x;
            input(o, x);

            x--;
            int j;
            if (o == 1) {
                j = upper_bound(c.begin(), c.end(), a[x]) - c.begin() - 1;
                a[x]++;
                c[j]++;
            }
            else {
                j = upper_bound(d.begin(), d.end(), b[x]) - d.begin() - 1;
                b[x]++;
                d[j]++;
            }
            s.update(j, min(c[j], d[j]));

            cout << ' ' << s.query(0, n);
        }
        cout << endl;
    }
}
