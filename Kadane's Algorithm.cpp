#include <iostream>
using namespace std;
int kadane(int arr[], int n)
{

    int max_so_far = 0;
    int max_ending_here = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];

        max_ending_here = max(max_ending_here, 0);

        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; 
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The maximum sum of a contiguous subarray is " <<
            kadane(arr, n);

    return 0;
}
