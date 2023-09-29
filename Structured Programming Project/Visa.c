#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NODES 50
int n, e, nodeCount = 0,src,destination,visa,x,valid = 0;
static int totalPath = 0;
int visited[MAX_NODES], vis_cost[MAX_NODES], visit_count = 0,pathCost[MAX_NODES],minPathIndex;
int paths[MAX_NODES][50];
struct Node
{
    int nodeid;
    int adjcount,visaCount;
    int adjs[10];
    int costs[10];
    int visas[10];
};
struct Node arr[MAX_NODES];
void addNode(int nid)
{
    for(int i=0;i<nodeCount;i++)
    {
        if(arr[i].nodeid == nid)
        {
            return;
        }
    }
    arr[nodeCount].nodeid = nid;
    arr[nodeCount].adjcount = 0;
    nodeCount++;
}
void addAdjacent(int u,int v,int cost)
{
    for(int i=0;i<nodeCount;i++)
    {
        if(arr[i].nodeid == u)
        {
            int c = arr[i].adjcount;
            arr[i].adjs[c] = v;
            arr[i].costs[c] = cost;
            arr[i].adjcount++;
            break;
        }
    }
}
void read_graph()
{
    valid = 1;
    printf("\t\tEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\t\tEnter the number of edges : ");
    scanf("%d",&e);
    printf("\t\tEnter graph data(u,v,cost) : ");
    for(int i=0;i<e;i++)
    {
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        addNode(u);addNode(v);
        addAdjacent(u,v,c);
        addAdjacent(v,u,c);
    }
}
void add_path()
{
    int i = 0,j = 0,cost = 0;
    paths[totalPath][i] = src;
    for(i = 1; j < visit_count; i++,j++)
    {
        cost += vis_cost[i];
        paths[totalPath][i] = visited[j];
    }
    paths[totalPath][i] = -1;
    pathCost[totalPath] = cost;
    totalPath++;
    printf("\n");
}
int is_visited(int x)
{
    for (int i = 0; i < visit_count; i++)
    {
        if (visited[i] == x)
            return 1;
    }
    return 0;
}
int can_go(int v){
    for(int i=0;i<arr[src].visaCount;i++){
        if(arr[src].visas[i] == v){
            return 1;
        }
    }
    return 0;
}
int minCost(){
    int ans = 10000000;
    for(int i=0;i<totalPath;i++){
        if(pathCost[i] < ans){
            ans = pathCost[i];
            minPathIndex = i;
        }
    }
    return ans;
}
void findPath(int start, int end)
{
    if (visited[visit_count - 1] == end)
    {
        add_path();
    }
    int index = 0;
    for (int i = 0; i < nodeCount; i++)
    {
        if (arr[i].nodeid == start)
        {
            index = i;
            break;
        }
    }

    for (int i = 0; i < arr[index].adjcount; i++)
    {
        if (!is_visited(arr[index].adjs[i]) && can_go(arr[index].adjs[i]))
        {
            visited[visit_count] = arr[index].adjs[i];
            vis_cost[visit_count++] = arr[index].costs[i];
            findPath(arr[index].adjs[i], end);
            visit_count--;
        }
    }
}
int main()
{
    system("Color 3F");
    printf("\n\n");
    printf("\t\t\t***************************************************************************\n");
    printf("\t\t\t*                    Possbile Path with Visa                              *              \n");
    printf("\t\t\t***************************************************************************\n\n\n");
    int choice,flag = 0;
    printf("\n1. Construct The Graph\n");
    printf("2. Number of Path with Visa\n");
    printf("3. Print all the Path\n");
    printf("4. Minimum Cost to Reach the Destination\n");
    printf("5. Print The Minimum cost Path\n");
    printf("6. Exit\n");
    while (choice) {

        printf("\n\tPlease Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(valid == 0)
                read_graph();
                else
                printf("\t\tGraph is already read.");
                break;

            case 2:
                if(valid){
                    flag = 1;
                    printf("\t\tPlease enter the source : ");
                    scanf("%d",&src);
                    printf("\t\tNumber of Visa %d have : ",src);
                    scanf("%d",&visa);
                    arr[src].visaCount = visa;
                    printf("\n\t\tPlease enter all the visa of %d : ",src);
                    for(int i=0;i<visa;i++){
                        scanf("%d",&x);
                        arr[src].visas[i] = x;
                    }
                    printf("\nPlease Enter Your Destination : ");
                    scanf("%d",&destination);
                    findPath(src,destination);
                    printf("\n\t\tYou Can Go Your destination by : %d ways\n\n",totalPath);
                }
                else{
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                break;

            case 3:
                if(valid == 1 && flag){
                    printf("\n\tPaths :\n");
                    for (int i = 0; i < totalPath; i++) {
                        int j=0;
                        printf("\t\tPath %d : ", i + 1);
                        while(paths[i][j] != -1){
                            if(paths[i][j] != -1)
                            printf("%d ",paths[i][j++]);
                        }
                        printf("\n");
                    }
                    printf("\n\n");
                }
                else if(valid == 0){
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                else{
                    printf("\n\t\tPlease Fixed Your Destination first.\n");
                }
                break;
            case 4 : 
                if(valid && flag){
                    printf("Minimum Cost to Reach Your destination : %d\n",minCost());
                    printf("\n\n");
                }
                else if(valid == 0){
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                else{
                    printf("\n\t\tPlease Fixed Your Destination first.\n");
                }
                break;
            case 5 : 
                if(valid && flag){
                    printf("The Path with Minimum Cost : ");
                    int j = 0;
                    while(paths[minPathIndex][j] != -1){
                        printf("%d ",paths[minPathIndex][j++]);
                    }
                    printf("\n\n");
                }
                else if(valid == 0){
                    printf("\n\t\tPlease construct the Graph first.\n");
                }
                else{
                    printf("\n\t\tPlease Fixed Your Destination first.\n");
                }
                break;
            case 6:
                printf("\n\n\t\t\tThank You!\n\n\n");
                exit(0);

            default:
                printf("\t\tInvalid choice\n");
        }
    }
    return 0;
}