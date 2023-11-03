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

	int n;
	input(n);

	int x = n * (n + 1) / 2;

	if (x % 2 == 1) {
		print("NO");
		return 0;
	}

	print("YES");
	x /= 2;

	set<int> s;
	range(i, 1, n + 1) {
		s.insert(i);
	}

	vector<int> res;
	while (x) {
		set<int>::iterator i = s.upper_bound(x);
		i--;
		x -= *i;
		res.push_back(*i);
		s.erase(i);
	}

	print(res.size());
	arrPrint(res);

	print(s.size());
	arrPrint(s);
}
