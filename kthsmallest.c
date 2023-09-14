//kth smallest element
#include <stdio.h>
#include <stdlib.h>

void interchange(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int l, int h) {
    int pivot = a[l], i = l, j = h + 1;
    do {
        do {
            i++;
        } while (a[i] < pivot && i <= j);
        do {
            j--;
        } while (a[j] >= pivot);
        if (i < j) {
            interchange(a, i, j);
        }
    } while (i < j);
    interchange(a, l, j);
    return j;
}

int kthSmallest(int a[], int l, int h, int k) {
    if (l <= h) {
        int j = partition(a, l, h);
        if (j == k) {
            return a[j];
        } else if (j < k) {
            return kthSmallest(a, j + 1, h, k);
        } else {
            return kthSmallest(a, l, j - 1, k);
        }
    }
    return -1; // Return -1 if k is out of bounds
}

int main() {
    int a[100], n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter K value to find the kth smallest element: ");
    scanf("%d", &k);

    if (k >= 1 && k <= n) {
        int kthSmallestElement = kthSmallest(a, 0, n - 1, k - 1);
        printf("Kth smallest element: %d\n", kthSmallestElement);
    } else {
        printf("Invalid value of K. K should be between 1 and %d\n", n);
    }

    return 0;
}
/* output:
Enter the size of the array: 5
Enter element 1: 34
Enter element 2: 23
Enter element 3: 67
Enter element 4: 90
Enter element 5: 16
Enter K value to find the kth smallest element: 3
kth smallest element: 34
output2:
Enter the size of the array: 5
Enter element 1: 12
Enter element 2: 13
Enter element 3: 9
Enter element 4: 8
Enter element 5: 7
Enter K value to find the kth smallest element: 1
kth smallest element: 7
