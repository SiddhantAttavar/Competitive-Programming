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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n);
		arrput(p);

		int m = *max_element(p.begin(), p.end());

		set<int> s(p.begin(), p.end());
		vector<int> l(m + 1, 1e15);
		for (int i = m; i >= 0; i--) {
			if (s.count(i)) {
				l[i] = i;
			}
			else {
				l[i] = l[i + 1];
			}
		}

		vector<pair<int, pair<int, int>>> e;
		for (int i : s) {
			if (i < m and l[i + 1] <= m) {
				e.push_back({l[i + 1] % i, {i, l[i + 1]}});
			}
			for (int j = 2 * i; j <= m; j += i) {
				if (l[j] <= m) {
					e.push_back({l[j] % i, {i, l[j]}});
				}
			}
		}
		sort(e.begin(), e.end());

		UF d(m + 1);
		int res = 0;
		for (pair<int, pair<int, int>> p : e) {
			if (d.join(p.second.first, p.second.second)) {
				res += p.first;
			}
		}

		print(res);
	}
}
