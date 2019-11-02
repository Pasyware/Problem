#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long long exponent(unsigned long long base, int power) {
	int i;
	unsigned long long j = 1;
	for (i = 0; i < power; i++) {
		j = j * base;
	}
	//printf("(%llu[%i])%llu\n",base, power, j);
	return j;
}

int check_sum_strange(int num, int count, int *factor) {
	unsigned long long i, j;
	int p, q;
	if (count > 64) {
		printf("%d [%d] OverFlow\n", num, count);
		return 0;
	}
	for (i = exponent(2,count) - 1; i > 0; i--) {
		j = i;
		q = 0;
		for (p = 0; p < count; p++) {
			q += (j % 2) * factor[p];
			if (q > num)break;
			j = j / 2;
		}
		if (q == num) {
			/*j = i;
			printf("%d [%d]\n{ ",num,count);
			for (p = 0; p < count; p++) {
				if (j % 2)printf("%d ",factor[p]);
				j = j / 2;
			}
			printf("}\n");*/
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j, p, sum_all, Maxnum=0, ResultNum=0;
	int factor[1024] = { 0 };
	int Result[1024] = { 0 };
	//for (i = 0; i < 100; i++)exponent(2, i);
	while (true) {
		ResultNum = 0;
		printf("【StrangeCaculator】\nInput Maxnum:");
		scanf("%d", &Maxnum);
		printf("Start Seaching...\n");
		for (i = 1; i <= Maxnum; i++) {
			factor[0] = 1;
			sum_all = 1;
			p = 1;
			for (j = 2; j <= sqrt(i); j++) {
				if (i%j == 0) {
					factor[p] = j;
					factor[p + 1] = i / j;
					sum_all += j + i / j;
					p += 2;
				}
			}
			if (i == factor[p - 1] * factor[p - 1]) {
				p -= 1;
				sum_all -= factor[p];
			}
			if (sum_all > i) {
				if (check_sum_strange(i, p, factor)) {
					Result[ResultNum] = i;
					ResultNum += 1;
					printf("%d [%d] { ", i, p);
					for (j = 0; j < p; j++)printf("%d ", factor[j]);
					printf("}\n");
				}
			}
		}
		printf("Over\n");
		printf("Strange{ ");
		for (i = 0; i < ResultNum; i++) {
			printf("%d ", Result[i]);
		}
		printf("}\n\n");
	}
    return 0;
}

