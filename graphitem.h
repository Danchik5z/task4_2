#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
using namespace std;


class Graph
{
public:
    Graph();
    vector<int>* getVertexes();
    vector<vector<int>>* getConnection();
    void addVertex(int vertex);
    void setVertexes(vector<int> vertexes);
    void setConnections(vector<vector<int>> connections);
    void addConnection(int from, int to);
    string toGraphString();
    void addNames(vector<string> names);
    string getName(int i);
    vector<string>* getNames();
    int IndexOf(vector<int> *vec, int val);
private:
    vector<string> names;
    vector<int> vertexes;
    vector<vector<int>> connection;
};

#endif // GRAPH_H
