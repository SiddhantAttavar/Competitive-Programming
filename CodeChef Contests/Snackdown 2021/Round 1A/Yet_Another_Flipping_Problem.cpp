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
	setup(); int tc; input(tc); while (tc--) {
		int n, k; input(n, k);

		if (k % 2 == 0 and k > 0) {
			print("NO");
			continue;
		}
		print("YES");
		
		//Convert k to binary
		vector<int> bin;
		int temp = k;
		while (temp > 0) {
			bin.push_back(temp % 2);
			temp /= 2;
		}
		int m = bin.size();

		// Convert all sequences of 1, 0, 0 to 0, 0, 1 or 1, 1 to 1, 1
		vector<vector<int>> moves = {{}};
		range(i, 0, m) {
			if (i == m - 1 or bin[i + 1] == 1) {
				moves.back().push_back(1);
				moves.push_back({});
			}
			else {
				moves.back().push_back(0);
			}
		}
		moves.pop_back();

		int curr = k, x = 1;
		print(m);
		for (vector<int> move : moves) {
			int temp = x;
			curr -= x;
			for (int i : move) {
				if (i == 0) {
					print(curr - x + 1);
					curr -= x;
				}
				else {
					print(curr + 1);
					curr += x - temp;
				}
				x *= 2;
			}
		}
	}
}