/* Student Score Analyzer
 * A tiny, friendly utility: you tell it how many scores you'll enter,
 * then type that many integers. It prints the average (to 1 decimal),
 * the highest score, and the lowest score. Simple and straightforward.
 */

#include <stdio.h>
#include <stdlib.h>

/* Compute the arithmetic mean of `count` integers in `scores` and
 * return it as a float. We sum with a `long` to be a little safer
 * against overflow when there are many elements.
 */
float calculate_average(const int scores[], int count);

/* Return the largest value found in the array. Assumes count >= 1. */
int find_maximum(const int scores[], int count);

/* Return the smallest value found in the array. Assumes count >= 1. */
int find_minimum(const int scores[], int count);

int main(void) {
    int n = 0;

    /* Read how many scores the user will enter. */
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Input error: expected an integer.\n");
        return 1;
    }
    if (n <= 0) {
        fprintf(stderr, "Please enter a positive number of students (got %d).\n", n);
        return 1;
    }

    /* Allocate space for the scores. Don't forget to free it below. */
    int *scores = malloc((size_t)n * sizeof *scores);
    if (scores == NULL) {
        fprintf(stderr, "Memory allocation failed for %d scores.\n", n);
        return 1;
    }

    /* Read each score, one integer per input. If anything goes wrong
     * (non-integer input), print a brief message and exit cleanly.
     */
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            fprintf(stderr, "Failed to read score #%d. Aborting.\n", i + 1);
            free(scores);
            return 1;
        }
    }

    /* Compute simple stats and print a compact summary. */
    float average = calculate_average(scores, n);
    int highest = find_maximum(scores, n);
    int lowest = find_minimum(scores, n);

    printf("\n--- Score Summary ---\n");
    printf("Class Average : %.1f\n", average);
    printf("Highest Score : %d\n", highest);
    printf("Lowest Score  : %d\n", lowest);

    free(scores);
    return 0;
}

float calculate_average(const int scores[], int count) {
    long sum = 0;
    for (int i = 0; i < count; i++)
        sum += scores[i];
    return (float)sum / (float)count;
}

int find_maximum(const int scores[], int count) {
    int max = scores[0];
    for (int i = 1; i < count; i++)
        if (scores[i] > max)
            max = scores[i];
    return max;
}

int find_minimum(const int scores[], int count) {
    int min = scores[0];
    for (int i = 1; i < count; i++)
        if (scores[i] < min)
            min = scores[i];
    return min;
}