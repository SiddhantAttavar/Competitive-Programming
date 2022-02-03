// https://codebreaker.xyz/problem/eescapism
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
#define int long long

const int MOD = 1000000007;

int32_t main() {
	setup();
	
	int n;
	input(n);
	
	vector<int> d(n);
	arrPut(d);
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());

	int res = 0;
	range(i, 0, n - 1) {
		res += (i + 1) * d[i] * (d[i] + 1) / 2 - d[i + 1] * (d[i + 1] + 1) / 2;
		res %= MOD;
	}
	res += n * d[n - 1] * (d[n - 1] + 1) / 2;
	res %= MOD;
	print(res);
}
