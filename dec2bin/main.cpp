#include <iostream>
#include <string>
#include <sstream>      // std::stringstream

using namespace std;

void dwujkowy(int liczba, std::string& bin) 
{
    if(liczba)
    {
	dwujkowy(liczba/2, bin);
	cout<<liczba%2;
	ostringstream ss;
	ss << liczba%2;
	bin.append(ss.str());
    }
}

int main(int argc, char *argv[])
{
    int liczba;
    std::string bin;
    cout<<"Wprowadz liczbe dzisietna: ";
    cin>>liczba;
    dwujkowy(liczba, bin);
    cout<<endl;

    cout<<"Liczba w formacie dwujkowym: "<<bin<<endl;
    return 0;
}
