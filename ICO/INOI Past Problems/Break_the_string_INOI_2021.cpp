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

vector<int> solve(string s, int n, int k) {
    int curr = 0;
    vector<int> res = {0};
    range(i, 0, n) {
        curr += s[i] == '1' ? 1 : -1;
        if (curr > k) {
            res.push_back(i);
            curr = 1;
        }
    }
    while (res.size() > 0 && curr <= 0) {
        res.pop_back();
        curr += k;
    }
    if (res.size() == 0) {
        return {-1};
    }
    return res;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);
		
		string s; input(s);
		string t;
		for (char c : s) {
		    t += c == '1' ? '0' : '1';
		}
		
		vector<int> res1 = solve(s, n, k);
		vector<int> res2 = solve(t, n, k);
		
		vector<int> res;
		if (res1[0] == -1) {
            if (res2[0] == -1) {
                res = {0};
            }
            else {
                res = res2;
            }
		}
		else if (res2[0] == -1) {
		    res = res1;
		}
		else {
		    res = res1.size() < res2.size() ? res1 : res2;
		}
		
		string fin;
		range(i, 0, n) {
		    fin += '0';
		}
		for (int i : res) {
		    fin[i] = '1';
		}
		print(fin);
	}
}