#pragma once
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
    void reset();
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
    int ligne(int e) // renvoie la ligne du board sur laquelle est l'élément (commence à 0)
    {
        return (position(e)/3);
    }
    int colonne(int e) // renvoie la colonne du board sur laquelle est l'élément (commence à 0)
    {
        return (position(e)%3);
    }
    std::vector<int> voisins_moins() { // renvoie la liste des voisins du -1
        std::vector<int> voisins;
        int i = position(-1);
        int l = ligne(position(-1));
        int c = colonne(position(-1));
        if (l==0){
            voisins.push_back(i+3);
            };
        }
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
