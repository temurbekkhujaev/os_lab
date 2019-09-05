#include <stdio.h>


int cmp(int a, int b) {
    return (a < b);
}

void bubble_sort(int a[], int n, int (*f)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f(a[j + 1], a[j])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    bubble_sort(a, n, cmp);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
