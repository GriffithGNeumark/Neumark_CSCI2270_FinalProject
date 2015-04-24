#include "Graph.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            //cout<<vertices[i].name<<" Adjacent:"<<endl;
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    vertices[i].adj.push_back(av);
                    //cout<<vertices[j].name<<endl;
                    //another vertex for edge in other direction
                    /*
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                    */
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}

vector<vertex> Graph::giveVertices(){
    return vertices;
}

void Graph::dispVertices(){
    for (int y = 0; y < vertices.size(); y++){
        cout<<vertices[y].name<<"->";
        for (int u = 0; u < vertices[y].adj.size(); u++){
            cout<<vertices[y].adj[u].v->name<<" ";
            //cout<<vertices[y].adj[u].v->intDistrict;
            if(u != vertices[y].adj.size()-1){
                cout<<"**";
            }
        }
        cout<<""<<endl;
    }
}

void Graph::emptyG(){
    vertices.clear();
}

void Graph::newRoom(int intRms){
    int intRAdd;
    if (intRms != 0){
        intRAdd = rand() % intRms;
    }
    else{
        intRAdd = 0;
    }
    addVertex(to_string(intRms+1));
    addEdge(to_string(intRAdd), to_string(intRms+1));
    cout<<intRms+1<<" linked to "<<intRAdd<<endl;
}
