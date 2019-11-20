# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void merge(vector<int>& nums,int left, int right, int mid);
void mergeSort(vector<int>&nums, int left, int right);
void mergeSort(vector<int>&nums);
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before quicksort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after quicksort"<<endl;
    mergeSort(nums);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void merge(vector<int>& nums,int left, int right, int mid)
{
    //int len = nums.size();
    vector<int>help(right-left+1);
    int i = 0;
    int lIndex=left;
    int rIndex=mid+1;
    while(lIndex<=mid&&rIndex<=right) 
    {
        help[i++] = nums[lIndex] < nums[rIndex] ? nums[lIndex++] : nums[rIndex++];

    }
    while(lIndex <= mid)
    {
        help[i++] = nums[lIndex++];
    }
    while(rIndex <= right)
    {
        help[i++] = nums[rIndex++];
    }
    for(i = 0;i<right-left+1;++i)
    {
        nums[left+i]=help[i];
    } 
}
void mergeSort(vector<int>&nums, int left, int right)
{
    if(right==left) return;
    int mid = left+(right-left)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    merge(nums,left,right,mid);
}
void mergeSort(vector<int>&nums)
{
    int left = 0, right = nums.size()-1;
    mergeSort(nums,left,right);
}