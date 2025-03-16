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

int32_t main() {
	setup();

	int n;
	input(n);

	map<pair<int, int>, vector<pair<int, int>>> m;
	rep(i, 0, n) {
		array<int, 3> a;
		arrput(a);
		sort(a.begin(), a.end());
		m[{a[1], a[2]}].push_back({a[0], i});
	}

	pair<int, int> res = {-1, -1};
	int x = 0;
	for (pair<pair<int, int>, vector<pair<int, int>>> p : m) {
		sort(p.second.begin(), p.second.end());
		reverse(p.second.begin(), p.second.end());
		if (p.second.size() > 1) {
			int z = min({p.first.first, p.first.second, p.second[0].first + p.second[1].first});
			if (z > x) {
				x = z;
				res = {p.second[0].second, p.second[1].second};
			}
		}
		else {
			int z = p.second[0].first; 
			if (z > x) {
				x = z;
				res = {p.second[0].second, -1};
			}
		}
	}

	if (res.second == -1) {
		print(1);
		print(res.first + 1);
	}
	else {
		print(2);
		print(res.first + 1, res.second + 1);
	}
}
