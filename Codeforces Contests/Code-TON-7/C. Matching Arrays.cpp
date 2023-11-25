#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool check(vector<int> &a, vector<int> &b, int x) {
	range(i, 0, (int) a.size()) {
		x -= a[i] > b[i];
	}
	return x == 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			input(a[i].first);
			a[i].second = i;
		}
		sort(a.begin(), a.end());

		vector<int> b(n);
		arrPut(b);

		if (x > n) {
			print("NO");
			continue;
		}

		sort(b.begin(), b.end());
		// arrPrint(b);

		vector<int> res(n);
		bool flag = true;
		range(i, 0, x) {
			if (b[x - i - 1] >= a[n - i - 1].first) {
				flag = false;
				break;
			}
			res[a[n - i - 1].second] = b[x - i - 1];
		}

		if (!flag) {
			print("NO");
			continue;
		}

		range(i, x, n) {
			if (a[i - x].first > b[i]) {
				flag = false;
				break;
			}
			res[a[i - x].second] = b[i];
		}

		if (!flag) {
			print("NO");
			continue;
		}

		print("YES");
		arrPrint(res);
	}
}
