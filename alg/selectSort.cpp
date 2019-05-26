void swap(int i, int j) {
    int tmp=i;
    i=j;
    j=tmp;
}
void selectSort(vector<int>& arr) {
    if(arr.empty() || arr.size()<2) return;
    for(int i=0;i<arr.size()-1;++i) {
        int minIndex=i;
        for(int j=i+1;j<arr.size();++j) {
            minIndex=arr[j]<arr[minIndex]?i:minIndex;
        }
        swap(arr[i],arr[minIndex]);
    }
}