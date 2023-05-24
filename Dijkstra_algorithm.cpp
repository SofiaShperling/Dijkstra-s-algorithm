#include <iostream>
#include <iomanip>
#include <climits>
#include <string>

using namespace std;

const int initial_node = 0;
const int vertices_number = 8;
const int map[vertices_number][vertices_number] = {
    {0, 12, 63, 92, 0, 0, 0, 0},
    {0, 0, 0, 0, 35, 0, 0, 0},
    {0, 59, 0, 0, 0, 21, 15, 0},
    {0, 0, 32, 0, 0, 0, 0, 0},
    {0, 0, 18, 0, 0, 0, 0, 54},
    {0, 0, 0, 0, 26, 0, 0, 3},
    {0, 0, 0, 13, 0, 11, 0, 35},
    {0, 0, 0, 2, 0, 0, 0, 0}, };

void Dijkstra_algorithm(const int map[vertices_number][vertices_number], const int& initial_node)
{
    bool visited[vertices_number];
    int distances[vertices_number];
    int minimalWeight, minimalIndex;


    //Assign to every node a tentative distance value
    for (int i = 0; i < vertices_number; ++i)
    {
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    distances[initial_node] = 0;

    do
    {
        minimalIndex = INT_MAX;
        minimalWeight = INT_MAX;

        for (int i = 0; i < vertices_number; ++i)
        {
            if (!visited[i] && distances[i] < minimalWeight)
            {
                minimalIndex = i;
                minimalWeight = distances[i];
            }
        }

        if (minimalIndex != INT_MAX)
        {
            for (int i = 0; i < vertices_number; ++i)
            {
                if (map[minimalIndex][i])
                {
                    int avalibleWeight = minimalWeight + map[minimalIndex][i];

                    if (avalibleWeight < distances[i])
                        distances[i] = avalibleWeight;
                }
            }

            visited[minimalIndex] = true;
        }
    } while (minimalIndex < INT_MAX);

    for (int i = 0; i < vertices_number; ++i)
    {
        if (distances[i] != INT_MAX)
        {
            cout << "Distance: " << initial_node << " -> " << i << " = " << setw(6) << left << distances[i] << "\t";

            int end = i;
            int weight = distances[end];
            string way = to_string(end) + " >- ";

            while (end != initial_node)
            {
                for (int j = 0; j < vertices_number; ++j)
                {
                    if (map[j][end])
                    {
                        int temp = weight - map[j][end];

                        if (temp == distances[j])
                        {
                            end = j;
                            weight = temp;
                            way += to_string(j) + " >- ";
                        }
                    }
                }
            }

            cout << "Path: ";

            for (int j = way.length() - 5; j >= 0; --j)
                cout << way[j];

            cout << endl;
        }
        else
            cout << "Distance: " << initial_node << " -> " << i << " - " << "path is unavailable" << endl;
    }

}

int main()
{
    Dijkstra_algorithm(map, initial_node);
}