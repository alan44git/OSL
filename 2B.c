#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}
void printArray(const char* msg, int arr[], int n) {
printf("%s: ", msg);
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
int main() {
int n;
printf("Enter number of array elements: ");
scanf("%d", &n);
int* arr = (int*)malloc(n * sizeof(int));
if (!arr) {
perror("Memory allocation failed");
return 1;
}
printf("Enter array elements:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
bubbleSort(arr, n);
printArray("Sorted array in parent", arr, n);
char** args = (char**)malloc((n + 2) * sizeof(char*));
args[0] = "./child";
for (int i = 0; i < n; i++) {
args[i + 1] = (char*)malloc(12);
sprintf(args[i + 1], "%d", arr[i]);
}
args[n + 1] = NULL;
pid_t pid = fork();
if (pid < 0) {
perror("fork failed");
exit(1);
} else if (pid == 0) {
execve("./child", args, NULL);
perror("execve failed");
exit(1);
} else {
wait(NULL);

}
for (int i = 1; i <= n; i++) {
free(args[i]);
}
free(args);
free(arr);
return 0;
}
//child.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
printf("\n--- CHILD PROCESS ---\n");
printf("Child PID: %d | Parent PID: %d\n", getpid(), getppid());
printf("Array in reverse order:\n");
for (int i = argc - 1; i >= 1; i--) {
printf("%s ", argv[i]);
}
printf("\n");
return 0;
}
