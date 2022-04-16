#include <vector>

using namespace std;

class Node
{
    private:
        string name;
        double score;
        vector<string> genres;
        vector<double> edges;
    public:
        Node(string name, double score, vector<string> genres)
        {
            this->name = name;
            this->score = score;
            this->genres = genres;
        }

        string getName()
        {
            return name;
        }

        double getScore()
        {
            return score;
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