#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
    int intDistrict = 0;
    bool visited = false;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2);
        void addVertex(std::string name);
        void displayEdges();
        void dispVertices();
        void emptyG();
        void newRoom(int);
        std::vector<vertex> giveVertices();
        void addAdj();
    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;

};

#endif // GRAPH_H
