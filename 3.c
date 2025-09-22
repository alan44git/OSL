#include<stdio.h>
struct Process{
	int pid;
	int arrivalTime;
	int burstTime;
	int completionTime;
	int turnaroundTime;
	int waitingTime;
	int responseTime;
	int remainingTime;
};
int main(){
	struct Process processes[4];
	processes[0].pid = 100;
	processes[0].arrivalTime = 0;
	processes[0].burstTime = 7;
	processes[0].remainingTime = processes[0].burstTime;
	processes[1].pid = 200;
	processes[1].arrivalTime = 2;
	processes[1].burstTime = 4;
	processes[1].remainingTime = processes[1].burstTime;
	processes[2].pid = 300;
	processes[2].arrivalTime = 4;
	processes[2].burstTime = 1;
	processes[2].remainingTime = processes[2].burstTime;
	processes[3].pid = 400;
	processes[3].arrivalTime = 5;
	processes[3].burstTime = 4;
	processes[3].remainingTime = processes[3].burstTime;
	int totalProcesses = sizeof(processes) / sizeof(struct Process);
	int completed = 0;
	int currentTime = 0;
	while(completed < totalProcesses){
    	int idx = -1;
    	for(int i = 0; i < totalProcesses; i++){
        	if(processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && ( idx == -1 || processes[i].remainingTime < processes[idx].remainingTime)){
            	idx = i;
        	}}
    	if(idx != -1){
        	if(processes[idx].burstTime == processes[idx].remainingTime) processes[idx].responseTime = currentTime - processes[idx].arrivalTime;
        	processes[idx].remainingTime--;
        	currentTime++;
        	if(processes[idx].remainingTime == 0){
            	completed++;
            	processes[idx].completionTime = currentTime;
            	processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            	processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
        	}
    	}else{  
        	currentTime++;
    	}}
	printf("\n--- Process Scheduling Results (SRTF) ---\n");
	printf("+-------+-------------+-----------+----------------+---------------+-------------+--------------+\n");
	printf("| PID   | Arrival Time| Burst Time| Completion Time| Turnaround Time| Waiting Time| Response Time|\n");
	printf("+-------+-------------+-----------+----------------+---------------+-------------+--------------+\n");
	double totalWaitingTime = 0;
	double totalTurnaroundTime = 0;
	for (int i = 0; i < totalProcesses; i++) {
    	printf("| %-5d | %-11d | %-9d | %-14d | %-13d | %-11d | %-12d |\n",
           	processes[i].pid,
           	processes[i].arrivalTime,
           	processes[i].burstTime,
           	processes[i].completionTime,
           	processes[i].turnaroundTime,
           	processes[i].waitingTime,
           	processes[i].responseTime);
    	totalWaitingTime += processes[i].waitingTime;
    	totalTurnaroundTime += processes[i].turnaroundTime;
	}
	printf("+-------+-------------+-----------+----------------+---------------+-------------+--------------+\n");

	printf("\n--- Averages ---\n");
	printf("Average Waiting Time:   %.2f\n", totalWaitingTime / totalProcesses);
	printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / totalProcesses);
	return 0;
}
