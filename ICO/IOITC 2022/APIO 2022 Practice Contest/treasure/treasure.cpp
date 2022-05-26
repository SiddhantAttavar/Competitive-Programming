#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include "treasure.h"

vector<int> encode(vector<int> x, vector<int> y) {
	int n = x.size();

	vector<int> res(3 * n);
	range(i, 0, n) {
		res[3 * i] = x[i];
		res[3 * i + 1] = y[i];
		res[3 * i + 1] = x[i] ^ y[i];
	}
	
	arrPrint(res);

	return res;
}

vector<int> decode(vector<int> e) {
	int n = e.size() / 3;

	vector<vector<int>> graph(n);
	set<int> s(e.begin(), e.end());

	range(i, 0, n) {
		
	}

	return e;
}
