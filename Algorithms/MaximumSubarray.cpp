#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, k);
    arrput(int, a, n);

    multiset<int, greater<int>> m;
    range(i, 0, k) {
        m.insert(a[i]);
    }

    range(i, 0, n - k) {
        printf("%d ", m.begin());
        m.erase(a[i]);
        m.insert(a[i + k]);
    }
}