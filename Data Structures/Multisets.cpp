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
    multiset<int> multiSet;
    multiSet.insert(6);
    multiSet.insert(65);
    multiSet.insert(16);
    multiSet.insert(65);
    
    for (int i: multiSet) {
        print(i);
    }

    print(multiSet.count(65));
    multiSet.erase(16);

    multiSet.clear();
    if (multiSet.empty()) {
        println("The multiset is empty");
    }
    else {
        println("The multiset is not empty");
    }
}