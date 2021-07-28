// AdjacencyList.hpp

typedef int ElementType;

class Vertex;
class Edge;
class Graph;

class Vertex
{
private:
public:
    ElementType data_; // Data value.
    bool visited_; // Check whether visited or not. 1 for visited, and 0 for not visited.
    int index; // Index of the Vertex, Ex) 1, 2, 3, ...

    Vertex *next_vertex_; // Get the list of vertex.
    Edge *adjacency_list_; // 

    ////////////////////////////////////////////////////////////
    Vertex (ElementType _data);

    void AddEdge (Edge *_edge);
};

class Edge
{
private:
public:
    int weight_;
    Edge *next_edge_;

    Vertex *start_;
    Vertex *end_;

    ////////////////////////////////////////////////////////////
    Edge (Vertex *_start, Vertex *_end, int _weight);
};

class Graph
{
private:
public:
    Vertex *vertices_;
    int vertex_count_;

    Graph (void);
    ~Graph (void);

    void AddVertex (Vertex *_vertex);
    void PrintGraph (void);
};