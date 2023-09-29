#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50
#define MAX_TRIANGLES 100

int n, e, nodeCount = 0;
int visited[MAX_NODES], visit_count = 0;
int valid = 0;
struct Node {
    int nodeid;
    int adjcount;
    int adjs[10];
};
struct Node arr[MAX_NODES];

int triangles[MAX_TRIANGLES][3];
int count_Triangle = 0;

void addNode(int nid) {
    for (int i = 0; i < nodeCount; i++) {
        if (arr[i].nodeid == nid) {
            return;
        }
    }
    arr[nodeCount].nodeid = nid;
    arr[nodeCount].adjcount = 0;
    nodeCount++;
}

void addAdjacent(int u, int v) {
    for (int i = 0; i < nodeCount; i++) {
        if (arr[i].nodeid == u) {
            int c = arr[i].adjcount;
            arr[i].adjs[c] = v;
            arr[i].adjcount++;
            break;
        }
    }
}

void read_graph() {
    valid = 1;
    printf("\tEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\tEnter the number of edges: ");
    scanf("%d", &e);
    printf("\tEnter graph data:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addNode(u);
        addNode(v);
        addAdjacent(u, v);
        addAdjacent(v, u);
    }
}
int isAdjacent(int u, int v) {
    for (int i = 0; i < arr[u].adjcount; i++) {
        if (arr[u].adjs[i] == arr[v].nodeid) {
            return 1;
        }
    }
    return 0;
}

void countTriangles() {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = i + 1; j < nodeCount; j++) {
            for (int k = j + 1; k < nodeCount; k++) {
                if (isAdjacent(i, j) &&
                    isAdjacent(j, k) &&
                    isAdjacent(k,i)) {
                        triangles[count_Triangle][0] = arr[i].nodeid;
                        triangles[count_Triangle][1] = arr[j].nodeid;
                        triangles[count_Triangle][2] = arr[k].nodeid;
                    count_Triangle++;
                }
            }
        }
    }
}

int main() {
    system("Color 1F");
    printf("\n\n");
    printf("\t\t\t***************************************************************************\n");
    printf("\t\t\t*                    Find The Number of Triangle in a Graph               *              \n");
    printf("\t\t\t***************************************************************************\n\n\n");
    int choice;
    while (choice != 4) {
        printf("\n1. Construct The Graph\n");
        printf("2. Number Of Triangles\n");
        printf("3. Print all the Triangles\n");
        printf("4. Exit\n");

        printf("\n\tPlease Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if(valid == 0)
                read_graph();
                else
                printf("Graph is already read.");
                break;

            case 2:
                if(valid == 1){
                    countTriangles();
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

            case 4:
                exit(0);

            default:
                printf("\t\tInvalid choice\n");
        }
    }

    return 0;
}