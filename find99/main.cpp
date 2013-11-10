#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    int liczba = 0;
    int count = 0;

    /* initialize random seed: */
    srand (time(NULL));

    for(int i=0; i<100;i++)
    {
        liczba = rand()%100;
        std::cout<<"liczba["<<i<<"] = "<<liczba<<std::endl;
        if(99==liczba)
        {
            std::cout<<"------- liczba["<<i<<"] = "<<liczba<<std::endl;
            count++;
        }
    }
    std::cout<<"Liczba 99 wystapila "<<count<<" razy."<<std::endl;
    return 0;
}
