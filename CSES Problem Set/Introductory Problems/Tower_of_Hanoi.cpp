#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<pair<int, int>> moves;

void solve(int n, int a, int b, int c) {
	if (n == 0) {
		return;
	}
	solve(n - 1, a, c, b);
	moves.push_back({a, b});
	solve(n - 1, c, b, a);
}

int main() {
	setup();
	
	int n; input(n);
	solve(n, 1, 3, 2);
	print(moves.size());
	for (pair<int, int> p : moves) {
		print(p.first << " " << p.second);
	}
}
