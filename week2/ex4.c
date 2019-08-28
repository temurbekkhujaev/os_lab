#include <stdio.h>
#include <string.h>

void swap(char **a, char ** b) {
	char *c = *a;
	*a = *b;
	*b = c;
}
int main(int argc, char ** argv) {

	printf("Enter two strings in new line: \n");
	char a[1000], b[1000];
	scanf("%s %s",a,b);
	swap(&a, &b);
	printf("%s %s\n", a, b);
	return 0;
}
