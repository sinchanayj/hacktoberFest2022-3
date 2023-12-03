#include <stdio.h>
#include <stdlib.h>

void findMajorityElements(int *nums, int numsSize) {
    if (numsSize == 0) {
        return;
    }

    // Initialize candidates and their counts
    int candidate1 = INT_MIN, count1 = 0;
    int candidate2 = INT_MIN, count2 = 0;

    // Find candidates
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Verify candidates and count occurrences
    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Print elements appearing more than ⌊ n/3 ⌋ times
    if (count1 > numsSize / 3) {
        printf("%d ", candidate1);
    }
    if (count2 > numsSize / 3) {
        printf("%d ", candidate2);
    }
}

int main() {
    int nums[50000]; // Assuming the maximum length of the array is 50000
    int numsSize;

    // Read array size
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    // Read array elements
    printf("Enter the array elements separated by commas: ");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
        if (i < numsSize - 1) {
            // Consume the comma
            getchar();
        }
    }

    printf("Elements appearing more than ⌊ n/3 ⌋ times: ");
    findMajorityElements(nums, numsSize);

    return 0;
}
