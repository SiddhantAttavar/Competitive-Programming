<<<<<<< HEAD
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
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k; input(n, k);
		int a[n]; arrPut(a);

		double median;
		if (n % 2 == 1) {
			median = a[n / 2];
		}
		else {
			median = (a[n / 2 - 1] + a[n / 2]) / 2.0;
		}
		double roundMedian = median + 0.5 - (median < 0);
		int center = roundMedian;

		int low = center - k / 2;
		int high = center + k / 2;
		if (k % 2 == 0) {
			if (median < center) {
				low = center - k / 2;
				high = center + k / 2 - 1;
			}
			else {
				low = center - k / 2 + 1;
				high = center + k / 2;
			}
		}

		ll res = 0;
		for (int i : a) {
			res += max(abs(i - low), abs(i - high));
		}
		print(res);
	}
=======
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
typedef long long ll;

int main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k; input(n, k);
		int a[n]; arrPut(a);

		double median;
		if (n % 2 == 1) {
			median = a[n / 2];
		}
		else {
			median = (a[n / 2 - 1] + a[n / 2]) / 2.0;
		}
		double roundMedian = median + 0.5 - (median < 0);
		int center = roundMedian;

		int low = center - k / 2;
		int high = center + k / 2;
		if (k % 2 == 0) {
			if (median < center) {
				low = center - k / 2;
				high = center + k / 2 - 1;
			}
			else {
				low = center - k / 2 + 1;
				high = center + k / 2;
			}
		}

		ll res = 0;
		for (int i : a) {
			res += max(abs(i - low), abs(i - high));
		}
		print(res);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}