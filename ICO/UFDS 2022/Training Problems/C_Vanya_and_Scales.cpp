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

int32_t main() {
	setup();
	
	int w, n;
	input(w, n);

	vector<int> a;
	while (n) {
		a.push_back(n % w);
		n /= w;
	}
	a.push_back(0);

	bool flag = true;
	range(i, 0, a.size() - 1) {
		if (a[i] > 1 and a[i] < w - 1) {
			flag = false;
			break;
		}
		
		if (a[i] == w - 1 or a[i] == w) {
			a[i + 1]++;
		}
	}
	if (flag) {
		print("YES");
	}
	else {
		print("NO");
	}
}
