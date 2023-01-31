#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isPrimeNumber(int x);	//�Ҽ� �Ǻ� �Լ� ����

int main() {
	int N, T, x = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int* arr = (int*)malloc(sizeof(int) * (N + 1));	//�迭�� index�� ���� ������ ������ ���̱� ������ �迭�� ũ��� (N+1)
		for (int j = 2; j <= N / 2; j++) {	// N / 2���� ������ ���������ν� j <= (N - j)�� �����Ǿ� ���� �Ҽ����� ���
			arr[j] = isPrimeNumber(j);	//isPrimeNumber�Լ��� ���� index�� �Ҽ���� �迭�� ���� 1�� �ʱ�ȭ
			if (arr[j] == 1 && isPrimeNumber(N - j) == 1)	//j�� �Ҽ��� Ȯ�����ٸ� �ٸ� �� �� N-j�� �Ҽ��� ��
				x = j;										//�ݺ����� ��� ���� ������ �ᱹ ���� �����ϴ� �Ҽ��� ���� ���� ���� �� ��.
		}
		printf("%d %d\n",x, N - x);
		free(arr);	//1���� �迭 �����Ҵ� ����
	}

	return 0;
}


int isPrimeNumber(int x) {
	double length;
	length = sqrt(x);
	for (int i = 2; i <= length; i++) {
		if (x % i == 0) return 0;	//�Ҽ��� �ƴϸ� 0�� ����
	}
	return 1;	//�Ҽ��� 1�� ����
}