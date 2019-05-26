void QuickSort (vector<int>& arr) {
    if(arr.empty() || arr.size()<2) return;
    QuickSort(arr,0,arr.size()-1);
}
void QuickSort(vector<int>& arr, int left, int right) {
    if(left < right) {
        swap(arr,right,srand((unsigned int)(time(NULL))%(right-left+1)+left);
        vector<int> p;
        p=partion(arr,left,right);
        QuickSort(arr,left,p[0]-1);
        QuickSort(arr,p[1]+1,right);
    }
}
vector<int> partion(vector<int>& arr,int left, int right) {
    vector<int> ans;
    int tmp = arr[arr.size()-1];
    int less=left-1;
    int more=right;
    while(left<more) {
        if(arr[left]<arr[right]) {
            swap(arr,++less,left++);           
        }
        else if(arr[left]>arr[right]) {
            swap(arr,--more,left);
        }
        else {
            left++;
        }
        swap(arr,more,right);
        ans.push_back(less+1);
        ans.push_back(more);
    }
}
void swap(vector<int>& arr, int i, int j) {
    int tmp =arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}