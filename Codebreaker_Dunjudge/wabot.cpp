// https://codebreaker.xyz/problem/wabot
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

int n;
vector<priority_queue<int, vector<int>, greater<int>>> a(2e6);

int32_t main() {
	setup();
	
	input(n);
	
	vector<int> l(n), c(n);
	range(i, 0, n) {
		input(l[i], c[i]);
	}
	
	fill(a.begin(), a.end(), priority_queue<int, vector<int>, greater<int>>());
	range(i, 0, n) {
		a[l[i]].push(c[i]);
	}

	int res = 0;
	range(i, 0, a.size()) {
		while (a[i].size() > 1) {
			int x = a[i].top();
			a[i].pop();
			int y = a[i].top();
			a[i].pop();
			res += x + y;
			a[i + 1].push(x + y);
		}
	}
	print(res);
}
