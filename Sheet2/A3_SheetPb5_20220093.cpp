// File name:Problem 5
// Purpose:take the tasklist from cmd and sort it
// Author(s):Toqa Abdalla Ahmed
// ID(s):20220093
// Section:s7,8
// Date:8/12/2023
#include <bits/stdc++.h>
using namespace std;
class Process {
private:
    string name;
    string pid;
    string memoryUsage;

public:
    Process(string name,string pid,string memoryUsage) : name(name), pid(pid), memoryUsage(memoryUsage) {}

    string getName() const {
        return name;
    }

    string getPID() const {
        return pid;
    }

    string getMemoryUsage() const {
        return memoryUsage;
    }
};

class ProcessList {
private:
   vector<Process> processes;

public:
    void fetchProcesses() {
        string command = "tasklist /FO CSV";
        FILE* stream = _popen(command.c_str(), "r");

        if (stream) {
            char buffer[1024];
            while (!feof(stream)) {
                if (fgets(buffer, 1024, stream) != nullptr) {
                    istringstream iss(buffer);
                    string name,pid,line, memoryUsage;

                    getline(iss, name, ',');
                    getline(iss, pid, ',');
                    getline(iss, line, ',');
                    getline(iss, line, ',');
                    getline(iss, memoryUsage);

                    name = name.substr(1, name.length() - 2);
                    pid = pid.substr(1, pid.length() - 2);
                    memoryUsage=memoryUsage.substr(1,memoryUsage.length()-2);

                    processes.emplace_back(name, pid, memoryUsage);
                }
            }
            _pclose(stream);
        }
    }

    void displayProcesses() const {
        cout<<"Image Name              "<<'\t'<<"PID     "<<'\t'<<"Mem Usage"<<endl;
        cout<<"========================"<<'\t'<<"========"<<'\t'<<"============"<<endl;
        for (const auto& process : processes) {

            cout << "Name: " << process.getName()<<'\t' << " | PID: " << process.getPID() <<'\t'<< " | Memory Usage: " << process.getMemoryUsage() << endl;
        }
    }

    void sortProcesses(int choice) {
        switch (choice) {
            case 1:
                sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                    return a.getName() < b.getName();
                });
                break;
            case 2:
                sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                    return a.getPID() < b.getPID();
                });
                break;
            case 3:
               sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
                    return a.getMemoryUsage() < b.getMemoryUsage();
                });
                break;
            default:
                cout << "Invalid choice!" << std::endl;
                break;
        }
    }
};

int main() {
    ProcessList processList;

    processList.fetchProcesses();

    cout << "How do you want to sort the processes?" << endl;
    cout << "1. Sort by Name" <<endl;
    cout << "2. Sort by PID" <<endl;
    cout << "3. Sort by Memory Usage" <<endl;

    int choice;
    cin >> choice;

    processList.sortProcesses(choice);

    processList.displayProcesses();

    return 0;
}
