//Array Merging
#include<stdlib.h>
int *merge(int ar1[],int ar2[],int size_ar1,int size_ar2){
    int total_size=size_ar1+size_ar2;
    int *finar=(int *) malloc(total_size*sizeof(int));
    for(int i=0;i<size_ar1;i++){
        finar[i]=ar1[i];
    }
    int j=0;
    for(int i=size_ar1;i<total_size;i++){
        finar[i]=ar2[j];
        j++;
    }
    return finar;
}

//Array Searching
int linear(int ar[], int n, int key){
    int flag=0;
    for(int i=0;i<n;i++){
        if(ar[i]==key){
            return i;
            flag++;
        }
    }
    if(flag==0){
        return -1;
    }
    
}

int binary(int ar[], int n, int key){
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(key>ar[mid]){
            start=mid+1;
        }
        else if(key==ar[mid]){
            return mid;
            return 0;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}

int interpolation(int ar[], int n ,int key){
    int start=0;
    int end=n-1;
    int mid=start+((key-ar[start])*((double)(end-start))/(ar[end]-ar[start]));
    while(start<=end){
        if(key>ar[mid]){
            start=mid+1;
        }
        else if(ar[mid]==key){
            return mid;
        }
        else{
            end=mid-1;
        }
        mid=start+((key-ar[start])*((double)(end-start))/(ar[end]-ar[start]));
    }
    return -1;
}

//Array sorting
int bubble(int ar[], int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<(size-1)-i;j++){
            if(ar[j]>ar[j+1]){
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}

int insertion(int ar[], int size){
    int temp;
    for(int i=0;i<size;i++){
        temp=ar[i];
        int j=i-1;
        for(j=j;(j>=0&&ar[j]>temp);j--){
            ar[j+1]=ar[j];
        }
        ar[j+1]=temp;
    }
}

int selection(int arr[],int size){
 for(int i=0;i<size-1;i++){
    int min=i;
    for(int j=i+1;j<size;j++){
        if(arr[min]>arr[j]){
            min=j;
        }
    }
    int temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
 }
}

void quick(int arr[], int start, int stop){
   int p, q, pivot, temp;
   if(start < stop){
      pivot = start;
      p = start;
      q = stop;
      while(p < q){
         while(arr[p] <= arr[pivot] && p < stop)
            p++;
         while(arr[q] > arr[pivot])
            q--;
         if(p < q){
            temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
         }
      }
      temp = arr[pivot];
      arr[pivot] = arr[q];
      arr[q] = temp;
      quick(arr, start, q-1);
      quick(arr, q+1, stop);
   }
}

void shell(int ar[], int size){
    int j; 
    for(int gap=size/2;gap>0;gap=gap/2){
        for(int i=gap;i<size;i++){
            int temp=ar[i];
            for(j=i;j>=gap && ar[j-gap]>temp;j=j-gap){
                ar[j]=ar[j-gap];
            }
        ar[j]=temp;
        }
    }
}

void merge(int arr[], int start, int mid, int stop) {
    int i, j, k;
    int n1 = mid-start+1;
    int n2 = stop-mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[start+i];
    for (j = 0; j < n2; j++) R[j] = arr[mid+1+j];

    i = j = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    } while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int start, int stop) {
    if (start < stop) {
        int mid = start+(stop-start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, stop);
        merge(arr, start, mid, stop);
    }
}
