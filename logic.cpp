#include "logic.h"
#include <fstream>
#include <bits/stdc++.h>

Logic::Logic()
{

}

Graph Logic::readFileItem(string file)
{
    Graph item;
    vector<vector<int>> connections;
    string nextLine;
    vector<string> names;

    ifstream myFile(file);

    getline (myFile, nextLine);
    while (getline (myFile, nextLine)) {
        vector<int> vertex;
        stringstream ss(nextLine);
            string tok;
            ss >> tok;
            names.push_back(tok);
            while (ss >> tok) {
                vertex.push_back(stoi(tok));
            }
            connections.push_back(vertex);
    }
    myFile.close();
    vector<int> vertex;
    for(int i = 0; i < connections.size(); i++)
        vertex.push_back(i);
    item.setVertexes(vertex);
    item.setConnections(connections);
    item.addNames(names);
    return item;
}

void Logic::writeFile(string file, Graph* item)
{
    fstream myfile;
    myfile.open (file);
    myfile << item->toGraphString();
    myfile.close();
}

vector<Graph> Logic::splitGraph(int startVertex, Graph* itemToSplit)
{
    vector<Graph> res;
    vector<int> currentLevlVertexes;
    vector<bool> visited;
    vector<int>* vertexes = itemToSplit->getVertexes();
    vector<vector<int>>* connection = itemToSplit->getConnection();

    for(int i = 0; i < vertexes->size(); i++)
        visited.push_back(false);
    currentLevlVertexes.push_back(startVertex);

    while(hasFalse(&visited) && currentLevlVertexes.size() != 0){
        res.push_back(makeItem(currentLevlVertexes, connection, vertexes, itemToSplit->getNames()));
        vector<int> nextLevlVertexes;
        for(int i = 0; i < currentLevlVertexes.size(); i++)
            visited[indexOf(vertexes, currentLevlVertexes[i])] = true;
        for(int i = 0; i < currentLevlVertexes.size(); i++)
            for(int j = 0; j < connection->at(indexOf(vertexes, currentLevlVertexes[i])).size(); j++)
                if(!contains(&nextLevlVertexes, connection->at(indexOf(vertexes, currentLevlVertexes[i])).at(j)) && !visited[indexOf(vertexes, connection->at(indexOf(vertexes, currentLevlVertexes[i])).at(j))])
                    nextLevlVertexes.push_back(connection->at(indexOf(vertexes, currentLevlVertexes[i])).at(j));
        currentLevlVertexes = nextLevlVertexes;
    }
    return res;
}

int Logic::indexOf(vector<int> *vec, int val)
{
    for(int i = 0; i < vec->size(); i++)
        if(vec->at(i) == val)
            return i;
    return -1;
}

Graph Logic::makeItem(vector<int> vertexes, vector<vector<int>>* connection, vector<int>* allVertexes, vector<string>* allNames)
{
    Graph item;
    vector<string> names;
    for(int i = 0; i < vertexes.size(); i++)
        names.push_back(allNames->at(indexOf(allVertexes, vertexes[i])));
    item.addNames(names);

    item.setVertexes(vertexes);    
    for(int i = 0; i < vertexes.size(); i++)
        for(int j = 0; j < vertexes.size(); j++)
            if(contains(&connection->at(indexOf(allVertexes, vertexes[i])), vertexes[j]))
                item.addConnection(vertexes[i], vertexes[j]);
    return item;
}

bool Logic::hasFalse(vector<bool>* vec)
{
    for(int i = 0; i < vec->size(); i++)
        if(!vec->at(i))
            return true;
    return false;
}

bool Logic::contains(vector<int> *vec, int a)
{
    for(int i = 0; i < vec->size(); i++)
        if(vec->at(i) == a) return true;
    return false;
}
