# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void bucketSort(vector<int>& arr); 
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before sort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after sort"<<endl;
    bucketSort(nums);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void bucketSort(vector<int>& arr) 
{
    if(arr.empty() || arr.size()<2) return;
    int max_value = INT_MAX;
    for(int i= 0;i<arr.size();++i) {
        max_value=max(max_value,arr[i])
    }
    vector<int> bucket(max+1);
    for(int i =0;i<arr.size();++i) {
        bucket[arr[i]]++;
    }
    int i=0;
    for(int j=0;j<bucket.size();++j) {
        while(bucket[j]-- > 0) {
            arr[i++]=j;
        }
    }
}