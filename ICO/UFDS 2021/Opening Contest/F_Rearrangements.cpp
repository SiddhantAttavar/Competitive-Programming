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

	const int MOD = 1e9 + 7;
	
	int n;
	input(n);
	vector<int> a(n);
	arrPut(a);

	vector<int> fact(n + 1, 1);
	range(i, 1, n + 1) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}


	int res = 1;
	map<int, int> freq;
	for (int i : a) {
		freq[i]++;
	}
	for (pair<int, int> p : freq) {
		res = (res * fact[p.second]) % MOD;
	}
	print(res);
}
