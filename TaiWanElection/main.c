#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int vote_MYJ(unsigned int mid,unsigned int max) {
	unsigned long long temp = rand() * 1024;
	//printf("%u / %u [%d]", temp % max, max, temp);
	if (temp % max < mid)
		return 1;
	else 
		return 0;
}

int main() {
	srand((unsigned)time(NULL));
	//for (int i = 0; i<20; i++)
	//	printf("%d\n",rand());

	while (1) {
		int num = 0, n = 0;
		unsigned int A = 0, B = 0;
		printf("¡¾TaiWan Election¡¿\nInput Sample Num:");
		scanf("%d", &num);
		printf("Input Train Times:");
		scanf("%d", &n);
		printf("Input MYJ:");
		scanf("%u", &A);
		printf("Input XCT:");
		scanf("%u", &B);
		int tnum = 1;
		while (tnum <= num) {
			int tn = 1, MYJ_keep_first = 0;
			while (tn <= n) {
				int tA = A, tB = B, tA_ = 0, tB_ = 0, not_first = 0;
				while (tA > A - B && tB > 0) {
					if (vote_MYJ(tA, tA + tB)) {
						tA -= 1;
						tA_ += 1;
					}
					else {
						tB -= 1;
						tB_ += 1;
					}
					if (tA_ <= tB_) {
						//printf("-- XCT_FIRST: MYJ[%u] XCT[%u]\n", tA_,tB_);
						not_first = 1;
						break;
					}
				}
				if (not_first == 0) {
					//printf("++ MYJ_KEEP: MYJ[%u] XCT[%u]\n", tA_, tB_);
					MYJ_keep_first += 1;
				}
				//printf("Probability:[ %.5f ]= %d / %d\n", (float)MYJ_keep_first / tn, MYJ_keep_first, tn);
				tn++;
			}
			printf("[ %.5f ]= %d / %d\n", (float)MYJ_keep_first / tn, MYJ_keep_first, tn);
			tnum++;
		}
	}
}