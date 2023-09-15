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

bool check(vector<int> &a) {
	range(i, 0, (int) a.size() - 1) {
		if (a[i] == a[i + 1]) {
			return false;
		}
	}

	range(i, 0, (int) a.size() - 2) {
		if ((a[i] < a[i + 1] and a[i + 1] < a[i + 2]) or 
			(a[i] > a[i + 1] and a[i + 1] > a[i + 2])) {
			return false;
		}
	}

	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);
		sort(a.begin(), a.end());

		vector<int> res1(n), res2(n);
		int j = 0;
		for (int i = 0; i < n; i += 2) {
			res1[i] = a[j];
			j++;
		}
		for (int i = 1; i < n; i += 2) {
			res1[i] = a[j];
			j++;
		}

		j = 0;
		for (int i = 1; i < n; i += 2) {
			res2[i] = a[j];
			j++;
		}
		for (int i = 0; i < n; i += 2) {
			res2[i] = a[j];
			j++;
		}

		if (check(res1)) {
			arrPrint(res1);
		}
		else if (check(res2)) {
			arrPrint(res2);
		}
		else {
			print(-1);
		}
	}
}
