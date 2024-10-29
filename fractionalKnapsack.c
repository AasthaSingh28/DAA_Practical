#include <stdio.h>

// Function to calculate the maximum value for the fractional knapsack
double fractionalKnapsack(int W, int n, int value[], int weight[]) {
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= W) {
            W -= weight[i];                // Take the whole item
            totalValue += value[i];
        } else {
            totalValue += value[i] * ((double)W / weight[i]);  // Take fraction of the item
            break;  // Knapsack is full
        }
    }
    
    return totalValue;
}

int main() {
    int n, W;

    // Input the number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int value[n], weight[n];

    // Input the value and weight of each item
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &value[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weight[i]);
    }

    double maxValue = fractionalKnapsack(W, n, value, weight);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
