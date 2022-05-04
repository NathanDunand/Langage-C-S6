#include <stdio.h>
void main()
{
	int i, j, k, tmp;		  // 1
	int *pi, *pj, *pk, *ptmp; // 2

	i = 31;
	j = 52;
	k = 17; // 3
	pi = &i;
	pj = &j;
	pk = &k; // 4

	printf("i=%d j=%d k=%d\n", i, j, k);
	printf("*pi=%d *pj=%d *pk=%d\n", *pi, *pj, *pk);

	tmp = *pi; // 5
	*pi = *pj; // 6
	*pj = *pk; // 7
	*pk = tmp; // 8

	printf("i=%d j=%d k=%d\n", i, j, k);
	printf("*pi=%d *pj=%d *pk=%d\n", *pi, *pj, *pk);

	ptmp = pi; // 9
	pi = pj;   // 10
	pj = pk;   // 11
	pk = ptmp; // 12

	printf("i=%d j=%d k=%d\n", i, j, k);
	printf("*pi=%d *pj=%d *pk=%d\n", *pi, *pj, *pk);
}
