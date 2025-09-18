#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

int main()
{
    double *names, *profit, *weight, *ppw, *stat;
    int N;
    double w_max, total_profit = 0.0, total_w = 0.0;

    std::ifstream objs;
    objs.open("props.txt");
    objs >> N;
    names = new double[N];
    profit = new double[N];
    weight = new double[N];
    ppw = new double[N];
    stat = new double[N];

    for (int i = 0; i < N; i++)
    {
        objs >> names[i];
    }
    for (int i = 0; i < N; i++)
    {
        objs >> profit[i];
    }
    for (int i = 0; i < N; i++)
    {
        objs >> weight[i];
    }
    objs >> w_max;
    objs.close();

    for (int i = 0; i < N; i++)
    {
        ppw[i] = profit[i] / weight[i];
        stat[i] = 0.0;
    }

    double k_weight = 0;
    while (k_weight < w_max)
    {
        int pos = std::max_element(ppw, ppw + N) - ppw;
        if (ppw[pos] == 0)
        {
            std::cout << "No more items to fill the sack. Sealing the sack.\n";
            break;
        }
        if (weight[pos] + k_weight <= w_max)
        {
            k_weight += weight[pos];
            ppw[pos] = 0;
            stat[pos] = 1.0;
        }
        else
        {
            stat[pos] = (double)(w_max - k_weight) / weight[pos];
            k_weight = w_max;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        total_profit += (stat[i] * profit[i]);
        total_w += (stat[i] * weight[i]);
    }

    std::cout << "\nMaximum profit is: " << total_profit << "\n";
    return EXIT_SUCCESS;
}