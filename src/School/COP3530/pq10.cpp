#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Edge {
	int src, dest, weight;
	Edge(int _src, int _dest, int _weight) {src = _src; dest = _dest; weight = _weight;}
};

class Graph {
public:
	int numVertices;
    int src = 0, dst = 0;
	vector<vector<pair<int, int>>> adjList; 
    // e.g. 0: {1, 12}, {2, 4} -> the weight from vertex 0 to 1 is 12 
    //                        and the weight from vertex 0 to 2 is 4

	Graph(const vector<Edge>& edges, int vertices) {
		numVertices = vertices;

		adjList.resize(vertices);

		for (auto &edge : edges) {
			adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));
		}
	}
};

Graph makeGraph(vector<string>& graph)
{
    vector<Edge> edges;
    vector<vector<char>> points;
    for(int row = 0; row < graph.size(); row++)
    {
        points.push_back(vector<char>());
        for(int col = 0; col < graph.at(row).length(); col++)
        {
            points.at(row).push_back(graph.at(row).at(col));
        }
    }

    int start, end;

    vector<pair<int, int>> moves;
    moves.push_back(make_pair(-1, 0));
    moves.push_back(make_pair(0, -1));
    moves.push_back(make_pair(1, 0));
    moves.push_back(make_pair(0, 1));

    for(int i = 0; i < points.size(); i++)
    {
        for(int j = 0; j < points.at(i).size(); j++)
        {
            if(points.at(i).at(j) != '.')
            {
                if(points.at(i).at(j) == 's') start = (i * points.at(i).size()) + j;
                if(points.at(i).at(j) == 't') end = (i * points.at(i).size()) + j;
                for(pair<int, int> movement : moves)
                {
                    if(i + movement.first >= 0 && i+movement.first < points.size())
                    {
                        if(j + movement.second >= 0 && j+movement.second < points.at(i).size())
                        {
                            char dst = points.at(i + movement.first).at(j + movement.second);
                            if(dst != '.')
                            {
                                int weight = (dst == 's' || dst == 't') ? 0 : dst - '0';
                                edges.push_back(Edge((i * points.at(i).size()) + j, ((i+movement.first) * points.at(i).size()) + j+movement.second, weight));
                            }
                        }
                    }
                }
            }
        }
    }
    int vertices = points.size() * points.at(0).size();
    Graph g = Graph(edges, vertices);
    g.src = start;
    g.dst = end;
    return g;
}

int shortestDist(unordered_set<int>& unvisited, vector<int>& distances)
{
    int smallestValue = INT_MAX, smallest = -1;
    for(auto it = unvisited.begin(); it != unvisited.end(); it++)
    {
        if(distances[*it] < smallestValue)
        {
            smallestValue = distances[*it];
            smallest = *it;
        }
    }
    return smallest;
}

int dijkstra(std::vector<std::string> & graph) 
{

    Graph g = makeGraph(graph);

    unordered_set<int> unvisited;
    for(int i = 0; i < g.numVertices; i++)
    {
        unvisited.emplace(i);    
    }
    vector<int> distances(g.numVertices, INT_MAX);
    distances[g.src] = 0;
    while(!unvisited.empty())
    {
        int index = shortestDist(unvisited, distances);
        if(index == -1) break;
        unvisited.erase(index);
        int baseDist = distances[index];
        for(pair<int, int> edge : g.adjList.at(index))
        {
            if(unvisited.find(edge.first) != unvisited.end())
            {
                if(baseDist + edge.second < distances[edge.first])
                {
                    distances[edge.first] = baseDist + edge.second;    
                }
            }
        }
    }
    return distances[g.dst];
}

int main()
{

    vector<string> graph;
    graph.push_back("s3153");
    graph.push_back("1.424");
    graph.push_back("22.3t");

    return dijkstra(graph);

    return 0;
}