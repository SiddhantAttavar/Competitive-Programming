#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
	    string s1, s2, s3;
	    input(s1);
	    input(s2);
	    input(s3);
	    
	    unordered_map<char, int> m1, m2, m3;
	    for (char c : s1) {
	        m1[c]++;
	    }
	    for (char c : s2) {
	        m2[c]++;
	    }
	    for (char c : s3) {
	        m3[c]++;
	    }
	    
	    if (m2.size() != m1.size() || m3.size() != m1.size()) {
	        print("Not Possible");
	        continue;
	    }
	    
	    bool flag = true;
	    for (pair<char, int> p : m1) {
	        if (m2.find(p.first) == m2.end() || m3.find(p.first) == m3.end() || p.second != m2[p.first] || p.second != m3[p.first]) {
	            flag = false;
	            break;
	        }
	    }
	    
	    print((flag ? "Possible" : "Not Possible"));
	}
}