#include <stdio.h>
#include <limits.h>
#include <float.h>
int main( ){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	
	
	printf("integer: size = %d,\t value = %d \n",sizeof(a), a); 
	printf("float  : size = %d,\t value = %.15f \n",sizeof(b), b); 
	printf("double : size = %d,\t value = %.15f \n",sizeof(c), c); 

	return 0;
}
