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
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		string s; input(s);
		int n = s.size();

		bool zeroArr[n + 1] = {false};
		bool oneArr[n + 1] = {false};
		stack<int> zeroS, oneS;

		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			zeroArr[i] = zeroArr[i + 1];
			oneArr[i] = oneArr[i + 1];

			if (s[i] == '0') {
				zeroArr[i] = true;
				zeroS.push(i);
			}
			else {
				oneArr[i] = true;
				oneS.push(i);
			}

			if (zeroArr[i] && oneArr[i]) {
				count++;
				zeroArr[i] = oneArr[i] = false;
			}
		}

		if (count == 0) {
			print(zeroArr[0]);
			continue;
		}

		//arrPrint(zeroArr);
		//arrPrint(oneArr);

		int ind = 0;
		string res;
		if (!zeroArr[0] && oneArr[0]) {
			res = "10";
			while (!zeroS.empty() && zeroS.top() < ind) {
				zeroS.pop();
			}
			if (zeroS.empty()) {
				break;
			}
			ind = zeroS.top() + 1;
			zeroS.pop();
		}
		zeroArr[0] = true;
		while (ind <= n && count-- >= 0) {
			if (!zeroArr[ind]) {
				res += '0';
				while (!zeroS.empty() && zeroS.top() < ind) {
					zeroS.pop();
				}
				if (zeroS.empty()) {
					break;
				}
				ind = zeroS.top() + 1;
				zeroS.pop();
			}
			else if (!oneArr[ind]) {
				res += '1';
				while (!oneS.empty() && oneS.top() < ind) {
					oneS.pop();
				}
				if (oneS.empty()) {
					break;
				}
				ind = oneS.top() + 1;
				oneS.pop();
			}
		}

		print(res);
	}
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
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		string s; input(s);
		int n = s.size();

		bool zeroArr[n + 1] = {false};
		bool oneArr[n + 1] = {false};
		stack<int> zeroS, oneS;

		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			zeroArr[i] = zeroArr[i + 1];
			oneArr[i] = oneArr[i + 1];

			if (s[i] == '0') {
				zeroArr[i] = true;
				zeroS.push(i);
			}
			else {
				oneArr[i] = true;
				oneS.push(i);
			}

			if (zeroArr[i] && oneArr[i]) {
				count++;
				zeroArr[i] = oneArr[i] = false;
			}
		}

		if (count == 0) {
			print(zeroArr[0]);
			continue;
		}

		//arrPrint(zeroArr);
		//arrPrint(oneArr);

		int ind = 0;
		string res;
		if (!zeroArr[0] && oneArr[0]) {
			res = "10";
			while (!zeroS.empty() && zeroS.top() < ind) {
				zeroS.pop();
			}
			if (zeroS.empty()) {
				break;
			}
			ind = zeroS.top() + 1;
			zeroS.pop();
		}
		zeroArr[0] = true;
		while (ind <= n && count-- >= 0) {
			if (!zeroArr[ind]) {
				res += '0';
				while (!zeroS.empty() && zeroS.top() < ind) {
					zeroS.pop();
				}
				if (zeroS.empty()) {
					break;
				}
				ind = zeroS.top() + 1;
				zeroS.pop();
			}
			else if (!oneArr[ind]) {
				res += '1';
				while (!oneS.empty() && oneS.top() < ind) {
					oneS.pop();
				}
				if (oneS.empty()) {
					break;
				}
				ind = oneS.top() + 1;
				oneS.pop();
			}
		}

		print(res);
	}
}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
