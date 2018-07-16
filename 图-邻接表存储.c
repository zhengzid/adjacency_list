#include <stdio.h>

typedef struct Node
{
	int dest;				//�ڽӱߵĻ�ͷ������
	struct Node *next;		//ָ����һ���ڽӱ�
}Edge;                      

typedef struct
{
	int name;				//����һЩ���ݣ���������
	Edge *firstAdj;			//�ڽӱ�ͷָ�� ��һ���ڽӵ�
}AdjHeight;					//���������Ԫ�����͵Ľṹ��

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
    printf("��%d-%d֮������\n",a1,a2);
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
    printf("��ã����磡\n");
    
    int n=10;
    AdjHeight adjList[n];

    createGragh(adjList,n);//����ͼ 

	//��ӻ�
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
                printf("NODE��%d -> ",edge->dest);
                edge=edge->next;
            }
        }
        printf("\n\n");
    }

    return 0;
}
