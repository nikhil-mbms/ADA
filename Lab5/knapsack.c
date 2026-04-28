#include <stdio.h>

int main() {
    int capacity, no_items, cur_weight, item;
    int used[10] = {0};
    float total_profit = 0;

    int i;
    int weight[10], value[10];

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d items:\n", no_items);

    for (i = 0; i < no_items; i++) {
        printf("Weight[%d]: ", i);
        scanf("%d", &weight[i]);

        printf("Value[%d]: ", i);
        scanf("%d", &value[i]);
    }

    cur_weight = capacity;

    while (cur_weight > 0) {
        item = -1;

        for (i = 0; i < no_items; i++) {
            if (used[i] == 0 &&
               (item == -1 ||
               ((float)value[i] / weight[i] > (float)value[item] / weight[item]))) {
                item = i;
            }
        }

        used[item] = 1;

        if (weight[item] <= cur_weight) {
            cur_weight -= weight[item];
            total_profit += value[item];

            printf("Added object %d (%d Rs, %d Kg) completely. Space left: %d\n",
                   item + 1, value[item], weight[item], cur_weight);
        }
        else {
            float fraction = (float)cur_weight / weight[item];

            total_profit += value[item] * fraction;

            printf("Added %.2f%% of object %d (%d Rs, %d Kg)\n",
                   fraction * 100, item + 1, value[item], weight[item]);

            cur_weight = 0;
        }
    }

    printf("Total profit: %.2f\n", total_profit);

    return 0;
}