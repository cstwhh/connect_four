#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("raceAns.txt");
    double sum=0;
    string str;
    double score;
    int m=100;
    while(fin>>str)
    {
        if (str==":")
        {
            fin>>score;
            sum=sum+score;
        }    
    }
    fin.close();
    cout<<sum*0.8+60<<endl;
    system ("pause");
    return 0;
}        
 
