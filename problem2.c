#include <stdio.h>

void combinations(int score) {
    int numCombinations = 0;

    for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (int td_fg = 0; td_fg * 7 + td_2pt * 8 <= score; td_fg++) {
            for (int td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= score; td++) {
                for (int fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; fg++) {
                    int check = score - (fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8);
                    if (check % 2 == 0) {
                        int safety = check / 2;
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",td_2pt, td_fg, td, fg, safety);
                        numCombinations++;
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }
        printf("Possible combinations of scoring plays:\n");
        combinations(score);
    }
    return 0;
}

