void HeapSort(vector<int>& arr) {
    if(arr.empty() || arr.size()<2) return;
    //创建一个大根堆
    for(int i= 0;i<arr.size();++i) {
        HeapInsert(arr,i);
    }
    //大根堆的调整
    int size= arr.size();
    swap(arr,0,--size);
    while(size>0) {
        HeapFit(arr,0,size);
        swap(arr,0,--size);
    }
}
//大根堆
void HeapInsert(vector<int>& arr, int index) {
    while(arr[index] > arr[(index-1)/2]) {
        swap(arr, index, (index-1)/2);
        index=(index-1)/2;

    }
}
void HeapFit(vector<int>& arr, int index, int HeapSize) {
    int leftchild=index*2+1;
    while(leftchild<HeapSize) {
        int largest = (leftchild+1<HeapSize)&& (arr[leftchild+1]>arr[leftchild])
                ? arr[leftchild+1]
                : arr[leftchild];
        largest= largest>arr[index]?largest:index;
        if(largest==index) break;
        swap(arr, index, largest);
        index=largest;
        leftchild=index*2+1;
    }
}

void swap(vector<int>& arr, int i, int j) {
    int tmp =arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}