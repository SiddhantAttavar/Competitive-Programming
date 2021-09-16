#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    unordered_set<char> set;
    range(i, 0, str.size()) {
        set.insert(str[i]);
    }

    string res;
    range(i, 65, 91) {
        if (set.find(char(i)) == set.end()) {
            res.push_back(char(i));
        }
    }

    println(res.c_str());
}