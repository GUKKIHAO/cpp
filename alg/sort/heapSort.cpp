# include<bits/stdc++.h>
# include"windows.h"
using namespace std;
void heapify(vector<int> &nums, int len, int currentNode);
void heapSort(vector<int> &nums);

int main() {
    vector<int>nums={3,1,4,2,5};
    cout<<"numsay before sort"<<endl;
    for(int i = 0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"numsay after sort"<<endl;
    heapSort(nums);
    for(unsigned int i =0;i<nums.size();++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
// 递归方式构建大根堆(len是nums的长度，index是第一个非叶子节点的下标)
void heapify(vector<int> &nums, int len, int currentNode)
{
    int left =  2*currentNode + 1; // index的左子节点
    int right = 2*currentNode + 2;// index的右子节点
 
    int max = currentNode;
    if(currentNode<len){
        if(left<len && nums[left] > nums[max])  
        {
            max = left;
        }   
        if(right<len && nums[right] > nums[max])
        {
            max = right;
        }    
        if(max != currentNode)
        {
            swap(nums[max], nums[currentNode]);
            heapify(nums, len, max);
        }
    }
}
// 堆排序
void heapSort(vector<int> &nums)
{
    int len=nums.size();
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i=len/2 - 1; i >= 0; i--)
    {
        heapify(nums, len, i);
    }
 
    // 调整大根堆
    for(int i = len - 1; i >= 1; i--)
    {
        swap(nums[0], nums[i]);           // 将当前最大的放置到数组末尾
        heapify(nums, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}