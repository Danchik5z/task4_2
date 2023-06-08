#ifndef LOGIC_H
#define LOGIC_H

#include <vector>
#include <string>
#include "graphitem.h"
using namespace std;

class Logic
{
public:
    Logic();
    Graph readFileItem(string file);
    void writeFile(string file, Graph* item);
    string toString();
    vector<Graph> splitGraph(int startVertex, Graph* itemToSplit);
private:
    vector<vector<int>> graph;
    int indexOf(vector<int>* vec, int val);
    Graph makeItem(vector<int> vertexes, vector<vector<int>>* connection, vector<int>* allVertexes, vector<string>* allNames);
    bool hasFalse(vector<bool>* vec);
    bool contains(vector<int>* vec, int a);
};

#endif // LOGIC_H
