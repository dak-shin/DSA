#include <iostream>

using namespace std;
int main()
{
    int arr[] = {10, 3, 4, 2, 234, 5, 44, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";

        cout << endl;
    }

}
