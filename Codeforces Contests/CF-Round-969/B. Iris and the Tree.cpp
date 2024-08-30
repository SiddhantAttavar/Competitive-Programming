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
const int MOD = (int) 1e9 + 7;

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, w;
		input(n, w);

		vector<int> p(n - 1);
		arrPut(p);

		vector<int> m(n), l(n, 0);
		range(i, 0, n) {
			m[i] = i;
		}
		range(i, 1, n) {
			l[i] = l[p[i - 1] - 1] + 1;
		}
		for (int i = n - 1; i > 0; i--) {
			m[p[i - 1] - 1] = max(m[p[i - 1] - 1], m[i]);
		}

		DSU d;
		d.init(n);

		int res = w * n;
		set<int> s;
		range(i, 0, n - 1) {
			int x, y;
			input(x, y);
			x--;

			res -= y * (n - 2 - s.size()); 
			w -= y;

			if (d.get((m[x] + 1) % n) == d.get(p[x - 1] - 1) and d.get(m[x]) == d.get(x)) {
				s.insert(m[x]);
				res -= w;
			}

			if (d.get((x - 1 + n) % n) == d.get(p[x - 1] - 1)) {
				s.insert((x - 1 + n) % n);
				res -= w;
			}

			d.unite(x, p[x - 1] - 1);
			cout << res << ' ';
		}
		cout << endl;
	}
}
