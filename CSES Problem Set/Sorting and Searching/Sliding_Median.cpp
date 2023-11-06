#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrPut(a);

	if (k == 1) {
		arrPrint(a);
		return 0;
	}

	multiset<int> x, y;
	range(i, 0, k) {
		y.insert(a[i]);
	}

	range(i, 0, k / 2) {
		x.insert(*y.begin());
		y.erase(y.begin());
	}

	if (k % 2 == 1) {
		x.insert(*y.begin());
		y.erase(y.begin());
	}

	multiset<int>::iterator j = x.end();
	j--;
	cout << *j << ' ';

	range(i, k, n) {
		if (a[i - k] <= *j) {
			x.erase(x.find(a[i - k]));

			if (x.size() < y.size()) {
				x.insert(*y.begin());
				y.erase(y.begin());
			}
		}
		else {
			y.erase(y.find(a[i - k]));

			if (y.size() < x.size() - 1) {
				y.insert(*j);
				x.erase(j);
			}
		}

		j = x.end();
		j--;
		// arrPrint(x);
		// arrPrint(y);
		// print('j', *j);

		if (a[i] <= *j) {
			x.insert(a[i]);

			if (y.size() < x.size() - 1) {
				y.insert(*j);
				x.erase(j);
			}
		}
		else {
			y.insert(a[i]);

			if (x.size() < y.size()) {
				x.insert(*y.begin());
				y.erase(y.begin());
			}
		}

		j = x.end();
		j--;
		// arrPrint(x);
		// arrPrint(y);
		cout << *j << ' ';
	}
}
