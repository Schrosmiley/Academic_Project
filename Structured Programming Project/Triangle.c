#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_TRIANGLES 100

int n, e, nodeCount = 0,minCostTrianlgeIndex = -1,minCost = 1000000;
int visited[MAX_NODES], visit_count = 0;
int valid = 0;

// Definition of a structure to represent a node in the graph
struct Node
{
    int nodeid;
    int adjcount, visaCount;
    int adjs[10]; // Array to store adjacent nodes
    int costs[10]; // Array to store costs associated with adjacent nodes
    int visas[10]; // Array to store visa information for the node
};

struct Node arr[MAX_NODES]; // Array to store nodes in the graph

int triangles[MAX_TRIANGLES][3]; // 2D array to store triangles
int costs[MAX_NODES];
int count_Triangle = 0;

// Function to add a new node to the graph
void addNode(int nid)
{
    for (int i = 0; i < nodeCount; i++)
    {
        if (arr[i].nodeid == nid)
        {
            return; // Node already exists, so return
        }
    }
    arr[nodeCount].nodeid = nid;
    arr[nodeCount].adjcount = 0;
    nodeCount++;
}
// Function to add an adjacent node to an existing node
void addAdjacent(int u, int v, int cost)
{
    for (int i = 0; i < nodeCount; i++)
    {
        if (arr[i].nodeid == u)
        {
            int c = arr[i].adjcount;
            arr[i].adjs[c] = v; // Add the adjacent node
            arr[i].costs[c] = cost; // Add the cost associated with the edge
            arr[i].adjcount++;
            break;
        }
    }
}
// Function to read the graph data from the user
void read_graph()
{
    valid = 1;
    printf("\t\tEnter the number of nodes : ");
    scanf("%d", &n);
    printf("\t\tEnter the number of edges : ");
    scanf("%d", &e);
    printf("\t\tEnter graph data(u,v,cost) : ");
    for (int i = 0; i < e; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        addNode(u); // Add node 'u' if it doesn't exist
        addNode(v); // Add node 'v' if it doesn't exist
        addAdjacent(u, v, c); // Add the edge (u, v) with cost 'c'
        addAdjacent(v, u, c); // Add the reverse edge (v, u) with the same cost
    }
}
// Function to check if two nodes are adjacent
int isAdjacent(int u, int v) {
    for (int i = 0; i < arr[u].adjcount; i++) {
        if (arr[u].adjs[i] == arr[v].nodeid) {
            return 1; // Nodes are adjacent
        }
    }
    return 0; // Nodes are not adjacent
}
int calCost(int u,int v){
    for (int i = 0; i < arr[u].adjcount; i++) {
        if (arr[u].adjs[i] == arr[v].nodeid) {
            return arr[u].costs[i];
        }
    }
    return 0;
}
/// @brief 
void calMinCost(){
    for(int i=0;i<count_Triangle;i++){
        if(costs[i] < minCost){
            minCost = costs[i];
            minCostTrianlgeIndex = i;
        }
    }
}
void determineIndex(){
    for(int i=0;i<count_Triangle;i++){
        if(costs[i] < minCost){
            minCost = costs[i];
            minCostTrianlgeIndex = i;
        }
    }
}
// Function to count triangles in the graph
void countTriangles() {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = i + 1; j < nodeCount; j++) {
            for (int k = j + 1; k < nodeCount; k++) {
                if (isAdjacent(i, j) && isAdjacent(j, k) && isAdjacent(k, i)) {
                    triangles[count_Triangle][0] = arr[i].nodeid;
                    triangles[count_Triangle][1] = arr[j].nodeid;
                    triangles[count_Triangle][2] = arr[k].nodeid;
                    costs[count_Triangle] = calCost(i,j) + calCost(j,k) + calCost(k,i);
                    count_Triangle++;
                }
            }
        }
    }
}

int main() {
    system("Color AF");
    printf("\n\n");
    printf("\t\t\t***************************************************************************\n");
    printf("\t\t\t*                    Find The Number of Triangles in a Graph               *              \n");
    printf("\t\t\t***************************************************************************\n\n\n");
    int choice;
    while (choice != 6) {
        printf("\n1. Construct The Graph\n");
        printf("2. Number Of Triangles\n");
        printf("3. Print all the Triangles\n");
        printf("4. print Minimum Cost among all Triangle\n");
        printf("5. print the Triangle that Cost is minimum\n");
        printf("6. Exit\n");

        printf("\n\tPlease Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(valid == 0)
                read_graph(); // Read the graph data from the user
                else
                printf("\n\t\tGraph is already read.");
                break;

            case 2:
                if(valid == 1){
                    countTriangles(); // Count the triangles in the graph
                    printf("\n\t\tTotal triangles : %d\n\n", count_Triangle);
                }
                else{
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                break;

            case 3:
                if(valid == 1){
                    printf("\n\tTriangles:\n");
                    for (int i = 0; i < count_Triangle; i++) {
                        printf("\t\tTriangle %d: %d %d %d\n", i + 1, triangles[i][0], triangles[i][1], triangles[i][2]);
                    }
                    printf("\n");
                }
                else{
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                break;
            case 4 : 
                    if(valid == 1){
                        calMinCost();
                        printf("\n\t\tMinimum Cost among all : %d\n",minCost);
                        printf("\n");
                    }
                    else{
                        printf("\n\t\tPlease construct the Graph first.\n");
                    }
                    break;
            case 5:
                    if(valid == 1){
                        if(minCostTrianlgeIndex == -1){
                            determineIndex();
                        }
                        printf("\n\t\tThe Triangle with the Minimum Cost : ");
                        for(int i = 0;i<3;i++){
                            printf("%d ",triangles[minCostTrianlgeIndex][i]);
                        }
                        printf("\n");
                    }
                    else{
                        printf("\n\t\tPlease construct the Graph first.\n");
                    }
                    break;
            case 6:
                    printf("\n\n\t\t\tThank You Sir!\n\n\n");
                    exit(0); // Exit the program
                    break;
            default:
                printf("\t\tInvalid choice\n");
        }
    }

    return 0;
}