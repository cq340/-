/**
* The problem:
* 从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的（网易）。
* use binary search, perhaps you should compile it with -std=c99
* fairywell 2011
*/
#include <stdio.h>

#define MAX_NUM    (1U<<31)

int
main()
{
	int i, n, low, high, mid, max;

	printf("Input how many numbers there are: ");
	scanf("%d/n", &n);
	/* a[] holds the numbers, b[i] holds the number of increasing numbers
	* from a[0] to a[i], c[i] holds the number of increasing numbers
	* from a[n-1] to a[i]
	* inc[] holds the increasing numbers
	* VLA needs c99 features, compile with -stc=c99
	*/
	double a[n], b[n], c[n], inc[n];

	printf("Please input the numbers:/n");
	for (i = 0; i < n; ++i) scanf("%lf", &a[i]);

	// update array b from left to right
	for (i = 0; i < n; ++i) inc[i] = (unsigned)MAX_NUM;
	//b[0] = 0;
	for (i = 0; i < n; ++i) {
		low = 0; high = i;
		while (low < high) {
			mid = low + (high - low)*0.5;
			if (inc[mid] < a[i]) low = mid + 1;
			else high = mid;
		}
		b[i] = low + 1;
		inc[low] = a[i];
	}

	// update array c from right to left
	for (i = 0; i < n; ++i) inc[i] = (unsigned)MAX_NUM;
	//c[0] = 0;
	for (i = n - 1; i >= 0; --i) {
		low = 0; high = i;
		while (low < high) {
			mid = low + (high - low)*0.5;
			if (inc[mid] < a[i]) low = mid + 1;
			else high = mid;
		}
		c[i] = low + 1;
		inc[low] = a[i];
	}

	max = 0;
	for (i = 0; i < n; ++i)
	if (b[i] + c[i] > max) max = b[i] + c[i];
	printf("%d number(s) should be erased at least./n", n + 1 - max);
	return 0;
}