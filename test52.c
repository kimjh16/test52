#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 7    // 마방진 크기

int main()
{
	int arr[N][N] = { 0 };

	int row = 0;   // 시작 행
	int column = N / 2; // 시작 열

	for (int num = 1; num <= N * N; num++)
	{
		arr[row][column] = num;

		int next_row = (row - 1 + N) % N;
		int next_column = (column + 1) % N;

		if (arr[next_row][next_column] == 0) 
		{
			row = next_row;
			column = next_column;
		}
		else
		{
			row = (row + 1) % N;
		}
	}

	for (int i = 0; i < N; i++) // 마방진 출력
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("가로 합: \n");
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum += arr[i][j];
		}
		printf("row %d = %d\n", i, sum);
	}
	printf("세로 합: \n");
	for (int j = 0; j < N; j++)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += arr[i][j];
		}
		printf("column %d = %d\n", j, sum);
	}

	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < N; i++)
	{
		sum1 += arr[i][i];
		sum2 += arr[i][N - 1 - i];
	}
	printf("왼쪽 대각선: %d\n", sum1);
	printf("오른쪽 대각선: %d\n", sum2);

	return 0;

}