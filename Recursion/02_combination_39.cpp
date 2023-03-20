#include<iostream>
#include<vector>
using namespace std;

// Helper Function 1
void display(vector<int> v)
{
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;
}

// Helper Function 2
int sum(vector<int> v)
{
    int s = 0;
    for(int x: v)
        s+=x;
    return s;
}

void combination(int *arr, int n, vector<int> v, int index, int target)
{
    int s = sum(v);
    // 1. Base Condition 1
    if(s >= target)
    {
        if(s==target)
            display(v);
        return;
    }
    // 2. Base Condtion 2
    if(index>=n)
        return;
    v.push_back(arr[index]);
    combination(arr, n, v, index, target);
    v.pop_back();
    combination(arr, n, v, index+1, target);
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int target;
    cout<<"Enter target: ";
    cin>>target;
    int *arr;
    arr = new int[n];
    cout<<"Enter array elements: ";
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    vector<int> v;
    combination(arr, n, v, 0, target);
    return 0;
}
