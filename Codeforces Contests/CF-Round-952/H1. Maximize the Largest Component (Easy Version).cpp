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

/**tcT> T kruskal(int N, vector<pair<T,pi>> ed) {
	sort(all(ed));
	T ans = 0; DSU D; D.init(N); // edges that unite are in MST
	each(a,ed) if (D.unite(a.s.f,a.s.s)) ans += a.f; 
	return ans;
}*/

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> a(n);
		arrPut(a);

		DSU d;
		d.init(n * m);

		range(i, 0, n) {
			range(j, 0, m) {
				if (a[i][j] == '.') {
					continue;
				}

				if (i > 0 and a[i - 1][j] == '#') {
					d.unite(i * m + j, i * m + j - m);
				}
				if (i < n - 1 and a[i + 1][j] == '#') {
					d.unite(i * m + j, i * m + j + m);
				}
				if (j > 0 and a[i][j - 1] == '#') {
					d.unite(i * m + j, i * m + j - 1);
				}
				if (j < m - 1 and a[i][j + 1] == '#') {
					d.unite(i * m + j, i * m + j + 1);
				}
			}
		}

		int res = 0;
		range(i, 0, n) {
			set<int> s;
			int c = 0;
			range(j, 0, m) {
				if (a[i][j] == '.') {
					c++;
				}
				if (a[i][j] == '#' and !s.count(d.get(i * m + j))) {
					c += d.size(i * m + j);
					s.insert(d.get(i * m + j));
				}
				if (i > 0 and a[i - 1][j] == '#' and !s.count(d.get(i * m + j - m))) {
					c += d.size(i * m + j - m);
					s.insert(d.get(i * m + j - m));
				}
				if (i < n - 1 and a[i + 1][j] == '#' and !s.count(d.get(i * m + j + m))) {
					c += d.size(i * m + j + m);
					s.insert(d.get(i * m + j + m));
				}
			}
			res = max(res, c);
		}

		range(j, 0, m) {
			set<int> s;
			int c = 0;
			range(i, 0, n) {
				if (a[i][j] == '.') {
					c++;
				}
				if (a[i][j] == '#' and !s.count(d.get(i * m + j))) {
					c += d.size(i * m + j);
					s.insert(d.get(i * m + j));
				}
				if (j > 0 and a[i][j - 1] == '#' and !s.count(d.get(i * m + j - 1))) {
					c += d.size(i * m + j - 1);
					s.insert(d.get(i * m + j - 1));
				}
				if (j < m - 1 and a[i][j + 1] == '#' and !s.count(d.get(i * m + j + 1))) {
					c += d.size(i * m + j + 1);
					s.insert(d.get(i * m + j + 1));
				}
			}
			res = max(res, c);
		}

		print(res);
	}
}
