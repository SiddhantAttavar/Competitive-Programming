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

int32_t main() {
	setup();
	int n, q;
	input(n, q);

	vector<int> a(n);
	arrPut(a);

	while (q--) {
		int l, r;
		input(l, r);

		if (r - l + 1 >= 50) {
			print("YES");
			continue;
		}

		vector<int> b(a.begin() + l - 1, a.begin() + r);
		sort(b.begin(), b.end());

		int i = 2, j = b.size() - 3;
		while (i < b.size() and b[i] >= b[i - 1] + b[i - 2]) {
			i++;
		}
		while (j > i and b[j] + b[j + 1] <= b[j + 2]) {
			j--;
		}

		if (j > i) {
			print("YES");
			continue;
		}

		bool flag = false;
		range(i, 5, b.size()) {
			if (b[i - 5] + b[i - 4] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 3] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 2] > b[i] and b[i - 4] + b[i - 3] > b[i - 1]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 1] > b[i] and b[i - 4] + b[i - 3] > b[i - 2]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 4] > b[i - 1] and b[i - 3] + b[i - 2] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 3] > b[i - 1] and b[i - 4] + b[i - 2] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 2] > b[i - 1] and b[i - 4] + b[i - 3] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 4] > b[i - 2] and b[i - 3] + b[i - 1] > b[i]) {
				flag = true;
				break;
			}

			if (b[i - 5] + b[i - 3] > b[i - 2] and b[i - 4] + b[i - 1] > b[i]) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
