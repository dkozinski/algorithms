#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
//definicja wezla
struct wezel
{
   int wartosc;           //wartosc przechowywana w wezle
   struct wezel *rodzic;  //wskaznik na rodzica
   struct wezel *l_syn;   //wskaznik na lewe dziecko
   struct wezel *p_syn;   //wskaznik na prawe dziecko
};
struct wezel *root;  //wskaźnik na root'a

//dodaje wezel o podanej wartosci n, do drzewa o korzeniu start
int dodawanie(int n, struct wezel *start)
{
    //jezeli drzewo jest puste to dodaj korzen
    if (root == NULL)
    {
        root = (wezel*)malloc(sizeof *root);
        root->wartosc = n;
        root->l_syn = NULL;
        root->p_syn = NULL;
        root->rodzic = NULL;
    }
    //jezeli zadana wartosc jest mniejsza od korzenia idz do lewego poddrzewa
    else if(n !=1 )
    {
        //jezeli lewe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
        if(start->l_syn != NULL)
        {
            dodawanie(n,start->l_syn);
        }
        //jezeli lewe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
        else
        {
            wezel *nowy = (wezel*)malloc(sizeof *root);
            nowy->wartosc = n;
            nowy->l_syn = NULL;
            nowy->p_syn = NULL;
            nowy->rodzic = start;
            start->l_syn=nowy;
        }
    }
    //jezeli zadana wartosc jest wieksza lub rowna korzeniowi idz do prawego
    //poddrzewa
    else
    {
    //jezeli prawe poddrzewo istnieje wywolaj dla niego ta funkcje rekurencyjnie
    if(start->p_syn!=NULL)
    {
    dodawanie(n,start->p_syn);
    }
    //jezeli prawe poddrzewo nie istnieje dodaj nowy wezel o zadanej wartosci
    else
    {
    wezel *nowy = (wezel*)malloc(sizeof *root);
    nowy->wartosc = n;
    nowy->l_syn = NULL;
    nowy->p_syn = NULL;
    nowy->rodzic = start;
    start->p_syn=nowy;
    }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int liczba = 0;
    int count = 0;
    int SIZE  =10;
    int array[SIZE];

    std::vector< std::vector<int> > v(SIZE);

    memset(array, 0, sizeof(int)*SIZE);

    /* initialize random seed: */
    srand (time(NULL));

    // generate sequence o 10 numbers
    for(int i=0; i<SIZE;i++)
    {
        liczba = rand()%10+1;
        std::cout<<"liczba["<<i<<"] = "<<liczba<<std::endl;
        array[i] = liczba;
    }

    //std::cout<<"size: "<< (sizeof(tab)/sizeof(*tab))<<std::endl;
    //oczko(tab, (sizeof(tab)/sizeof(*tab)));
    return 0;
}

void printVector(const std::vector<int>& v)
{
    std::vector<int>::const_iterator it = v.begin();
    std::cout<<"[ ";
    int s = 0;
    for (it=v.begin();it<v.end();it++)
    {
        std::cout<<" "<<*it;
    }
    std::cout<<" ]"<<std::endl;
}

int sumElements(const std::vector<int>& v)
{
    int sum = 0;
    std::vector<int>::const_iterator it = v.begin();
    for (it=v.begin();it<v.end();it++)
    {
        sum+=(*it);
    }
    return sum;
}

int* oczko(int *tab, int size)
{
    //int size = sizeof(tab)/sizeof(*tab);
    std::cout<<"size: "<<size<<std::endl;
    for(int i=0;i<size;i++)
    {
        int oczko = 0;
        int a = 0;

        while(oczko<21)
        {
            oczko = tab[i]+oczko;
            std::cout<<"oczko:"<<oczko<<std::endl;
            a++;
        }
        std::cout<<"sdsds"<<std::endl;
    }
    return NULL;
}
