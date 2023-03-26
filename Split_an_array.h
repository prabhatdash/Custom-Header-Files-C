#include<stdio.h>

void main(){
int n;
printf("Enter the size of the array\n");
scanf("%d",&n);
int arr1[n];

  //Taking The elements From User
for(int i=0;i<n;i++){
scanf("%d",&arr1[i]);
}

  //Displaying The Array
printf("the Original Array Is\n");
for(int i=0;i<n;i++){
printf("%d ",arr1[i]);
}

  //Taking The Element From Where The User Want to Split
printf("\n");
printf("Enter the index from where you want to split\n");
int split;
scanf("%d",&split);

  //Defining Arrays
int arr2[split];
int arr3[n-split];


for(int i=0;i<split;i++){
arr2[i]=arr1[i];
}

  
printf("the Second Array Is\n");
for(int i=0;i<split;i++){
printf("%d ",arr2[i]);
}
printf("\n");
int j=0;
for(int i=split;i<n;i++){
arr3[j]=arr2[i];
j++;    
}

  
printf("The Third Array is\n");

for(int i=split;i<n;i++){
printf("%d ",arr1[i]);
}

}
