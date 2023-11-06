#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define int long long

int32_t main() {
	setup();

	int n;
	input(n);

	vector<pair<pair<int, int>, int>> e;
	ordered_multiset a;
	range(i, 0, n) {
		int x, y;
		input(x, y);

		e.push_back({{x, -y}, i});
		a.insert(y);
	}

	sort(e.begin(), e.end());

	int res1[n], res2[n];
	fill(res1, res1 + n, 0);
	fill(res2, res2 + n, 0);

	ordered_multiset b;
	for (pair<pair<int, int>, int> p : e) {
		int x, y, i = p.second;
		tie(x, y) = p.first;
		y = -y;

		a.erase(a.find(y));
		res1[i] = (int) (a.order_of_key(y + 1) - b.order_of_key(y + 1) - 1);
		res2[i] = (int) (b.size() - b.order_of_key(y));
		b.insert(y);
	}

	arrPrint(res1);
	arrPrint(res2);
}
