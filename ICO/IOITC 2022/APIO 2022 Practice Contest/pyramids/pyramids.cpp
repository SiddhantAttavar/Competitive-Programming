#include "pyramids.h"
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
#define ll long long

vector<ll> a, b;
vector<ll> prefA, prefB;
int n;

void init(vector<int> x, vector<int> y) {
	n = x.size();
	
	a = vector<ll>(x.begin(), x.end());
	b = vector<ll>(y.begin(), y.end());
	
	prefA.resize(n + 1);
	prefB.resize(n + 1);
	range(i, 0, n) {
		prefA[i + 1] = prefA[i] + a[i];
		prefB[i + 1] = prefB[i] + b[i];
	}
}

bool can_convert(int l, int r, int x, int y) {
	ll p = prefA[r + 1] - prefA[l];
	ll q = prefB[y + 1] - prefB[x];
	return p == q;
}
