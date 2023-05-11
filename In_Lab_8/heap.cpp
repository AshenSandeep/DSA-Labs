#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify (int arr[],int n, int root){
    int temp;
    int left = root*2+1;
    int right = root*2+2;
    int max = root;
    if(left < n && arr[left]>arr[root]){
        max = left;
    }
    if(right < n && arr[right]>arr[max]){
        max = right;
    } 
    if(max != root){
        temp = arr[root];
        arr[root]=arr[max];
        arr[max]=temp;
        heapify(arr,n,max);

    }
}

// implementing heap sort
void heapSort(int arr[],int n){
    for(int i = (n/ 2)-1 ; i>=0; i--){    // Build Heap 
        heapify(arr,n,i);
    }
    for(int i = n-1 ; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   cout<<"Enter the Array length: ";
   int n;
   cin>>n;
   int arr[n];
   cout<<"Enter the array:"<<endl;
   int p;
   for(int k=0;k<n;k++){
      cin>>p;
      arr[k] = p;
   }
   
   cout<<endl;
   cout<<"Input array"<<endl;
   displayArray(arr,n);
   cout<<endl;
   heapSort(arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(arr, n);
   cout<<endl;
   
}