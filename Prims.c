#include<stdio.h>
#include<malloc.h>
#include<time.h>
#define edge_weight 500

int **weight;
int Min_Cost=edge_weight+1;
int visited[500]={0};
int Final_Cost=0;
int p,q,u,v,i,j;

//Matrix allocation-> dynamic
int Allocation(int vertices)
{
  weight=(int**)malloc(vertices*sizeof(int*));
  for(i=1;i<=vertices;i++)
    weight[i]=malloc(vertices*sizeof(int));
}

//Finding the adjacency matrix and assigning weight
int Adjacency_Matrix(int vertices)
{
    int r;
    int min=1;
    int max=vertices;
    for(j=1;j<=vertices;j++)
    {
      if(i==j)
        weight[i][j]=edge_weight;
      else
      {
	r = (rand() % (max+1-min))+min;
        weight[i][j]=r;
        if(weight[i][j]==0)
          weight[i][j]=edge_weight;
        weight[j][i]=weight[i][j];
      }
    }
}

//Extract the minimum weight valued edges
int Extractmin(int vertices)
{
   for(i=1,Min_Cost=edge_weight;i<=vertices;i++)
     for(j=1;j<=vertices;j++)
       if(weight[i][j]<Min_Cost)
         if(visited[i]!=0)
         {
           Min_Cost=weight[i][j];
	   u=i;
           p=u;
           v=j;
	   q=v;
         }
}

//Relaxation
int Decreasekey(int vertices)
{
    weight[p][q]=edge_weight;
    weight[q][p]=edge_weight;
}

//main
main()
{
  clock_t Clock_Start_Time,Clock_End_Time;
  double Total_CPU_Time;

  int vertices,edges=1;
  printf("\nEnter the number of vertices:");
  scanf("%d",&vertices);
  if (vertices<=1)
  {
   printf("\nError!!Enter the number of vertices:");
   scanf("%d",&vertices);    
  }

  Allocation(vertices);
  for(i=1;i<=vertices;i++)
   Adjacency_Matrix(vertices);

  /*for(i=1;i<=vertices;i++)
  {
    printf("\n");
    for(j=1;j<=vertices;j++)
      printf("%d\t",weight[i][j]);
  }*/

  //clock start
  Clock_Start_Time=clock();
  visited[1]=1;
  while(edges<vertices)
  {
    Extractmin(vertices);
    if(visited[u]==0||visited[v]==0)
    {
      Final_Cost+=Min_Cost;
      visited[q]=1;
      edges++;
    }
    Decreasekey(vertices);
  }
  Clock_End_Time=clock();
  //clock end

  Total_CPU_Time=((double)(Clock_End_Time-Clock_Start_Time))/CLOCKS_PER_SEC;

  printf("\nMST Cost=%d",Final_Cost);
  printf("\nTime:%lf",Total_CPU_Time);
  printf("\n");
}
