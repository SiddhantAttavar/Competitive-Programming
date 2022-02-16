// https://codebreaker.xyz/problem/mountains
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int maximum_deevs(vector<int> y) {
	int n = y.size();
	vector<pair<int, int>> h(n);
	range(i, 0, n) {
		h[i].first = y[i];
		h[i].second = i;
	}
	sort(h.begin(), h.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	});
	
	map<int, int> m;
	int res = 0;
	ordered_set s;
	for (pair<int, int> p : h) {
		int l = s.order_of_key(p.second);
		res += l * (s.size() - l - m[p.first]);
		s.insert(p.second);
		m[p.first]++;
	}
	return res;
}

int32_t main() {
	setup();
	
	int n;
	input(n);
	vector<int> y(n);
	arrPut(y);
	print(maximum_deevs(y));
}
