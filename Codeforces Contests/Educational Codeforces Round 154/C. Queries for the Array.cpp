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
	setup(); int tc; input(tc); while (tc--) {
		string s;
		input(s);

		int curr_size = 0;
		int n = s.size();
		bool flag = true;

		int min_unsorted_size = n;
		bool is_unsorted = false;

		stack<int> sorted_sizes;
		sorted_sizes.push(0);
		bool is_sorted = true;

		for (char c : s) {
			if (c == '+') {
				curr_size++;

				is_sorted = false;
				while (!sorted_sizes.empty() and curr_size <= sorted_sizes.top()) {
					sorted_sizes.pop();
				}
			}
			else if (c == '-') {
				curr_size--;

				if (curr_size < min_unsorted_size) {
					min_unsorted_size = n;
					is_unsorted = false;
				}

				while (!sorted_sizes.empty() and curr_size < sorted_sizes.top()) {
					sorted_sizes.pop();
				}

				if (!sorted_sizes.empty() and curr_size <= sorted_sizes.top()) {
					is_sorted = true;
				}
			}
			else if (c == '0') {
				if (is_sorted) {
					flag = false;
					break;
				}

				min_unsorted_size = min(min_unsorted_size, curr_size);
				is_unsorted = true;
			}
			if (c == '1' or curr_size <= 1) {
				if (is_unsorted) {
					flag = false;
					break;
				}

				while (!sorted_sizes.empty() and curr_size < sorted_sizes.top()) {
					sorted_sizes.pop();
				}
				if (sorted_sizes.empty() or (!sorted_sizes.empty() and curr_size > sorted_sizes.top())) {
					sorted_sizes.push(curr_size);
				}

				min_unsorted_size = n;
				is_sorted = true;
			}
		}

		print(flag ? "YES" : "NO");
	}
}
