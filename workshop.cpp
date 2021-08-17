
#include<iostream>
using namespace std;

//Define the structs Workshops and .
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshops
{
    int st; int dur; int et;

};
struct Available_Workshops
{
    int n;
    Workshops* arr;

}aw;
Available_Workshops* initialize(int start_time[], int duration[], int n)
{

    struct Workshops ws[50];
    for (int i = 0; i < n; i++)
    {
        ws[i].st = start_time[i];
        ws[i].dur = duration[i];
        ws[i].et = start_time[i] + duration[i];
    }

    aw.arr = ws;
    aw.n = n;
    cout << "done init";
    return &aw;
}
Workshops* sort(Workshops* arr, int n)
{
    struct Workshops key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j].st > key.st; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
    return arr;
}
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    Workshops* old_arr = ptr->arr;
    sort(old_arr, ptr->n);
    int count = 0;
    int curr_st = ptr->arr[0].st;
    for (int i = 0; i < ptr->n; i++)
    {
        curr_st = ptr->arr[i].st;
        for(int j=i;j<n;j++)
        {

        }
    }
    return 0;
}



int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    // int* start_time = new int[n];
    // int* duration = new int[n];
    //
    // for(int i=0; i < n; i++){
    //     cin >> start_time[i];
    // }
    // for(int i = 0; i < n; i++){
    //     cin >> duration[i];
    // }
    n = 6;
    int start_time[6] = { 1,3,0,5,5,8 };
    int duration[6] = { 1,1,6,2,4,1 };

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
