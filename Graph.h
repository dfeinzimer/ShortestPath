#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Graph {
private:
    int num_vertices;
    int **matrix;
    bool *visited;
public:
    Graph(int _num_vertices) {
        this->num_vertices = _num_vertices;
        visited = new bool [_num_vertices];
        matrix = new int* [_num_vertices];
        for (int i = 0; i < _num_vertices; i++)
        {
            matrix[i] = new int [_num_vertices];
            for(int j = 0; j < _num_vertices; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    void DFS(int a, int b, vector<int> &path) {
        if (a != b) {
            visited[a] = 1;
            for (int i = 0; i < num_vertices; i++) {
                if (matrix[a][i] == 1 && visited[i] == false) {
                    path.push_back(i);
                    a = i;
                    DFS(a,b,path);
                }
            }
        }
        
    }
    
    bool are_connected(int a, int b) {
        if (matrix[a][b] == 1) {return true;}
        else if (matrix[b][a] == 1) {return true;}
        else return false;
    }
    
    vector<int> getPath(int a, int b) {
        vector<int> path;
        path.push_back(a);
        DFS(a, b, path);
        path.push_back(b);
        return path;
    }
    
    void add_edge(int left, int right) {
        if( left > num_vertices || right > num_vertices || left < 0 || right < 0) {
            return;
        }
        else {
            matrix[left][right] = 1;
        }
    }
};
