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

// Calculate gcd of an array
int gcd(vector<int> &a, int n){
	int res = a[0];
	for(int i=1; i<n; i++){
		res = __gcd(res, a[i]);
	}
	return res;
}

int no_prime(int x) {
	vector<int> p;
	vector<bool> s(x + 1, true);
	range(i, 2, x + 1) {
		if (s[i]) {
			p.push_back(i);
			range(j, i + i, x + 1) {
				s[j] = false;
			}
		}
	}

	int c = 0;
	for (int i : p) {
		while (x % i == 0) {
			x /= i;
			c++;
		}
		if (i > x) {
			break;
		}
	}
	return c;
}


/* int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		vector<int> a(n);
		arrPut(a);


		int x = gcd(a, n);

		int y = no_prime(x);
		if (n == 2) {
			int s = no_prime(a[0]);
			int t = no_prime(a[1]);
			if (s >= 2 and t >= 2) {
				print("BOB");
			}
			else {
				print("DRAW");
			}
			continue;
		}
		if (y <= 1) {
			print("DRAW");
		}
		else {
			print("BOB");
		}
	}
} */

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		vector<int> a(n);
		arrPut(a);


		int x = gcd(a, n);

		int y = no_prime(x);
		if (n == 2) {
			int s = no_prime(a[0]);
			int t = no_prime(a[1]);
			if (s >= 2 and t >= 2) {
				print("BOB");
			}
			else {
				print("DRAW");
			}
			continue;
		}
		if (y <= 1) {
			print("DRAW");
		}
		else {
			print("BOB");
		}
	}
}
