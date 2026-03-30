#include <stdio.h>

int main() {
    int n, key, i, found = -1;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &key);
  
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        printf("found at position %d\n", found);
    } else {
        printf("%d not found\n", key);
    }
    return 0;
}
