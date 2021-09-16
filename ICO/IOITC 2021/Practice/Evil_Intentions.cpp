#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto &outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int n; input(n);
	int in[n], out[n];
	arrPut(in);
	arrPut(out);

	int sumIn = 0, sumOut = 0;
	for (int i : in) {
		sumIn += i;
	}
	for (int i : out) {
		sumOut += i;
	}

	if (sumIn == sumOut) {
		print("YES");
	}
	else {
		print("NO");
		return 0;
	}

	int a = 0, b = 0;
	while (a < n) {
		if (out[a] == 0) {
			a++;
			continue;
		}
		if (in[b] == 0) {
			b++;
			continue;
		}
		print(a + 1, b + 1);
		out[a]--;
		in[b]--;
	}
}