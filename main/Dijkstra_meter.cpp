#include <Meter.h>
#include <vector>
#include <iostream>
#include <algorithm>

#include <Dijkstra_binary.h>
#include <Dijkstra_pq.h>
#include <Dijkstra_redblack.h>

using namespace std;

int main()
{
    char Algname[20];

    uint32_t numberOfTest = 900;

    cout << "measuring Dijkstra!" << endl;

    Meter DBinary = Meter("Dijstra_Binary_Time.txt","Dijkstra_Binary_Cycle.txt",
                          "Dijkstra_Binary_Cycle_Plot.txt","Dijkstra_Binary_Time_Plot.txt");

    Meter DPriorityQ = Meter("Dijkstra_Queue_Time.txt","Dijkstra_Queue_Cycle.txt",
                             "Dijkstra_Queue_Cycle_Plot.txt","Dijkstra_Queue_Time_Plot.txt");

    Meter DRedBlack = Meter("Dijkstra_RedBlack_Time.txt","Dijkstra_RedBlack_Cycle.txt",
                             "Dijkstra_RedBlack_Cycle_Plot.txt","Dijkstra_RedBlack_Time_Plot.txt");

    cout << "Dijkstra with Binary Heap!" << endl;
    for(uint32_t i = 2; i < numberOfTest;i += (i/10)+1)
    {
        cout << "i : " << i << endl;
        GenerateGraph_binary(i);
        DBinary.measure(*dijkstra_binary,0);
        DBinary.printDataTime(Algname);
        DBinary.printDataCycle(Algname);
        DBinary.printDataToPlotCycle(Algname,i);
        DBinary.printDataToPlotTime(Algname,i);
    }
    numberOfTest = 5000;
    cout << "Dijkstra with Priority Queue!" << endl;
    for(uint32_t i = 1; i < numberOfTest;i += (i/10)+1)
    {
        cout << "i : " << i << endl;
        Graph g = GenerateGraph_pq(i);
        DPriorityQ.measure(*dijkstra_pq,g);
        DPriorityQ.printDataTime(Algname);
        DPriorityQ.printDataCycle(Algname);
        DPriorityQ.printDataToPlotCycle(Algname,i);
        DPriorityQ.printDataToPlotTime(Algname,i);
    }

    cout << "Dijkstra with Red Black Tree!" << endl;
    for(uint32_t i = 2; i < numberOfTest;i += (i/10)+1)
    {
        cout << "i : " << i << endl;
        adjacency_list a = GenerateGraph_rb(i);
        DRedBlack.measure(*dijkstra_redblack,a);
        DRedBlack.printDataTime(Algname);
        DRedBlack.printDataCycle(Algname);
        DRedBlack.printDataToPlotCycle(Algname,i);
        DRedBlack.printDataToPlotTime(Algname,i);
    }

    cout << "Finished Measuring!" << endl;
}
