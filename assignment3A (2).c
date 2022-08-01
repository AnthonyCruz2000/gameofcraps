#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void roll(int* dice_one, int* dice_two) {
	*dice_one = rand() % 6 + 1;
	*dice_two = rand() % 6 + 1;
}

void win_display(int* count_win) {
	for (int i = 0; i < 12; i++) {
		printf("Total win at roll %d : %d\n", i + 1, count_win[i]);
	}
	printf("Total win after roll 12 : %d\n", count_win[12]);

}

void loose_display(int* count_loose) {
	for (int i = 0; i < 12; i++) {
		printf("Total win at roll %d : %d\n", i + 1, count_loose[i]);
	}
	printf("Total loose after roll 12 : %d\n", count_loose[12]);
}

int main() {
	int dice_one, dice_two;
	int n;		scanf("%d", &n);
	int _ = n;
	int count_win[13] = {0};
	int count_loose[13] = {0};
	srand(time(0));
	while (n--) {
		printf("Iteration : %d\n", _ - n);
		bool win;		int t_roll = 0;
		roll(&dice_one, &dice_two);		t_roll++;
		printf("%d%d\n", dice_one, dice_two);
		int total = dice_one + dice_two;
		if (total == 7 || total == 11) {
			win = true;
		}
		else if (total == 2 || total == 3 || total == 12) {
			win = false;
		}
		else {
			int point = total;
			roll(&dice_one, &dice_two);		t_roll++;
			printf("%d%d\n", dice_one, dice_two);
			total = dice_one + dice_two;
			while (point != total) {
				if (total == 7) {
					win = false;
					break;
				}
				point = total;
				roll(&dice_one, &dice_two);		t_roll++;
				printf("%d%d\n", dice_one, dice_two);
				total = dice_one + dice_two;
			}
			if (point == total) {
				win = true;
			}
		}
		printf("\n");
		if (win == true) {
			if (t_roll <= 12) {		count_win[t_roll - 1] += 1;		}
			else {		count_win[12] += 1;		}
		}
		else {
			if (t_roll <= 12) {		count_loose[t_roll - 1] += 1;		}
			else {		count_loose[12] += 1;		}
		}
	}
	int t_win = 0, t_loose = 0;
	int length = 0;
	for (int i = 0; i < 13; i++) {
		t_win += count_win[i];
		t_loose += count_loose[i];
		length += (t_win + t_loose);
	}
	win_display(count_win);		printf("\n");
	loose_display(count_loose);		printf("\n");
	printf("Chances of Winning : %.2f %% \n", ((t_win / (_ * 1.0)) * 100));
	printf("Average length : %.2f\n", (length / (_ * 1.0)));
	return 0;
}
