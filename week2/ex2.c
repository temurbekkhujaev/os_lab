#include <stdio.h>
#include <string.h>

int main() {
	char s[1000];
	
	scanf("%s",s);
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++ ) {
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
	printf("%s",s);


	return 0;
}
