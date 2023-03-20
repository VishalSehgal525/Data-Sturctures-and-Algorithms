#include<iostream>
#include<vector>
using namespace std;

/*
0. Print all the subsequences for a given array
1. Print all the subsequences whose sum is K.
2. Print anyone of the subsequence whose sum is K.
3. Count total number of the subsequences whose sum is K.
*/

// Helper Function #1
void display(vector<int> v)
{
    for(int x: v)
        cout<<x<<" ";
    cout<<endl;
}

// 0. Print all the subsequences for an array
void printSubseq(int *arr, int n, vector<int> v, int index)
{
    if(index>=n)
    {
        display(v);
        return;
    }
    v.push_back(arr[index]);
    printSubseq(arr, n, v, index+1);
    v.pop_back();
    printSubseq(arr, n, v, index+1);
}

// Helper Function #2
int sum(vector<int> v)
{
    int s = 0;
    for(int x: v)
        s+=x;
    return s;
}

// 1. Print all subsequences whose sum is k
void f(int *arr, int n, vector<int> v, int index, int k)
{
    if(index>=n)
    {
        if(sum(v)==k)
            display(v);
        return;
    }
    v.push_back(arr[index]);
    f(arr, n, v, index+1, k);
    v.pop_back();
    f(arr, n, v, index+1, k);
}

// 2. Print any one subsequence whose sum is k
bool f_once(int *arr, int n, vector<int> v, int index, int k)
{
    if(index>=n)
    {
        if(sum(v)==k)
        {
            display(v);
            return true;
        }
        else
        {
            return false;
        }
    }
    v.push_back(arr[index]);
    if(f_once(arr, n, v, index+1, k)==true)
        return true;
    v.pop_back();
    if(f_once(arr, n, v, index+1, k)==true)
        return true;
    return false;
}

// 3. Print total number of subsequences whose sum is k
int f_count(int *arr, int n, vector<int> v, int index, int k)
{
    if(index>=n)
    {
        if(sum(v)==k)
            return 1;
        else
            return 0;
    }
    v.push_back(arr[index]);
    int f = f_count(arr, n, v, index+1, k);
    v.pop_back();
    int s = f_count(arr, n, v, index+1, k);
    return f+s;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int *arr;
    vector<int> v;
    arr = new int[n];
    cout<<"Enter elements into the array: ";
    for(int i = 0; i<n; i++)
        cin>>arr[i];
//    printSubseq(arr, n, v, 0, k);
//    f_once(arr, n, v, 0, k)?cout<<"":cout<<"No solutions found"<<endl;
    cout<<"Total number of subsequences whose sum is "<<k<<" are "<<f_count(arr, n, v, 0, k)<<endl;
    return 0;
}
