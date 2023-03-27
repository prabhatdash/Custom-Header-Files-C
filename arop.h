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
