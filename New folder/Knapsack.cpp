#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int wt[], int val[], int n, int& steps)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            steps++; // Increment step for each comparison

            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                steps += 3; // Increment steps for max, addition, and array access
            }
            else
            {
                K[i][w] = K[i - 1][w];
                steps++; // Increment step for array access
            }
        }
    }

    return K[n][W];
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int val[n], wt[n];
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int steps = 0; // Counter for steps

    int result = knapsack(W, wt, val, n, steps);

    cout << "Maximum value that can be obtained: " << result << endl;
    cout << "Total steps taken: " << steps << endl;

    return 0;
}
