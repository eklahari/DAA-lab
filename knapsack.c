#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int profit;
    double ratio;
    int order;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(struct Item items[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double knapsack(struct Item items[], int n, int capacity) {
    int currentweight = 0;
    double totalprofit = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentweight + items[i].weight <= capacity) {
            currentweight += items[i].weight;
            totalprofit += items[i].profit;
            printf("|item %d|->", items[i].order);
        } else {
            double remainingcapacity = capacity - currentweight;
            totalprofit += (remainingcapacity / items[i].weight) * items[i].profit;
            printf("|item %d|", items[i].order);
            break;
        }
    }

    return totalprofit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items you want to read: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter each item profit and weight:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (double)items[i].profit / items[i].weight;
        items[i].order = i + 1;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    bubblesort(items, n);

    printf("The sequence of items: ");
    double maxprofit = knapsack(items, n, capacity);
    printf("\nMaximum profit = %.2lf\n", maxprofit);

    return 0;
}

/* output1:
Enter the number of items you want to read: 3
Enter each item profit and weight:
Item 1: 25 18
Item 2: 24 15
Item 3: 15 10
Enter the capacity of the knapsack: 20
The sequence of items: |item 2|->|item 3|
Maximum profit = 31.50
output2:
Enter the number of items you want to read: 7
Enter each item profit and weight:
Item 1: 10 2
Item 2: 5 3
Item 3: 15 5
Item 4: 7 7
Item 5: 6 1
Item 6: 18 4
Item 7: 3 1
Enter the capacity of the knapsack: 15
The sequence of items: |item 5|->|item 1|->|item 6|->|item 3|->|item 7|->|item 2|
Maximum profit = 55.33 */
