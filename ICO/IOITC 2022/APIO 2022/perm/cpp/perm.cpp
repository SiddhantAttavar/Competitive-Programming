#include "perm.h"
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

vector<int> construct_permutation(long long k) {
	// print(k);
	if (k <= 1) {
		return {};
	}
	
	if (k & 1) {
		if (k > 100 and (((k - 1) >> 1) & 1)) {
			vector<int> res = construct_permutation((k - 3) >> 1);
			bool flag = true;
			range(i, 0, res.size()) {
				if (res[i] == 0) {
					flag = false;
					break;
				}
				if (res[i] == 1) {
					range(j, 0, res.size()) {
						if (res[j] >= 2) {
							res[j]++;
						}
					}
					res.push_back(res.size() + 1);
					res.push_back(2);
					return res;
				}
			}
		}

		vector<int> res = construct_permutation(k - 1);
		range(i, 0, res.size()) {
			res[i]++;
		}
		res.push_back(0);
		return res;
	}

	vector<int> res = construct_permutation(k >> 1);
	res.push_back(res.size());

	return res;
}
