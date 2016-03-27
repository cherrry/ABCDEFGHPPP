#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIAL 1000000

int x[9];

void randomize() {
    int i, j, y;
    for (i = 0; i < 9; i++) {
        int ok = 0;
        while (!ok) {
            x[i] = rand() % 10;
            ok = 1;
            for (j = 0; j < i; j++) {
                ok = ok && x[i] != x[j];
            }
        }
    }
}

int correct() {
    int i, ab, cd, ef, gh, ppp;

    ab = x[0] * 10 + x[1];
    cd = x[2] * 10 + x[3];
    ef = x[4] * 10 + x[5];
    gh = x[6] * 10 + x[7];
    ppp = x[8] * 111;
    return (ab - cd) == ef && (ef + gh) == ppp;
}

int main() {
    int t;
    do {
        randomize();
        t++;
    } while (!correct() && t <= MAX_TRIAL);

    if (correct()) {
        printf("Answer found at #%d trial%s.\n", t, t == 1 ? "": "s");
        printf(
            "%1$d%2$d - %3$d%4$d = %5$d%6$d, %5$d%6$d + %7$d%8$d = %9$d%9$d%9$d\n",
            x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8]
        );
    } else {
        puts("I'm too stupid.");
    }

    return 0;
}
