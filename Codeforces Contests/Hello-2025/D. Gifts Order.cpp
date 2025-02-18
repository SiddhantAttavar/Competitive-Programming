#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

struct Tree {
	typedef array<int, 5> T;
    T unit;
	T f(T a, T b) {
        return {
            min(a[0], b[0]),
            max(a[1], b[1]),
            min(a[2], b[2]),
            max(a[3], b[3]),
            max({a[4], b[4], b[1] - a[0], a[3] - b[2]})
        };
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = {}) : unit(def), s(2*n, def), n(n) {}
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

        vector<int> a(n);
        arrput(a);

        Tree s(n, {(int) 1e9, (int) -1e9, (int) 1e9, (int) -1e9, 0});
        range(i, 0, n) {
            s.update(i, {a[i] - i, a[i] - i, a[i] + i, a[i] + i, 0});
        }

        print(s.query(0, n)[4]);
        while (q--) {
            int i, x;
            input(i, x);

            i--;
            s.update(i, {x - i, x - i, x + i, x + i, 0});
            print(s.query(0, n)[4]);
        }
    }
}
