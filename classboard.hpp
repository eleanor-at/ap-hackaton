#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdlib>

class Board
{
private:
    std::vector<int> tab;

public:
    Board() : tab(9) {};
    void swap(int x, int y) //échange deux éléments du board, prend en arguments les positions de ces éléments
    {
        int t = tab[x];
        tab[x] = tab[y];
        tab[y] = t;
    }
    std::vector<int> tableau () //renvoie le board
    {
        return tab;
    }
    std::vector<int> voisins_moins () {}; //renvoie la liste des voisins du -1
    int find_moins () // renvoie la position du -1
    {
        for (int i = 0; i < 9; i++)
        {
            if (tab[i] == -1)
            {
                return i;
            }
        }
    };
    bool win() //renvoie si on a gagné
    {
        for (int i = 0; i < 8; i++)
        {
            if (tab[i] != (i + 1))
            {
                return false;
            }
        }
        if (tab[-1] != (-1))
        {
            return false;
        }
        return true;
    };
};

