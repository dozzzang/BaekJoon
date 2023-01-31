#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isPrimeNumber(int x);	//소수 판별 함수 선언

int main() {
	int N, T, x = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int* arr = (int*)malloc(sizeof(int) * (N + 1));	//배열의 index를 실제 값으로 생각할 것이기 때문에 배열의 크기는 (N+1)
		for (int j = 2; j <= N / 2; j++) {	// N / 2까지 범위를 설정함으로써 j <= (N - j)가 성립되어 작은 소수부터 출력
			arr[j] = isPrimeNumber(j);	//isPrimeNumber함수에 의해 index가 소수라면 배열의 값을 1로 초기화
			if (arr[j] == 1 && isPrimeNumber(N - j) == 1)	//j가 소수로 확정났다면 다른 한 수 N-j만 소수면 됨
				x = j;										//반복문이 계속 돌기 때문에 결국 합을 구성하는 소수의 차가 가장 적게 될 것.
		}
		printf("%d %d\n",x, N - x);
		free(arr);	//1차원 배열 동적할당 해제
	}

	return 0;
}


int isPrimeNumber(int x) {
	double length;
	length = sqrt(x);
	for (int i = 2; i <= length; i++) {
		if (x % i == 0) return 0;	//소수가 아니면 0을 리턴
	}
	return 1;	//소수는 1을 리턴
}