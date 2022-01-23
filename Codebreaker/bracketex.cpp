// https://codebreaker.xyz/problem/bracketex
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
	setup();
	int l;
	input(l);
	string s;
	input(s);
	stack<char> stack;
	map<char, char> match = {
		{'(', ')'}, 
		{'[', ']'},
		{'{', '}'}
	};

	bool flag = true;
	for (char c : s) {
		if (match.count(c)) {
			stack.push(c);
		}
		else {
			if (stack.empty() or match[stack.top()] != c) {
				flag = false;
				break;
			}
			stack.pop();
		}
	}
	
	if (!stack.empty()) {
		flag = false;
	}

	if (flag) {
		print("Valid");
	}
	else {
		print("Invalid");
	}
}
