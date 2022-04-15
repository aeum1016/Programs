#include <vector>

using namespace std;

class Node
{
    private:
        string name;
        vector<string> genres;
        vector<double> edges;
    public:
        Node(string name, vector<string> genres)
        {
            this->name = name;
            this->genres = genres;
        }

        string getName()
        {
            return name;
        }

        vector<string> getGenres()
        {
            return genres;
        }

        vector<double> getEdges()
        {
            return edges;
        }

        void addEdge(double weight)
        {
            edges.push_back(weight);
        }
};