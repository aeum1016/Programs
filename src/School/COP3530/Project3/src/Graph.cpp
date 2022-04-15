#include <iostream>
#include <vector>
#include <string>

#include "Node.cpp"

using namespace std;

class Graph
{
    private:
        vector<Node> vertices;
    public:
        bool addVertice(string name, vector<string> genres)
        {
            vertices.push_back(Node(name, genres));
            return true;
        }
        void printGraph()
        {
            for(Node node : vertices)
            {
                cout << node.getName() << endl;
                for(int i = 0; i < node.getGenres().size(); i++)
                {
                    cout << node.getGenres().at(i) << " ";
                }
                cout << endl;
                for(int i = 0; i < node.getEdges().size(); i++)
                {
                    cout << node.getEdges().at(i) << " ";
                }
                cout << endl;
            }
        }
        void computeEdges()
        {
            for(int i = 0; i < vertices.size(); i++)
            {
                if(i % 100 == 0) cout << i;
                for(int j = 0; j < 100; j++)
                {
                    double relatedness = 0.0;
                    for(string genre : vertices[i].getGenres())
                    {
                        for(string genre2 : vertices[j].getGenres())
                        {
                            if(genre == genre2) relatedness += 1.0/vertices[i].getGenres().size();
                        }
                    }
                    vertices[i].addEdge(relatedness);
                }
            }
        }


};