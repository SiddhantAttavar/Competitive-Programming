#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
    setup();
    input(int, tc); while (tc--) {
        input(string, str);        
        unordered_map<char, int> map;
        range(i, 0, str.size()) {
            char c = str.at(i);
            if (map.find(c) == map.end()) {
                map[c] = 1;
            }
            else {
                map[c]++;
            }
        }

        int a = 0, b = 0;
        for (pair<char, int> p: map) {
            a += p.second / 2;
            b += p.second % 2;
        }

        int res = min(a, b);
        a -= min(a, b);
        res += (a * 2) / 3;
        print(res);
    }
}