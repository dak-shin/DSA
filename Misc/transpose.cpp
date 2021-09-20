#include<iostream>
using namespace std;

int** trans(int** arr, int r, int c)
{
    int** arr1 = new int*[c];
    for (int i = 0; i < c; i++)
        arr1[i] = new int[r];

      for (int i = 0; i < r; i++)
      {
          for (int j = 0; j < c; j++)
          {
            arr1[j][i] = arr[i][j];
              cout << arr[i][j] << " ";
          }
          cout << endl;
      }

    for (int i = 0; i < c; i++)
    {

        for (int j = 0; j < r; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    return arr1;
}

void trans()
{}

int main()
{
    int** arr = new int* [5];


    int r, c;
    cout << "Enter the size of the 2d array : " << endl;
    cin >> r >> c;


    for (int i = 0; i < r; i++)
        arr[i] = new int[c];

    cout << "Enter the elements of the 2d array row wise : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    trans(arr, r, c);

}
