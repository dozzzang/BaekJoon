#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int isPrimeNumber(int x);			//�Ҽ� �Ǻ� �Լ� ����
int main() {
	int T, n, temp1 = 0, temp2 = 0;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {	//2~n���� �Ҽ��� �Ǻ�
			if (isPrimeNumber(j) > 0) {
				for (int k = 2; k <= n - isPrimeNumber(j); k++) {	// ¦�� n = �Ҽ�+�Ҽ��� ��Ÿ���⶧��
					if (isPrimeNumber(k) > 0 && isPrimeNumber(j) + isPrimeNumber(k) == n && isPrimeNumber(j) <= isPrimeNumber(k))
					{
						temp1 = isPrimeNumber(j); temp2 = isPrimeNumber(k);
					}
				}
			}
		}							//3�� for�������� �ð����⵵�� T*n*(n)��	
		printf("%d %d\n", temp1, temp2);
	}
}


int isPrimeNumber(int x) {
	int length, i = 2;
	length = sqrt(x);
	if (length == sqrt(x)) return 0;		//1�� ��������
	while (i <= length) {
		if (x % i == 0) { return 0; }
		i += i % 2 ? 2 : 1;		//2�� ������ ¦���� �Ҽ��� �� �� ����.
	}
	return x;
}