#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstdlib>


bool in(int x,std::vector<int> vect) //vérifie si x est dans vect
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
    explicit Board(const std::vector<int>& vect) : tab(vect) {
        if (this->tab.size() != 9)
            throw std::runtime_error("Taille de board non valide.");
    }
    void reset() //crée un board avec les nombres rangés aléatoirement et le -1 en bas à droite
    {
        std::vector<int> present;
        tab[8]=-1;
        for (int i=0;i<8;i++)
        {
            int x=rand()%8+1;
            while (in(x,present)) {x=rand()%8+1;}
            present.push_back(x);
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
    int position(int e) const // renvoie la position d'un élément du board
    {
        for (int i = 0; i < 9; i++)
        {
            if (tab[i] == e)
            {
                return i;
            }
        };
        return (99);
    }
    int ligne(int e) const// renvoie la ligne du board sur laquelle est l'élément (commence à 0)
    {
        return (position(e)/3);
    }
    int colonne(int e) const // renvoie la colonne du board sur laquelle est l'élément (commence à 0)
    {
        return (position(e)%3);
    }
    std::vector<int> voisins_moins() const { // renvoie la liste des voisins du -1
        std::vector<int> voisins;
        int i = position(-1);
        int l = ligne(position(-1));
        int c = colonne(position(-1));
        if (l==0){
            voisins.push_back(i+3);
            }
        else if (l==1){
            voisins.push_back(i-3);
            voisins.push_back(i+3);
        }
        else if (l==2){
            voisins.push_back(i-3);
        }
        if (c==0){
            voisins.push_back(i+1);
        }
        else if (c==1){
            voisins.push_back(i+1);
            voisins.push_back(i-1);
        }
        else if (c==2){
            voisins.push_back(i-1);
        }
        return voisins;
        }
    std::vector<Board> adjacents () const {
        std::vector<int> vois_moins = voisins_moins();
        int p_moins = position(-1);
        int l = vois_moins.size();
        std::vector<Board> boards_adjacents;
        for (int i = 0; i < l; i++) {
            Board new_board = Board(tab);
            int p = position(vois_moins[i]);
            new_board.swap(p_moins, p);
            boards_adjacents.push_back(new_board);
        }
        return boards_adjacents;

    } 
    bool equal (Board b1) { //fonction testant si deux boards sont égaux
        for (int i = 0; i < 9; i++)
        {
            if (b1.tab[i] != this->tab[i])
            {
                return false;
            }
        }
        return true;
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


void affichage(Board tab)
{
    std::vector<int> vect=tab.tableau();
    for (int i=0;i<3;i++)
    {
        std::cout<<vect[i]<<"  ";
    }
    std::cout<<std::endl;
    for (int i=3;i<6;i++)
    {
        std::cout<<vect[i]<<"  ";
    }
    std::cout<<std::endl;
    for (int i=6;i<9;i++)
    {
        std::cout<<vect[i]<<"  ";
    }
}