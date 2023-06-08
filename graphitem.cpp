#include "graphitem.h"
#include <fstream>

Graph::Graph()
{

}

vector<int>* Graph::getVertexes()
{
    return &vertexes;
}

vector<vector<int>>* Graph::getConnection()
{
    return &connection;
}

void Graph::addVertex(int vertex)
{
    vertexes.push_back(vertex);
    connection.resize(connection.size() + 1);
}

void Graph::setVertexes(vector<int> vertexes)
{
    this->vertexes = vertexes;
    connection.resize(vertexes.size());
}

void Graph::setConnections(vector<vector<int>> connections)
{
    this->connection = connections;
}

void Graph::addConnection(int from, int to)
{
    for(int i = 0; i < vertexes.size(); i++)
        if(vertexes[i] == from)
            connection[i].push_back(to);
}

string Graph::toGraphString()
{
    string res = to_string(vertexes.size()) + "\n";
    for(int i = 0; i < connection.size(); i++){
        res += names.at(i) + " ";
        for(int j = 0; j < connection[i].size(); j++){
            res += to_string(IndexOf(&vertexes, connection[i][j]));
            res += " ";
        }
        res += "\n";
    }
    return res;
}

void Graph::addNames(vector<string> names)
{
    this->names = names;
}

string Graph::getName(int i)
{
    return names.at(i);
}

vector<string> *Graph::getNames()
{
    return &names;
}

int Graph::IndexOf(vector<int> *vec, int val)
{
    for(int i = 0; i < vec->size(); i++)
        if(vec->at(i) == val)
            return i;
}
