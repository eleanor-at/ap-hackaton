#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdlib>

bool in(int x,std::vector<int> vect)
{
    for (auto e:vect)
    {
        if (e==x){return true;}
    }
    return false;
}

class Board
{
private:
    std::vector<int> tab;

public:
    Board() : tab(9) {};
    void reset() //crée un board avec les nombres rangés aléatoirement et le -1 en bas à droite
    {
        std::vector<int> rempli;
        tab[8]=-1;
        for (int i=0;i<8;i++)
        {
            int x=rand()%9;
            while (in(x,rempli)) {x=rand()%9;}
            rempli.push_back(x);
            tab[i]=x;
        }
    }
    void swap(int x, int y) // échange deux éléments du board, prend en arguments les positions de ces éléments
    {
        int t = tab[x];
        tab[x] = tab[y];
        tab[y] = t;
    }
    std::vector<int> tableau() // renvoie le board
    {
        return tab;
    }
    int position(int e) // renvoie la position d'un élément du board
    {
        for (int i = 0; i < 9; i++)
        {
            if (tab[i] == e)
            {
                return i;
            }
        }
    }
    std::vector<int> voisins_moins(); // renvoie la liste des voisins du -1
    bool win() // renvoie si on a gagné
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
    }
};
