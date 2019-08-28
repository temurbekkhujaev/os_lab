#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
//	printf("%d %s\n",argc, argv[1]);
	int n;
	sscanf(argv[1], "%d", &n);
//	printf("%d\n",n);
	
	for (int i = 1; i <= n; i++) {
		int cnt = (i - 1) * 2 + 1;
		for (int j = 1; j <= (2 * n - 1 - cnt) / 2; j++) printf(" ");

		for (int j = 1; j <= cnt; j++) printf("*");

		for (int j = 1; j <= (2 * n - 1 - cnt) / 2; j++) printf(" ");
		printf("\n");		
	}


	return 0;
}
