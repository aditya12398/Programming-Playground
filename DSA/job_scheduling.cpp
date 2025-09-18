#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

int main()
{
    std::string *jobName;
    int *time;
    double *profit;
    int *deadline;
    int N, job_counter = 0;

    std::ifstream jobs;
    jobs.open("jobs.txt");
    jobs >> N;
    jobName = new std::string[N];
    profit = new double[N];
    deadline = new int[N];
    for (int i = 0; i < N; i++)
    {
        jobs >> profit[i];
    }
    for (int i = 0; i < N; i++)
    {
        jobs >> deadline[i];
    }
    int max_time = *std::max_element(deadline, deadline + N);
    time = new int[max_time];

    for (int i = 0; i < max_time; i++)
    {
        time[i] = -1;
    }

    for (int jobid = 0; jobid < N; jobid++)
    {
        int sch = 1;
        while (deadline[jobid] >= sch)
        {
            if (time[deadline[jobid] - sch] != -1)
            {
                sch++;
            }
            else
            {
                time[deadline[jobid] - sch] = jobid;
                break;
            }
        }
    }
    std::cout << "Job sequence: ";
    for (int i = 0; i < max_time; i++)
    {
        std::cout << time[i] << "\t";
    }
    std::cout << "\n";
}