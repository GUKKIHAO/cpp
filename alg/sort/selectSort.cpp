# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void Swap(int& x, int& y);
void selectSort(vector<int> &nums);
int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"array before sort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"array after sort"<<endl;
    selectSort(nums);
    for(int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
void Swap(int& x, int& y)
{
    int temp= x;
	x = y;
	y = temp;
}
void selectSort(vector<int> &nums)
{
    if(nums.size()<=1) return;
    int i,len=nums.size();
    for(int i = 0;i<len-1;++i)
    {
        int tmp = i;
        for(int j = i+1;j<len;++j)
        {
            if(nums[tmp]>nums[j])
            {
                tmp = j;
            }
        }
        Swap(nums[tmp],nums[i]);
    }
}
