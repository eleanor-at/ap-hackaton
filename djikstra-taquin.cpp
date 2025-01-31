#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <stack>

class Graph_board
{
    private:
    std::unordered_map<Board, std::vector<Board> > graph;
    Board begin;

    public:
    std::vector<Board> crochets(Board);

    Bool in(Board s1, Board s2, Graph_board)


    void ajouter(Board s1, Board s2)
    {
        graph.crochets(s1).push(s2);
    }


    Graph_board(Board begin) :

    {
        stack<Board> voisins;
        a_visiter.push(begin);
        while (not a_visiter.empty())
        {
            Board sommet = a_visiter.top();
            a_visiter.pop();
            for (const auto& elem: sommet.adjacent())
            {
                if (not in(sommet, elem, graph)) //fonction in qui permet de tester la présence d'une arete dans le graphe
                {
                    graph.ajouter(sommet, elem);

                }
                
            }
        }


    }
    
    
    std::vector<Board> crochets(Board)
    {
        std::vector;
            for (auto& pair1 : graphe)
            {
                if (pair1.first == name)
                {
                    for (auto& pair2 : pair1.second)
                    {
                        graphe_name[pair2.first] = pair2.second;

                    }
                    return graphe_name;
                }

                
            }
            static const std::unordered_map<std::string, int> empty_map;
            return empty_map;
    }





    

}







std::unordered_map<Board, int> initialiser_distance(Graph_board graph) 
{
    std::unordered_map<Board, int> distance;
    for (const auto& sommet : graph)
    {
        distance[sommet] = -1;
    }
    distance[graph.begin()] = 0; //dans la classe Graph_board, implémenter la fonction begin
    return distance;
}




Board trouve_sommet_min(std::vector<Board> a_explorer)
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


void maj_distance(Board s1, Board s2)
{
    if (distance[s2] > distance[s1] + 1) //distance du début à s2 est plus grande que celle du début à s2 en passant par s1
                                         // +1 correspond au poids de l'arete ie le nombre d'étapes
    {
        distance[s2] = distance[s1] + 1;
        successeur[s1] = s2;

    }
}




void dijkstra(Graph_board graph) //affiche le plus court chemin pour gagner la partie
{
    std::unordered_map<Board, int> distance = initialiser_distance(graph);
    std::vector<Board> a_explorer = graph.sommet();
    std::vector<Board> successeur;
    successeur[0] = Graph_board.begin();
    while (a_explorer.size() != 0)
    {
        Board s = trouve_sommet_min(a_explorer);
        a_explorer.erase(s);
        for (const auto& voisin : s.adjacent()) //méthode adjacent qui renvoie les sommets adjacents d'un sommet
        {
            maj_distance(s, voisin);
        }
    }
    
    for (const auto& elem: successeur)
    {
        affichage(elem);

    }


}








int main()
{
    return 0;
}