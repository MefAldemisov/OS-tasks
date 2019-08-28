/* *
* Author: Bogdanova Alina BS 18-04
* Date: 28.08.19
* Description: Max values and sizes of variables of type:
* - int
* - float
* - double
*/
#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
	int i;
	float f;
	double d;

	i = INT_MAX;
	
	f = FLT_MAX;
	d = DBL_MAX;

	printf("Max value\tSize\n%d\t%ld\n%f\t%ld\n%lf\t%ld", i, sizeof(i), f, sizeof(f), d, sizeof(d));

	return 0;
}
