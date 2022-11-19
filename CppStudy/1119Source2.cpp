#include <iostream>

using namespace std;

enum VisitMode{ visit, notVisited};

struct S_Edge 
{
	int weight;
	struct S_Edge* next;
    struct S_Vertex* from;
    struct S_Vertex* Target;
};

struct S_Vertex
{
	int nData;
	VisitMode visitedMode;

	int nIndex = 0;
    struct  S_Vertex* S_Next;
    struct  S_Edge* AdjacenyList;
};

typedef struct S_Graph
{
    struct  S_Vertex* vectices;
	int VertexCount;
};

S_Graph* CreateGraph()
{
    S_Graph* graph = new S_Graph;
    graph->vectices = nullptr;
    graph->VertexCount = 0;

    return graph;
}

S_Vertex* CreateVertext(int nData)
{
    S_Vertex*V = new S_Vertex;
    V->nData = nData;
    V->S_Next = nullptr;
    V->AdjacenyList = nullptr;
    V->visitedMode = notVisited;
    V->nIndex = -1;

    return V;
}

S_Edge *CreateEdge(S_Vertex* From, S_Vertex* Target, int Weight)
{
    S_Edge* E = new S_Edge;
    E->from = From;
    E->Target = Target;
    E->next = nullptr;
    E->weight = Weight;

    return E;
}

void AddVertex(S_Graph* G, S_Vertex* V)
{
    S_Vertex* VertexList = G->vectices;
    if (VertexList == NULL)
    {
        G->vectices = V;
    }
    else
    {
        while (VertexList->S_Next != NULL)
        {
            VertexList = VertexList->S_Next;
        }

        VertexList->S_Next = V;
    }

    V->nIndex = G->VertexCount;
}

void AddEdge(S_Vertex* V, S_Edge* E)
{
    if (V->AdjacenyList == NULL)
    {
        V->AdjacenyList = E;
    }
    else
    {
        S_Edge* AdjacenyList = V->AdjacenyList;

        while (AdjacenyList->next != NULL)
            AdjacenyList = AdjacenyList->next;

        AdjacenyList->next = E;
    }
}

void PrintGraph(S_Graph *G)
{
    S_Vertex *V = NULL;
    S_Edge* E = NULL;

    if ((V = G->vectices) == NULL)
        return;

    while (V != NULL)
    {
        std::cout << V->nData << " ";

        if ((E = V->AdjacenyList) == NULL)
        {
            V = V->S_Next;
            std::cout << std::endl;
            continue;
        }

        while (E != NULL)
        {
            std::cout << E->Target->nData << "[" << E->weight << "]";
            E = E->next;
        }

        std::cout << std::endl;

        V = V->S_Next;
    }

    std::cout << std::endl;
}

void DFS(S_Vertex* V) //±íÀÌ¿ì¼±Å½»ö
{
    S_Edge* E = NULL;

    cout << V->nData << " ";

    V->visitedMode = visit;

    E = V->AdjacenyList;

    while (E != NULL)
    {
        if (E->Target != NULL && E->Target->visitedMode == notVisited)
        {
            DFS(E->Target);
        }
        E = E->next;
    }
}

int main()
{
    S_Graph* G = CreateGraph();

    S_Vertex* V1 = CreateVertext(1);
    S_Vertex* V2 = CreateVertext(2);
    S_Vertex* V3 = CreateVertext(3);
    S_Vertex* V4 = CreateVertext(4);
    S_Vertex* V5 = CreateVertext(5);
    S_Vertex* V6 = CreateVertext(6);
    S_Vertex* V7 = CreateVertext(7);

    AddVertex(G, V1);
    AddVertex(G, V2);
    AddVertex(G, V3);
    AddVertex(G, V4);
    AddVertex(G, V5);
    AddVertex(G, V6);
    AddVertex(G, V7);

    AddEdge(V1, CreateEdge(V1, V2, 0));
    AddEdge(V1, CreateEdge(V1, V3, 0));

    AddEdge(V2, CreateEdge(V2, V4, 0));
    AddEdge(V2, CreateEdge(V2, V5, 0));

    AddEdge(V3, CreateEdge(V3, V4, 0));
    AddEdge(V3, CreateEdge(V3, V6, 0));

    AddEdge(V4, CreateEdge(V4, V5, 0));
    AddEdge(V4, CreateEdge(V4, V7, 0));

    AddEdge(V5, CreateEdge(V5, V7, 0));

    AddEdge(V6, CreateEdge(V6, V7, 0));

    PrintGraph(G);

    DFS(G->vectices);

    return 0;
}