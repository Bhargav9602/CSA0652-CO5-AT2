#include <stdio.h>

#define MAX 20

int set[MAX];
int subset[MAX];
int n;

// Backtracking function
void generateEvenSubsets(int pos, int size)
{
    int i;

    // If all elements are processed
    if (pos == n)
    {
        if (size % 2 == 0)
        {
            printf("{ ");
            for (i = 0; i < size; i++)
                printf("%d ", subset[i]);
            printf("}\n");
        }
        return;
    }

    // Include current element
    subset[size] = set[pos];
    generateEvenSubsets(pos + 1, size + 1);

    // Exclude current element
    generateEvenSubsets(pos + 1, size);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("\nEven-sized subsets are:\n");

    generateEvenSubsets(0, 0);

    return 0;
}
