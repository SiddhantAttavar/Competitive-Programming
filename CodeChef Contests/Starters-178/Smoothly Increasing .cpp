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

bool check(vector<int> &a) {
	if (a.size() == 1) {
		return true;
	}
	vector<int> b(a.size() - 1);
	rep(i, 0, a.size() - 1) {
		if (a[i + 1] <= a[i]) {
			return false;
		}
		b[i] = a[i + 1] - a[i];
	}
	return check(b);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		if (n > 50) {
			print(string(n, '0'));
			continue;
		}

		string res(n, '0');
		rep(i, 0, n) {
			vector<int> b(a.begin(), a.end());
			b.erase(b.begin() + i);
			res[i] = check(b) ? '1' : '0';
		}
		print(res);
	}
}
