#include <limits>
#include <iostream>
#include <fstream>

int main()
{
    int INTMAX = std::numeric_limits<int>::max();
    int **adj_mat, *cost, *visited, N;
    std::ifstream mat_in;
    mat_in.open("graph_connections.dat");
    mat_in >> N;

    adj_mat = new int *[N];
    cost = new int[N]; // Distance of all nodes from the first node
    visited = new int[N];
    for (int i = 0; i < N; i++)
    {
        adj_mat[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            visited[i] = 0;
            mat_in >> adj_mat[i][j]; // Get all weighted edges
            if (i == 0 && adj_mat[i][j] > 0)
                cost[j] = adj_mat[i][j];
            else if (i == 0)
                cost[j] = INTMAX; // Set distance to inf if not connected directly to the first node
        }
    }

    cost[0] = 0;

    int l_lim, min_val, min_pos;
    l_lim = cost[0];

    for (int i = 0; i < N; i++)
    {
        min_val = INTMAX;
        for (int j = 1; j < N; j++)
        {
            if ((l_lim < cost[j] && cost[j] < min_val) && visited[j] == 0)
            {
                min_val = cost[j];
                min_pos = j;
            }
        }
        
        visited[min_pos]++;
        for (int j = 1; j < N; j++)
        {
            if (adj_mat[min_pos][j] > 0)
            {
                if (cost[min_pos] + adj_mat[min_pos][j] < cost[j])
                {
                    cost[j] = cost[min_pos] + adj_mat[min_pos][j];
                }
            }
        }
        l_lim = min_val;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << cost[i] << "\t";
    }
    std::cout << "\n";
    return EXIT_SUCCESS;
}