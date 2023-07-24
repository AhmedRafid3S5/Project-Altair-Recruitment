#include<stdbool.h>
#include<stdio.h>
#define Vertex_Limit 100

///Note: Number of vertices or location can be changed with the Vertices variable;
///edges can be added to the edges 2D matrix


int Vertices = 7; // num of locations
bool vertexVisited[Vertex_Limit]; //true if vertex i is visited, false if vertex i isn't visited
int adj_matrix[Vertex_Limit][Vertex_Limit];

void dfs(int current_vertex) // using global variables, so no parameters
{
   vertexVisited[current_vertex] = true;

   for(int i=0;i<Vertices;i++)
   {

    if(adj_matrix[current_vertex][i] == 1 && vertexVisited[i] == false)
            dfs(i);


   }
}

bool has_path()
{
    dfs(0);

    for(int i=0;i<Vertices;i++)
        if(vertexVisited[i] ==  false)
          return false;

    return true;
}

void print_edges(int edges[][2],int size)
{
     for(int i=0;i<size;i++)
    {
        for(int j=0;j<2;j++)
           printf("%d,",edges[i][j]);

        printf("\n");
    }
    printf("\n");
}

void print_adj_list(int adj_matrix[][7],int size_of_matrix)
{
    for(int i=0;i<size_of_matrix;i++){
        for(int j=0;j<size_of_matrix;j++){
           printf("%d, ",adj_matrix[i][j]);
        }
    printf("\n");
    }
    printf("\n");
}

int main()
{

    printf("Number of vertices:%d\n",Vertices);


    int edges[][2] = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3}};
    printf("Provided edge information:\n");


    //Filling edge info (enable edge input in console)
   /* for(int i=0;i<Vertices;i++)
    {
        scanf("%d,%d",&edges[i][0],&edges[i][1]);
    }*/

    //Initializing the adj_matrix with 0 ( 0 = no path, 1 = path exists )
    for(int i=0;i<Vertex_Limit;i++)
        for(int j=0;j<Vertex_Limit;j++)
           adj_matrix[i][j]=0;

    //Forming the adjacency list
    for(int i=0;i<sizeof(edges)/sizeof(edges[0]);i++){

            int start = edges[i][0];
            int end = edges[i][1];
            adj_matrix[start][end] = 1;
            adj_matrix[end][start] = 1;

    }

    print_edges(edges,sizeof(edges)/sizeof(edges[0]));

    //Print Adj list
    printf("Adjacency matrix:\n");
   for(int i=0;i<Vertices;i++){
        for(int j=0;j<Vertices;j++)
           printf("%d, ",adj_matrix[i][j]);
    printf("\n");
    }
    printf("\n");
    //-----------------------------------

    if(has_path() == false)
        printf("No path to all location\n");
    else
        printf("There is a path to all the locations\n");




}
