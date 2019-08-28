#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
//	printf("%d %s\n",argc, argv[1]);
	int n;
	int t;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &t);
//	printf("%d\n",n);
	
	if (t == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) printf("*");
			printf("\n");		
		}
	}

	if (t == 2) {
		int z = 0;
		for (int i = 1; i <= n; i++) {
			if (n & 1) {
				if (i<=(n+1)/2) z++; else z--;
			} else {
				if (i<n/2 + 1) z++;
				if (i>n/2 + 1) z--;
			}
			for (int j = 1; j <= z; j++) printf("*");
			printf("\n");		
		}
	}

	if (t == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) printf("*");
			printf("\n");		
		}
	}
	return 0;
}
