void mergeSort(vector<int>&arr) {
    if(arr.empty() || arr.size()<2) return;
    sortprocess(arr,0,arr.size()-1);
}
void sortorocess(vector<int>&arr,int left, int right) {
    if(left==right) return;
    int mid = left + (right-left)>>1;
    sortprocess(arr,left,mid);
    sortprocess(arr,mid+midright);
    merge(arr,left,mid,right);
}
void merge(vector<int>&arr,int left,int mid,int right) {
    vector<int> tmp (arr.size());
    int p1=left,p2=mid+1,idx=0;
    while(p1<=mid && p2<=right) {
        tmp[idx++]=arr[p1]>arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=mid) {
        tmp[idx++]=arr[p1++];
    }
    while(p2<=right) {
        tmp[idx++]=arr[p2++];
    }
    for(idx=0;i<tmp.size();++idx) {
        arr[left+idx]=tmp[idx];
    }
}