#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int isPrimeNumber(int x);			//소수 판별 함수 선언
int main() {
	int T, n, temp1 = 0, temp2 = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {	//2~n까지 소수를 판별
			if (isPrimeNumber(j) > 0) {
				for (int k = 2; k <= n - isPrimeNumber(j); k++) {	// 짝수 n = 소수+소수로 나타나기때문
					if (isPrimeNumber(k) > 0 && isPrimeNumber(j) + isPrimeNumber(k) == n && isPrimeNumber(j) <= isPrimeNumber(k))
					{
						temp1 = isPrimeNumber(j); temp2 = isPrimeNumber(k);
					}
				}
			}
		}							//3중 for문때문에 시간복잡도가 T*n*(n)급	
		printf("%d %d\n", temp1, temp2);
	}
}


int isPrimeNumber(int x) {
	int length, i = 2;
	length = sqrt(x);
	if (length == sqrt(x)) return 0;		//1을 배제하자
	while (i <= length) {
		if (x % i == 0) { return 0; }
		i += i % 2 ? 2 : 1;		//2를 제외한 짝수는 소수가 될 수 없다.
	}
	return x;
}