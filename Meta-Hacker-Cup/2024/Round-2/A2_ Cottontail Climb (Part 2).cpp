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
const int MOD = (int) 1e9 + 7; //998244353

void add(string x, int k, int i, vector<string> &v) {
	if (i == k) {
		v.push_back(x);
		return;
	}

	for (int y = x.back() - '0' - (i == 1); y > 0; y--) {
		add(x + to_string(y), k, i + 1, v);
	}
}

int32_t main() {
	vector<int> v;
	range(i, 1, 10) {
		range(k, 1, 6) {
			vector<string> w;
			add(to_string(i), k, 1, w);
			for (string s : w) {
				for (string t : w) {
					reverse(t.begin(), t.end());
					t.pop_back();
					v.push_back(stoi(t + s));
				}
			}
		}
	}

	setup(); int tc; input(tc); range(t, 0, tc) {
		int a, b, m;
		input(a, b, m);

		int res = 0;
		for (int i : v) {
			res += i >= a and i <= b and i % m == 0;
		}

		cout << "Case #" << t + 1 << ": " << res << '\n';
	}
}
