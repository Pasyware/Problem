#include <stdio.h>
#include <math.h>
#include <string.h>
 
#define TRUE 1
#define FALSE 0
#define MAX_NUM 200
 
int strangeNumber(int);// 判断是否是奇怪数
 
int sum;// 因子的和
int factor[MAX_NUM];// 保存因子
int factorNum;// 因子个数
int abundantNumber(int);// 判断是否是盈数
 
int back(int, int);// 回溯判断是否有子集的和是num
 
int main(void) {
	while(TRUE){
		int i,Max=0,ResultNum=0;
		int Result[1000];
		printf("【StrangCalculator】\nInput Maxnum:");
		if(scanf("%d",&Max)!=1)continue;
		for (i = 1; i <= Max; ++i) {
			if (TRUE == strangeNumber(i)) {
				Result[ResultNum] = i;
				ResultNum += 1;
				printf("is Strange\n");
			}
		}
		printf("Strange{ ");
		for (i = 0; i <ResultNum;i++){
			printf("%d ",Result[i]);
		}
		printf("}\n");
	}
	return 0;
}
 
int strangeNumber(int num) {
    if (FALSE == abundantNumber(num)) {
        return FALSE;// 不是盈数，即不是奇怪数
    }
	printf("【%d】 ",num);
    if (FALSE == back(0, num)) {
		printf("}\n");
        return FALSE;// 存在子集的和为num，即不是奇怪数
    }
    return TRUE;
}
 
int abundantNumber(int num) {
    // 初始化
    memset(factor, 0, sizeof(factor));
    factorNum = 0;
    factor[factorNum++] = 1;// 1肯定是因子
    sum = 1;
    int max = (int)sqrt(num);
    // 循环找到num的所有因子
    int i;
    for (i = 2; i <= max; ++i) {
        if (0 == num % i) {
            factor[factorNum++] = i;
            factor[factorNum++] = num / i;
            sum += i + num / i;
        }
    }
    // num是开方数，那么循环里面max加了两遍，要减掉多余的
    if (max * max == num) {
        --factorNum;
        sum -= max;
    }
    return sum <= num ? FALSE : TRUE;
}
 
int back(int index, int left) {
    if (index >= factorNum) {
		if(0 == left){
			printf("{ ");
			return FALSE;
		}
        return TRUE;
    }
    if (FALSE == back(index + 1, left)) {// 不选择第index个数
        return FALSE;
    }
    // 选择第index个数，剩余的减去当前数
	if (FALSE == back(index + 1, left - factor[index])) {
		printf("%d ",factor[index]);
        return FALSE;
    }
    return TRUE;
}