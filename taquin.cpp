#include "classboard.hpp"

void print(const std::string &msg)
{
    std::cout << msg <<std::endl;
}

void gauche(Board tab)
{
    int x=tab.position(-1);
    if (x%3!=0)
    {
        tab.swap(x,x-1);
    }
    else
    {
        print("déplacement impossible");
    }
}

void droite(Board tab)
{
    int x=tab.position(-1);
    if (x%3!=2)
    {
        tab.swap(x,x+1);
    }
    else
    {
        print("déplacement impossible");
    }
}

void haut(Board tab)
{
    int x=tab.position(-1);
    if (x>2)
    {
        tab.swap(x,x-3);
    }
    else
    {
        print("déplacement impossible");
    }
}

void bas (Board tab)
{
    int x=tab.position(-1);
    if (x<6)
    {
        tab.swap(x,x+3);
    }
    else
    {
        print("déplacement impossible");
    }
}

void play()
{
    char key;
    Board tab;
    tab.reset();
    while (true)
    {
        affichage(tab);
        print("action à effectuer ? (q pour quitter, i-j-k-l pour se déplacer)");

        std::cin >> key;
        if (key=='q')
        {
            print("jeu quitté");
            exit(0);
        }
        if (key=='i')
        {
            haut(tab);
        }
        if (key=='j')
        {
            gauche(tab);
        }
        if (key=='k')
        {
            bas(tab);
        }
        if (key=='l')
        {
            droite(tab);
        }

        if (tab.win())
        {
            print("gagné !");
        }
    }
}



int main()
{
    play();
    return 0;
}