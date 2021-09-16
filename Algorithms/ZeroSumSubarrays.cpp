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
    //Input
    input(int, n);
    arrput(int, a, n);

    int prefSum[n + 1];
    prefSum[0] = 0;
    range(i, 0, n) {
        prefSum[i + 1] = prefSum[i] + a[i];
    }

    int res = 0;
    unordered_map<int, int> count;
    count.emplace(0, 1);
    range(i, 1, n + 1) {
        if (count.find(-prefSum[i]) != count.end()) {
            res += count.at(-prefSum[i]);
        }

        if (count.find(prefSum[i]) == count.end()) {
            count.emplace(prefSum[i], 1);
        }
        else {
            count.emplace(prefSum[i], count.at(prefSum[i]) + 1);
        }
    }

    print(res);
}