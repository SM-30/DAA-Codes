#include <stdio.h>
#include <math.h>
long long_int_mult(long, long);
long digit_count(long, long);

int main() {
	long x, y;
	
	printf("\n Enter first number: ");
	scanf("%ld", &x);
	printf("\n Enter second number: ");
	scanf("%ld", &y);
	
	printf("\n %ld * %ld = %ld", x, y, long_int_mult(x, y));
}

long long_int_mult(long a, long b) {
	long a0, a1, b0, b1;
	long c0, c1, c2;
	
	long n = digit_count(a, b);
	
	if(n<=2)
		return (a*b);
	else {
		long m = floor(n/2);
		
		a0 = a%(int)pow(10, m);
		a1 = a/pow(10, m);
		b0 = b%(int)pow(10, m);
		b1 = b/pow(10, m);
		
		c2 = long_int_mult(a1, b1);
		c0 = long_int_mult(a0, b0);
		c1 = long_int_mult(a1+a0, b1+b0);
		
		return c2*pow(10, 2*m) + (c1-c0-c2)*pow(10, m) + c0;
	}
}

long digit_count(long a, long b) {
	long num, count=0;
	
	if(a>=b)
		num = a;
	else
		num = b;
	
	while(num>0) {
		num/=10;
		count++;
	}
	return count;
}
