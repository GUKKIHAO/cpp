# include<iostream>
# include<vector> 
# include"windows.h"
using namespace std;
void swap (int i, int j) {
    int tmp = i ;
    i=j;
    j = tmp;
};
void insertSort (vector<int>& arr) {
    if(arr.empty() || arr.size()<2) 
    {
        return;
    }
    for(int i= 1;i<arr.size();++i) 
    {
        int tmp = arr[i];
        for(int j=i-1;j>=0&&arr[j]>tmp;--j) 
        {
                swap(j,j-1);
        }
    }
}
int main() {
    vector<int>arr={4,1,3,5,2};
    insertSort(arr);
    for(int i=0; i<arr.size();++i) {
        cout<<arr[i]<<endl;
    }
    system("pause");
    return 0;
}