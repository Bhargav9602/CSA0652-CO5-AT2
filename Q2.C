#include <stdio.h>

#define MAX 20

int set[MAX];
int subset[MAX];
int n, k;

// Backtracking function
void generateSubsets(int index, int start)
{
    int i;

    // If subset size becomes k, print it
    if (index == k)
    {
        printf("{ ");
        for (i = 0; i < k; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    // Pruning: Not enough elements left
    if (n - start < k - index)
        return;

    // Try each remaining element
    for (i = start; i < n; i++)
    {
        subset[index] = set[i];
        generateSubsets(index + 1, i + 1);
    }
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter subset size (k): ");
    scanf("%d", &k);

    if (k > n || k < 0)
    {
        printf("Invalid value of k.\n");
        return 0;
    }

    printf("\nSubsets of size %d are:\n", k);

    generateSubsets(0, 0);

    return 0;
}
