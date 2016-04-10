#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define MAX_TRIALS 5516431 // 99.95% getting correct answer

using namespace std;

#define X(a, b) (x[a]*10+x[b])
int x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int correct() {
    int ab = X(0, 1), cd = X(2, 3), ef = X(4, 5), gh = X(6, 7), ppp = x[8] * 111;
    return (
        (ab >= 10 && cd >= 10 && ef >= 10 && gh >= 10) &&
        (ab - cd) == ef &&
        (ef + gh) == ppp
    );
}

int main() {
    int t = 1;
    for (; t <= MAX_TRIALS && !correct(); t++) {
        random_shuffle(x, x + 10);
    }

    if (correct()) {
        printf("Answer found at #%d trial%s.\n", t, t == 1 ? "": "s");
        int ab = X(0, 1), cd = X(2, 3), ef = X(4, 5), gh = X(6, 7), ppp = x[8] * 111;
        printf("%d - %d = %d, %d + %d = %d\n", ab, cd, ef, ef, gh, ppp);
    } else {
        puts("I'm so stupid. :(");
    }

    return 0;
}
