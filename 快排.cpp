#define   _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdlib.h>

void QuickSort(int *A, int left, int right)

{
	if (left >= right)
		return;
	int x = A[(left + right) >> 1];
	int low = left, high = right;
	while (low < high)
	{
		while (A[low] < x)
			low++;
		while (A[high]>x)
			high--;
		if (low <= high)
		{
			int temp = A[low];
			A[low] = A[high];
			A[high] = temp;
			low++;
			high--;
		}
	}
	QuickSort(A, left, high);
	QuickSort(A, low, right);



}





int main()

{
	int length, i, r[10000];
	scanf("%d", &length);
	for (i = 1; i <= length; i++)
		scanf("%d", &r[i]);
	QuickSort(r, 1, length);
	for (i = 1; i <= length; i++)
		printf(" %d", r[i]);
	printf("\n");
	system("pause");
	return 0;
}
