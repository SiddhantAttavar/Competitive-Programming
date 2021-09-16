#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(arr) for (auto &inVar : arr) {cin >> inVar;}
#define arrPrint(arr) for (auto &outVar : arr) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	setup();
	int n, m;
	input(n, m);

	int a[n], b[m];
	arrPut(a);
	arrPut(b);

	ll prefSumA[n + 1] = {0};
	range(i, 1, n + 1) {
		prefSumA[i] = prefSumA[i - 1] + a[i - 1];
	}

	ll prefSumB[m + 1] = {0};
	range(i, 1, m + 1) {
		prefSumB[i] = prefSumB[i - 1] + b[i - 1];
	}

	bool flag = false;
	range(i, 1, n + 1) {
		range(j, 1, m + 1) {
			if (prefSumA[i] == prefSumB[j]) {
				print(prefSumA[i]);
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}

	if (!flag) {
		print("Not possible");
	}
}