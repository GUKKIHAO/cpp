# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void quickSort(vector<int> &nums,int left,int right);
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before quicksort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after quicksort"<<endl;
    quickSort(nums,0,nums.size()-1);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void quickSort(vector<int> &nums,int left,int right){
    if(left < right) {
        int key = nums[left]; int i = left, j = right;
        while(i!=j) {
            while(nums[j]>=key && i<j) {
                --j;
            }
            if(i<j)
                nums[i++]=nums[j];
            while(nums[i] < key && i<j) {
                ++i;
            }
            if(i<j)
                nums[j--]=nums[i];
        }
        nums[i]=key;
        quickSort(nums,left,i-1);
        quickSort(nums,i+1,right);
    }
}