
#include <bits/stdc++.h>
#include "machine.h"
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<int> guess_permutation(int n) {
	vector<int> a(n);
	range(i, 0, n) {
		a[i] = i;
	}
	
	vector<int> b = use_machine(a);
	vector<int> o(b.begin(), b.end());
	sort(o.begin(), o.end());

	int x = -1;
	range(i, 0, 256) {
		vector<int> v(n);
		range(j, 0, n) {
			v[j] = i ^ j;
		}
		sort(v.begin(), v.end());
		bool flag = true;
		range(j, 0, n) {
			if (v[j] != o[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			x = i;
			bool flag = false;
			range(j, 0, n) {
				if (b[j] == 0) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				x = 2 * n - x;
			}
			break;
		}
	}

	map<int, int> res;
	range(i, 0, n) {
		res[x ^ i] = i;
	}

	vector<int> p(n);
	range(i, 0, n) {
		p[i] = res[b[i]];
	}

	return p;
}
