// User function Template for C++

class Solution {
  public:
    void MaxHeapify(vector<int>& arr, int i, int N){
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;
        
        if(l<N && arr[l] > arr[i]) largest = l;
        if(r < N && arr[r] > arr[largest]) largest = r;
        if(largest != i){
            swap(arr[i], arr[largest]);
            MaxHeapify(arr, largest, N);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i = (N - 2)/2; i >= 0; i--){
            MaxHeapify(arr, i, N);
        }
    }
};
