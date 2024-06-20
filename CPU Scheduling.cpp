#include <bits/stdc++.h>
using namespace std;

bool cmp_SJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] < p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void SJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0; 
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_SJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

bool cmp_LJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] > p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void LJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;    
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_LJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

bool cmp_SRJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] < p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void SRJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int curr_time = 0;
    int time_quantum = 0;
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_SRJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = 1;
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 

bool cmp_LRJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] > p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void LRJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;   
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_LRJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = 1;
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 

bool cmp_FCFS(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[1] != p2.second[1]){
        return p1.second[1] < p2.second[1];
    }
    return p1.second[3] > p2.second[3];
}
 
void FCFS(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;    
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_FCFS);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

bool cmp_MLFQ(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if (p1.first != p2.first){
        return p1.first > p2.first;
    }else if (p1.second[3] != p2.second[3]){
        return p1.second[3] > p2.second[3];
    }
    return p1.second[2] < p2.second[2];
}
 
void MLFQ(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int curr_time = 0;
    int time_quantum = 0;
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_MLFQ);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = min(processes[process_to_be_executed].first/2 + 1, processes[process_to_be_executed].second[2]);
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        for (int i = 0; i < processes.size(); ++i)
        { 
            if(i == process_to_be_executed){
                continue;
            }
            processes[i].first = processes[i].second[3]+max(min(5, (curr_time-processes[i].second[1]-processes[i].second[4])/8), 0);
        }
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 

bool cmp_PS(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if (p1.first != p2.first){
        return p1.first > p2.first;
    }
    return p1.second[2] < p2.second[2];
}
 
void PS(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;   
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_PS);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i)
        {
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = 1;
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 
 
void RR(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int curr_time = 0;    
    int time_quantum = 3;
    int process_to_be_executed = -1;
    queue<int> ready_queue;
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        
        for (int i = 0; i < processes.size(); ++i)
        {
            if(time_quantum>= 1 && processes[i].second[1] == curr_time-time_quantum+1){
                ready_queue.push(i);
            }
        }
        for (int i = 0; i < processes.size(); ++i)
        {
            if(time_quantum>= 2 && processes[i].second[1] == curr_time-time_quantum+2){
                ready_queue.push(i);
            }
        }
        for (int i = 0; i < processes.size(); ++i)
        {
            if(time_quantum>= 3 && processes[i].second[1] == curr_time-time_quantum+3){
                ready_queue.push(i);
            }
        }
        if(process_to_be_executed != -1){
            if (time_quantum != processes[process_to_be_executed].second[2]){
                processes[process_to_be_executed].second[2]-= time_quantum;
                ready_queue.push(process_to_be_executed);                
            }else{
                original[j].second.push_back(curr_time);
                original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
                original[j].second.push_back(curr_time-original[j].second[1]); 
            }
        }
        if (ready_queue.empty()){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        process_to_be_executed = ready_queue.front();
        for(j = 0; j < original.size(); j++){
            if (original[j].second[0] == processes[process_to_be_executed].second[0]){
                if(umap.find(j) == umap.end()){
                    umap[j] = 1;
                    original[j].second.push_back(curr_time - original[j].second[1]);
                }
                break;
            }
        }
        ready_queue.pop();
        time_quantum = min(3, processes[process_to_be_executed].second[2]);
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i)
        {
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        
    }
} 

int no_of_digits(int num){
    if(num==0){
        return 1;
    }
    int ans = 0;
    while(num){
        ans++;
        num/=10;
    }
    return ans;
}

void print(vector<pair<int, vector<int>>> &original){
    cout <<endl << endl<< "Table:";
    cout << endl;
    cout << "| Proc  | A T  | B T  | Pri  | R T  | C T  | W T  | TAT  |" << endl;
    int rt = 0;
    int ct = 0;
    int wt = 0;
    int tat = 0;
    for(int j = 0; j < original.size(); j++){
        cout << "| P";
        for(int i = 0; i < 9; i++){
            if(i==4){
                continue;
            }
            if(i == 5){
                rt+=original[j].second[i];
            }
            if(i == 6){
                ct+=original[j].second[i];
            }
            if(i == 7){
                wt+=original[j].second[i];
            }
            if(i == 8){
                tat+=original[j].second[i];
            }
            cout << original[j].second[i];
            for(int k = 0; k < 4-no_of_digits(original[j].second[i]); k++){
                cout << " ";
            }
            cout << " | ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Averages:" << endl;
    cout << "Average Response Time is " << rt*1.0/original.size() << "." << endl;
    cout << "Average Completion Time is " << ct*1.0/original.size() << "." << endl;
    cout << "Average Waiting Time is " << wt*1.0/original.size() << "." << endl;
    cout << "Average Turn Around Time is " << tat*1.0/original.size() << "." << endl;
    cout << endl << endl;    
}

int main(){
    int no_of_processes;
    cout << "Number of processes to be scheduled are: ";
    cin >> no_of_processes;
    cout << endl;
    vector<pair<int, vector<int>>> processes(no_of_processes);
    cout << "AT = Arrival Time | BT = Burst Time | P = Priority (Scale 1 to 5)"<<endl;
    cout << "| Process | AT BT P" << endl;
    for (int i = 0; i < no_of_processes; ++i)
    {
        vector<int> process;
        process.push_back(i+1);

        cout << "| P" << i+1;
        for(int j = 0; j < 6-no_of_digits(i+1); j++){
            cout << " ";
        }
        cout << " | ";
        int AT;
        cin >> AT;
        process.push_back(AT);
        int BT;
        cin >> BT;
        process.push_back(BT);
        int P;
        cin >> P;
        process.push_back(P);
        process.push_back(0);
        processes[i].first=P;
        processes[i].second=process;
    }
    cout << endl;
    long long total_BT = 0;
    for (int i = 0; i < no_of_processes; ++i)
    {
        total_BT += processes[i].second[2];
    }
    
    cout << "Proc = Process | A T = Arrival Time | B T = Burst Time | Pri = Priority | R T = Response Time | C T = Completion Time | W T = Waiting Time | TAT = Turn Around Time"<<endl << endl << endl;
    vector<pair<int, vector<int>>> original(no_of_processes);
    copy(processes.begin(), processes.end(), original.begin());
    cout << "Shortest Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    SJF(total_BT, processes, original); 
    print(original);
    cout << "Shortest Remaining Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    SRJF(total_BT, processes, original); 
    print(original);
    cout << "Longest Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    LJF(total_BT, processes, original);   
    print(original);
    cout << "Longest Remaining Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    LRJF(total_BT, processes, original); 
    print(original);
    cout << "First Come First Serve" << endl << endl;
    cout << "Gantt Chart" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    FCFS(total_BT, processes, original); 
    print(original);
    cout << "Round Robin" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    RR(total_BT, processes, original); 
    print(original);
    cout << "Priority Scheduling" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    PS(total_BT, processes, original); 
    print(original);
    cout << "Multi Level Feedback Queue" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    MLFQ(total_BT, processes, original); 
    print(original);
    return 0;
} 