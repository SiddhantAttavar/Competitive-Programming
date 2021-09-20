#include <bits/stdc++.h>
using namespace std;
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
    unordered_set<int> hashSet;
    range(i, 10) {
        hashSet.insert(2 * i);
        hashSet.insert(i * i);
    }

    for (int i: hashSet) {
        print(i);
    }

    if (hashSet.find(51) == hashSet.end()) {
        println("51 is not in the hash set");
    }
    else {
        println("51 is in the hash set");
    }
}