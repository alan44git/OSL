// Zombie process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void swap(int* arr, int i, int j) {
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1])
swap(arr, j, j + 1);
}
}
}
int main(){
int n;
printf("Enter number of array elements: ");
scanf("%d",&n);
int *arr = (int *)malloc(n * sizeof(int));
printf("Input array elements: \n");
for (int i = 0; i < n; i++) {
scanf("%d",&arr[i]);
}
pid_t pid = fork();
if(pid==0){
pid_t parent_id = getppid();
pid_t child_id = getpid();
printf("Parent id : %d \n", parent_id);
printf("Child id: %d \n",child_id);
bubbleSort(arr,n);
sleep(5);
printf("Child Array elements: ");
for (int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
printf("\n");
exit(0);
} else {
bubbleSort(arr,n);
sleep(10);
printf("Parent Array elements: ");
for (int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
printf("\n");
wait(NULL);
}
free(arr);
return 0;
}
// Orphan process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void swap(int* arr, int i, int j) {
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1])
swap(arr, j, j + 1);
}
}
}
int main(){

int n;
printf("Enter number of array elements: ");
scanf("%d",&n);
int *arr = (int *)malloc(n * sizeof(int));
printf("Input array elements: \n");
for (int i = 0; i < n; i++) {
scanf("%d",&arr[i]);
}
pid_t pid = fork();
if(pid==0){
printf("Parent id : %d \n", getppid());
printf("Child id: %d \n",getpid());
bubbleSort(arr,n);
sleep(5);
printf("Child Array elements: ");
for (int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
printf("\nParent died \n");
printf("Parent id : %d \n", getppid());
printf("Child id: %d \n",getpid());
exit(0);
} else {
bubbleSort(arr,n);
sleep(3);
printf("Parent Array elements: ");
for (int i = 0; i < n; i++) {
printf("%d ",arr[i]);
}
printf("\n");
}
free(arr);
return 0;
}
}
