# CPU-Scheduling

1. Shortest Job First (SJF)
Purpose: SJF aims to minimize average waiting time by executing the shortest jobs first.

Implementation Details:

Comparator (cmp_SJF): Compares processes based on their burst time (BT). If burst times are equal, it uses arrival time (AT) to break ties.
Algorithm (SJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by burst time.
Execution: Select the process that arrives before or at curr_time. Execute the process for its burst time or until completion if total_BT is less than burst time.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Minimizes average waiting time for processes.

Cons: May cause starvation for longer processes.

2. Shortest Remaining Job First (SRJF)
Purpose: SRJF is a preemptive version of SJF, where the scheduler can preempt the currently executing process if a shorter job arrives.

Implementation Details:

Comparator (cmp_SRJF): Similar to SJF, compares remaining burst time instead of total burst time.
Algorithm (SRJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by remaining burst time.
Execution: Select the process that arrives before or at curr_time. Execute the process for a time quantum (here 1 unit).
Preemption: If another process with shorter remaining time arrives, preempt the current process.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Reduces average response time and waiting time compared to SJF.

Cons: May lead to higher context switch overhead.

3. Longest Job First (LJF)
Purpose: LJF executes the longest jobs first, potentially leading to faster completion of larger tasks.

Implementation Details:

Comparator (cmp_LJF): Sorts processes in descending order of burst time.
Algorithm (LJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by burst time in descending order.
Execution: Select the process that arrives before or at curr_time. Execute the process for its burst time.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Can prioritize larger tasks and potentially reduce their waiting time.

Cons: Shorter jobs may starve if many long jobs arrive.

4. Longest Remaining Job First (LRJF)
Purpose: LRJF is a preemptive version of LJF, where the scheduler can preempt the currently executing process if a longer job arrives.

Implementation Details:

Comparator (cmp_LRJF): Sorts processes in descending order of remaining burst time.
Algorithm (LRJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by remaining burst time in descending order.
Execution: Select the process that arrives before or at curr_time. Execute the process for a time quantum (here 1 unit).
Preemption: If another process with longer remaining time arrives, preempt the current process.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Prioritizes execution of longer tasks while ensuring some progress on shorter tasks.

Cons: Increased complexity due to preemption.

5. First Come First Serve (FCFS)
Purpose: FCFS executes tasks in the order they arrive.

Implementation Details:

Comparator (cmp_FCFS): Sorts processes based on their arrival time.
Algorithm (FCFS function):
Initialization: Initialize curr_time to track current time and total_BT for total burst time.
Sorting: Sort processes by arrival time.
Execution: Execute processes sequentially as they arrive.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Simple to implement and understand.

Cons: May lead to longer average waiting times, especially for shorter processes arriving later.

6. Round Robin (RR)
Purpose: RR executes tasks in a cyclic manner, allowing each task to run for a fixed time quantum.

Implementation Details:

Algorithm (RR function):
Initialization: Initialize curr_time to track current time, time_quantum for time slice (here 3 units), and total_BT for total burst time.
Round Robin Execution: Processes are executed in a round-robin manner using a queue.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Ensures fair execution and prevents starvation.

Cons: May lead to higher context switch overhead.

7. Priority Scheduling (PS)
Purpose: PS executes tasks based on their priority.

Implementation Details:

Comparator (cmp_PS): Sorts processes based on their priority.
Algorithm (PS function):
Initialization: Initialize curr_time to track current time and total_BT for total burst time.
Sorting: Sort processes by priority.
Execution: Execute processes based on their priority, preempting lower priority tasks if a higher priority task arrives.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Prioritizes important tasks based on their priority level.

Cons: May lead to starvation of lower priority tasks.

8. Multi Level Feedback Queue (MLFQ)
Purpose: MLFQ uses multiple queues with different priorities to execute tasks, promoting shorter jobs to higher priority queues.

Implementation Details:

Comparator (cmp_MLFQ): Sorts processes based on their priority and burst time.
Algorithm (MLFQ function):
Initialization: Initialize curr_time to track current time, time_quantum for time slice (variable based on process priority), and total_BT for total burst time.
Multi-Level Queues: Processes are initially placed in a queue based on priority.
Execution: Execute processes from the highest priority queue, preempting lower priority tasks if necessary.
Promotion: After executing a task, its priority may be adjusted based on its behavior (e.g., penalizing long-running tasks).
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Balances execution between short and long jobs, reducing response time for short jobs.

Cons: Complexity in managing multiple queues and priorities.

Summary:
Each scheduling algorithm has its strengths and weaknesses, making them suitable for different scenarios based on system requirements such as throughput, turnaround time, and fairness. The provided C++ code implements these algorithms with the goal of demonstrating their behavior and calculating performance metrics for comparison.




merge it with your previous answer

ChatGPT
Certainly! Let's integrate the explanations of each scheduling algorithm with the previous answer for a more comprehensive overview:

Scheduling Algorithms Explained
Here’s a breakdown of various scheduling algorithms implemented in the provided C++ code, each serving different purposes and strategies:

1. Shortest Job First (SJF)
Purpose: SJF aims to minimize average waiting time by executing the shortest jobs first.

Implementation Details:

Comparator (cmp_SJF): Compares processes based on their burst time (BT). If burst times are equal, it uses arrival time (AT) to break ties.
Algorithm (SJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by burst time.
Execution: Select the process that arrives before or at curr_time. Execute the process for its burst time or until completion if total_BT is less than burst time.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Minimizes average waiting time for processes.

Cons: May cause starvation for longer processes.

2. Shortest Remaining Job First (SRJF)
Purpose: SRJF is a preemptive version of SJF, where the scheduler can preempt the currently executing process if a shorter job arrives.

Implementation Details:

Comparator (cmp_SRJF): Similar to SJF, compares remaining burst time instead of total burst time.
Algorithm (SRJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by remaining burst time.
Execution: Select the process that arrives before or at curr_time. Execute the process for a time quantum (here 1 unit).
Preemption: If another process with shorter remaining time arrives, preempt the current process.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Reduces average response time and waiting time compared to SJF.

Cons: May lead to higher context switch overhead.

3. Longest Job First (LJF)
Purpose: LJF executes the longest jobs first, potentially leading to faster completion of larger tasks.

Implementation Details:

Comparator (cmp_LJF): Sorts processes in descending order of burst time.
Algorithm (LJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by burst time in descending order.
Execution: Select the process that arrives before or at curr_time. Execute the process for its burst time.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Can prioritize larger tasks and potentially reduce their waiting time.

Cons: Shorter jobs may starve if many long jobs arrive.

4. Longest Remaining Job First (LRJF)
Purpose: LRJF is a preemptive version of LJF, where the scheduler can preempt the currently executing process if a longer job arrives.

Implementation Details:

Comparator (cmp_LRJF): Sorts processes in descending order of remaining burst time.
Algorithm (LRJF function):
Initialization: Initialize curr_time to track current time, total_BT for total burst time, and time_quantum for time slice.
Sorting: Sort processes by remaining burst time in descending order.
Execution: Select the process that arrives before or at curr_time. Execute the process for a time quantum (here 1 unit).
Preemption: If another process with longer remaining time arrives, preempt the current process.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Prioritizes execution of longer tasks while ensuring some progress on shorter tasks.

Cons: Increased complexity due to preemption.

5. First Come First Serve (FCFS)
Purpose: FCFS executes tasks in the order they arrive.

Implementation Details:

Comparator (cmp_FCFS): Sorts processes based on their arrival time.
Algorithm (FCFS function):
Initialization: Initialize curr_time to track current time and total_BT for total burst time.
Sorting: Sort processes by arrival time.
Execution: Execute processes sequentially as they arrive.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Simple to implement and understand.

Cons: May lead to longer average waiting times, especially for shorter processes arriving later.

6. Round Robin (RR)
Purpose: RR executes tasks in a cyclic manner, allowing each task to run for a fixed time quantum.

Implementation Details:

Algorithm (RR function):
Initialization: Initialize curr_time to track current time, time_quantum for time slice (here 3 units), and total_BT for total burst time.
Round Robin Execution: Processes are executed in a round-robin manner using a queue.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Ensures fair execution and prevents starvation.

Cons: May lead to higher context switch overhead.

7. Priority Scheduling (PS)
Purpose: PS executes tasks based on their priority.

Implementation Details:

Comparator (cmp_PS): Sorts processes based on their priority.
Algorithm (PS function):
Initialization: Initialize curr_time to track current time and total_BT for total burst time.
Sorting: Sort processes by priority.
Execution: Execute processes based on their priority, preempting lower priority tasks if a higher priority task arrives.
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Prioritizes important tasks based on their priority level.

Cons: May lead to starvation of lower priority tasks.

8. Multi Level Feedback Queue (MLFQ)
Purpose: MLFQ uses multiple queues with different priorities to execute tasks, promoting shorter jobs to higher priority queues.

Implementation Details:

Comparator (cmp_MLFQ): Sorts processes based on their priority and burst time.
Algorithm (MLFQ function):
Initialization: Initialize curr_time to track current time, time_quantum for time slice (variable based on process priority), and total_BT for total burst time.
Multi-Level Queues: Processes are initially placed in a queue based on priority.
Execution: Execute processes from the highest priority queue, preempting lower priority tasks if necessary.
Promotion: After executing a task, its priority may be adjusted based on its behavior (e.g., penalizing long-running tasks).
Gantt Chart: Print execution sequence ("P1 P2 ..."), update curr_time and total_BT.
Metrics Update: Update response time, completion time, waiting time, and turnaround time for each process.
Pros: Balances execution between short and long jobs, reducing response time for short jobs.

Cons: Complexity in managing multiple queues and priorities.

Summary
Each scheduling algorithm serves a specific purpose and has its strengths and weaknesses. The provided C++ code demonstrates these algorithms in action, simulating their behavior and calculating key metrics such as response time, waiting time, turnaround time, and completion order. Choosing the right scheduling algorithm depends on system requirements such as throughput, fairness, and responsiveness to optimize overall performance.
