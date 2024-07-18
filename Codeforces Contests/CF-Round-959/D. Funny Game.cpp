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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		if (n == 1) {
			print("YES");
			continue;
		}

		DSU d;
		d.init(n);

		vector<pair<int, int>> res;
		for (int x = n - 1; x > 0; x--) {
			vector<pair<int, int>> b(x, {-1, -1});
			range(j, 0, n) {
				if (b[a[j] % x].second != -1 and b[a[j] % x].second != d.get(j)) {
					d.unite(j, b[a[j] % x].first);
					res.push_back({j, b[a[j] % x].first});
					break;
				}
				b[a[j] % x] = {j, d.get(j)};
			}
		}

		if (res.size() != n - 1) {
			print("NO");
			continue;
		}

		reverse(res.begin(), res.end());
		print("YES");
		range(i, 0, n - 1) {
			print(res[i].first + 1, res[i].second + 1);
			// cout.flush();
			// assert(abs(a[res[i].first] - a[res[i].second]) % (i + 1) == 0);
		}
	}
}
