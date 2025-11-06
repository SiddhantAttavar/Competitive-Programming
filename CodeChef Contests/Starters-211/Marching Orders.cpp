#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		int c = *min_element(a.begin(), a.end());
		bool flag = true;
		rep(i, 0, n) {
			a[i]--;
			if (a[i] % 3 != (i + n) % 3) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			print("No");
			continue;
		}

		int i = 0;
		while (i < n) {
			if (i >= n - 2) {
				flag = false;
				break;
			}
			int x = a[i], y = a[i + 1], z = a[i + 2];
			if (min({x, y, z}) + 2 != max({x, y, z})) {
				flag = false;
				break;
			}
			int j = i;
			while (j + 1 < n and (a[j + 1] == x or a[j + 1] == y or a[j + 1] == z)) {
				j++;
			}
			if (max({x, y, z}) > j or min({x, y, z}) < i) {
				flag = false;
				break;
			}
			i = j + 1;
		}

		if (flag) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
