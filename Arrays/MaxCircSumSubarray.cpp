#include <iostream>
#include <cmath>
using namespace std;


int normalMaxSum(int arr[], int n)
{
	int res = arr[0];

	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}

	return res;
}

int overallMaxSum(int arr[], int n)
{
	int max_normal = normalMaxSum(arr, n);
  // to account for the corner case where every element in the array is negative
	if(max_normal < 0)
		return max_normal;

	int arr_sum = 0;
  // The array is inverted meaning the sign of the elements are changed, so the max sum of subarray after inversion becomes
  // the min sum of subarray.
  // if max sum = 8 then after inversion it becomes
	for(int i = 0; i < n; i++)
	{
		arr_sum += arr[i];

		arr[i] = -arr[i];
	}
  // the min sum of subarray is added from the sum of the array to get the final result.
	int max_circular = arr_sum + normalMaxSum(arr, n);

	return max(max_circular, max_normal);
}



int main() {

     int arr[] = {8, -4, 3, -5, 4}, n = 5;

     cout<<overallMaxSum(arr, n);

}
