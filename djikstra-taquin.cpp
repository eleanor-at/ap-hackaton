#include <limits>
#include <map>
#include <stack>
#include "classboard.hpp"

class Graph_board
{
    friend std::map<Board, int> initialiser_distance(Graph_board);
    friend void dijkstra(Graph_board);

private:
    std::map<Board, std::vector<Board>> graph;
    Board begin_game;

public:
    std::vector<Board> crochets(Board);

    bool in(Board, Board, std::map<Board, std::vector<Board>>);

    void ajouter(const Board &s1, const Board &s2)
    {
        graph[s1].push_back(s2);
    }

    Graph_board(Board b) : begin_game(b) {}

    void build_graph()
    {
        std::stack<Board> a_visiter;
        a_visiter.push(begin_game);
        while (not a_visiter.empty())
        {
            Board sommet = a_visiter.top();
            a_visiter.pop();
            for (const auto &elem : sommet.adjacents())
            {
                if (not in(sommet, elem, graph)) // fonction in qui permet de tester la présence d'une arete dans le graphe
                {
                    this->ajouter(sommet, elem);
                }
            }
        }
    }

    std::map<Board, std::vector<Board>>::const_iterator begin() const
    {
        return graph.cbegin();
    }

    std::map<Board, std::vector<Board>>::const_iterator end() const
    {
        return graph.cend();
    }

    std::vector<Board> crochets(Board &sommet)
    {
        std::vector<Board> crochets_sommet;
        auto iter = this->graph.find(sommet);
        if (iter != this->graph.end())
            crochets_sommet = iter->second;
        return crochets_sommet;
    }

};

std::vector<Board> sommet(Graph_board graph)
    {
        std::vector<Board> sommet;
        for (auto &pair : graph)
        {
            sommet.push_back(pair.first);
        }
        return sommet;
    }

std::map<Board, int> initialiser_distance(Graph_board graph)
{
    std::map<Board, int> distance;
    graph.build_graph();
    for (const auto &sommet : graph)
    {
        distance[sommet.first] = -1;
    }
    distance[graph.begin_game] = 0; // dans la classe Graph_board, implémenter la fonction begin
    return distance;
}

Board trouve_sommet_min(std::vector<Board> a_explorer, std::map<Board, int> distance)
{
    int min = std::numeric_limits<int>::infinity();
    Board sommet_min;
    for (int i = 0; i < a_explorer.size(); i++)
    {
        if (distance[a_explorer[i]] < min)
        {
            min = distance[a_explorer[i]];
            sommet_min = a_explorer[i];
        }
    }
    return sommet_min;
}

bool in(Board s1, Board s2, Graph_board graph)
{
    graph.build_graph();
    for (const auto &elem : graph)
    {
        if (elem.first.equal(s1))
        {
            for (const auto &voisin : graph.crochets(elem.first))
            {
                if (voisin.equal(s2))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void maj_distance(Board s1, Board s2, std::map<Board, int> distance, std::vector<Board> successeur)
{
    if (distance[s2] > distance[s1] + 1) // distance du début à s2 est plus grande que celle du début à s2 en passant par s1
                                         //  +1 correspond au poids de l'arete ie le nombre d'étapes
    {
        distance[s2] = distance[s1] + 1;
        successeur.push_back(s2);
    }
}


int index(std::vector<Board> vec, Board s)
{
    int n = 0;
    for (auto& elem : vec)
    {
        if (elem.equal(s))
        {
            return n;
        }
        n+= 1;

    }
}






void dijkstra(Graph_board graph) // affiche le plus court chemin pour gagner la partie
{
    graph.build_graph();
    std::map<Board, int> distance = initialiser_distance(graph);
    std::vector<Board> a_explorer = sommet(graph);
    std::vector<Board> successeur;
    successeur.push_back(graph.begin_game);
    while (a_explorer.size() != 0)
    {
        Board s = trouve_sommet_min(a_explorer, distance);
        a_explorer.erase(a_explorer.begin()+index(a_explorer, s));
        for (const auto &voisin : s.adjacents()) // méthode adjacent qui renvoie les sommets adjacents d'un sommet
        {
            maj_distance(s, voisin, distance, successeur);
        }
    }

    for (const auto &elem : successeur)
    {
        affichage(elem);
    }
}

int main()
{
    Board b;
    b.reset();
    Graph_board g(b);
    return 0;
}