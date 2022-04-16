#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "json-develop/single_include/nlohmann/json.hpp"

#include "Graph.cpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    json jDramas;
    json jAnimes;
    ifstream dramaifs("top_5000_mydramalist.json");
    ifstream animeifs("animes.json");

    dramaifs >> jDramas;
    animeifs >> jAnimes;

    Graph all;
    Graph dramas;
    Graph animes;
    for(int i = 0; i < jDramas.size(); i++)
    {
        auto rank = jDramas[i].at("ranking");
        if(rank <= 3000 && !rank.is_null())
        {
            vector<string> genres = jDramas[i].at("genres");
            double score = jDramas[i].at("ratings");
            all.addVertice(jDramas[i].at("name"), score/10, genres);
            dramas.addVertice(jDramas[i].at("name"), score/10, genres);
        }
    }

    for(int i = 0; i < jAnimes.size(); i++)
    {
        auto rank = jAnimes[i].at("ranked");
        if(rank <= 1500 && !rank.is_null())
        {
            string genresString = jAnimes[i].at("genre");
            genresString = genresString.substr(1, genresString.length()-2);
            vector<string> genres;
            stringstream ss(genresString);
            while (ss.good()) {
                string genre;
                getline(ss, genre, ',');
                if(genre.size() != 0)
                {
                    if(genre.at(0) == ' ') genre = genre.substr(1);
                    genre = genre.substr(1, genre.length()-2);
                    genres.push_back(genre);
                }
            }
            string scoreString = jAnimes[i].at("score");
            if(scoreString == "") scoreString = "0";
            double score = stof(scoreString);
            all.addVertice(jAnimes[i].at("title"), score/10.0, genres);
            animes.addVertice(jAnimes[i].at("title"), score/10.0, genres);
        }
    }
    animes.computeEdges();
    dramas.computeEdges();
    animes.printGraph();
    dramas.printGraph();

    return 0;
}