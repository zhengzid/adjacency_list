#include <stdio.h>

typedef struct Node
{
	int dest;				//邻接边的弧头结点序号
	struct Node *next;		//指向下一条邻接边
}Edge;                      

typedef struct
{
	int name;				//结点的一些数据，比如名字
	Edge *firstAdj;			//邻接边头指针 第一个邻接点
}AdjHeight;					//数组的数据元素类型的结构体

void createGragh(AdjHeight *list,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        list[i].name=i+1;
        list[i].firstAdj=NULL;
    }
}

void addEdge(AdjHeight *list,int a1,int a2)
{
    Edge *e;
    e=(Edge*)malloc(sizeof(Edge));
    e->dest=a2;
    e->next=NULL;
    printf("在%d-%d之间插入边\n",a1,a2);
	list[a1-1].name=a1;
    if(list[a1-1].firstAdj!=NULL)
    {
        Edge *edge = list[a1-1].firstAdj;
        while(edge->next!=NULL)
            edge=edge->next;
        edge->next=e;
    }
    else{
        list[a1-1].firstAdj=e;
    }
}


int main()
{
    printf("你好，世界！\n");
    
    int n=10;
    AdjHeight adjList[n];

    createGragh(adjList,n);//创建图 

	//添加弧
    addEdge(adjList,1,2);
    addEdge(adjList,1,4);
    addEdge(adjList,1,5);
	addEdge(adjList,5,2);

    int i;
    for(i=0;i<max;i++)
    {
        printf("adj: %d -> ",adjList[i].name);
        Edge *edge = adjList[i].firstAdj;
        if(edge!=NULL)
        {
            while(edge!=NULL)
            {
                printf("NODE：%d -> ",edge->dest);
                edge=edge->next;
            }
        }
        printf("\n\n");
    }

    return 0;
}
