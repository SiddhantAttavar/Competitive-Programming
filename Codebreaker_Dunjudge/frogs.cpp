// https://codebreaker.xyz/problem/frogs
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	int n, m, k;
	input(n, m, k);
	vector<int> d(m);
	arrPut(d);
	vector<int> a(k);
	arrPut(a);

	int x = 1e9;
	vector<int> res;
	range(i, 0, m) {
		int curr = 0;
		for (int j : a) {
			curr += j % d[i] == 0;
		}
		if (curr < x) {
			x = curr;
			res = {i + 1};
		}
		else if (curr == x) {
			res.push_back(i + 1);
		}
	}

	print(res.size());
	arrPrint(res);
}
