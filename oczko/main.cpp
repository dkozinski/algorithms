ls
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int* oczko(int *tab, int size);
void printVector(const std::vector<int>& v);
int sumElements(const std::vector<int>& v);

int main(int argc, char *argv[])
{
    int liczba = 0;
    int count = 0;
    int SIZE  =100;
    int array[SIZE];

    std::vector< std::vector<int> > v(SIZE);

    memset(array, 0, sizeof(int)*SIZE);

    /* initialize random seed: */
    srand (time(NULL));

    // generate sequence o 100 numbers
    for(int i=0; i<SIZE;i++)
    {
        liczba = rand()%10+1;
        std::cout<<"liczba["<<i<<"] = "<<liczba<<std::endl;
        array[i] = liczba;
    }

    for(int i=0; i<SIZE;i++)
    {
        int j = i;
        int sum = array[j];

        while(sum <= 21 && j<SIZE-1)
        {
            v[i].push_back(array[j]);
            j++;
            sum += array[j];
        }
        printVector(v[i]);
        sum = sumElements(v[i]);
        std::cout<<"\rsum = "<<sum<<std::endl;
        std::multimap<int, std::vector<int> > map;
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
