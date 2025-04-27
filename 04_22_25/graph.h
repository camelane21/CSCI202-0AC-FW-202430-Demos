#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

class graphType
{
public:
    bool isEmpty() const;
    void createGraph(std::string);
    void clearGraph();
    std::string printGraph();
    graphType(int size = 0);
    graphType(const graphType &);
    ~graphType();
    const graphType &operator=(const graphType &);
    std::string depthFirstTraversal();
    std::string dftAtVertex(int vertex);
    std::string breadthFirstTraversal();
    bool connected(int, int);

protected:
    int maxSize;
    // int gSize;
    // unorderedLinkedList<int> *graph;
    std::vector<unorderedLinkedList<int>> graph;

private:
    void dft(int v, bool visited[], std::string &output);
    void copyGraph(const graphType &);
};
inline bool graphType::connected(int vertex1, int vertex2)
{
    if (vertex1 < 0 || vertex1 >= graph.size() || vertex2 < 0 || vertex2 >= graph.size())
    {
        throw std::out_of_range("Vertex index out of range.");
    }

    nodeType<int> *current = graph[vertex1].first;
    while (current != nullptr)
    {
        if (current->info == vertex2)
        {
            return true;
        }
        current = current->link;
    }
    return false;
}
#endif
