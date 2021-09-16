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
    
    int res[n];

    //Find the answer for k = 0
    int currMax = a[0] + n;
    range(i, 1, n) {
        currMax = max(currMax, a[i] + i);
    }
    res[0] = currMax;

    //Find the answer for 1 <= k < n
    range(i, 1, n) {
        currMax = max(a[i] + n, currMax - 1);
        res[i] = currMax;
    }

    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
}