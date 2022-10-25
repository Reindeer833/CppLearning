#include <iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <set>
#include <string.h>
#include <stdio.h>

using namespace std;

void readTheFile(const char* filePath);
void procesCurrentLine(const char* aLine,set<string,less<string> >* aSet,int* aTotal);

/*
  This program reads a file and gathers all different words.
  Word is defined as a group of alphabetic chars with boundaries
  consisting of start or end of line or non-alphabetic chars.
*/

int main()
{
    cout << "Hello world!" << endl;
    string filePath="/home/Petr/Development/cpp/CppLearning/CodeBlocks/inputs/testing.txt";
    readTheFile(filePath.c_str());
    return 0;
}

void readTheFile(const char* filePath)
{
    ifstream fIn;
    fIn.open(filePath);
    string aLine("");
    set<std::string,less<string>> aSet;
    int aTotal=0;

    while(getline(fIn,aLine))
    {
        procesCurrentLine(aLine.c_str(),&aSet,&aTotal);
    }
    cout<<endl;
    for(set<string>::iterator ir = aSet.begin();ir != aSet.end();++ir)
    {
        cout<<*ir<<endl;
    }
    cout<<endl;
    cout<<"Total words found: "<< aTotal<<endl;
    cout<<endl;
    cout<<"Total different words found: "<< aSet.size()<<endl;
    cout<<endl;
}

void procesCurrentLine(const char* aLine,set<string,less<string>>* aSet,int* aTotal)
{
    char aWord[256];
    int lineIx=0;
    int charIx = 0;

    for(lineIx = 0;lineIx < (int)strlen(aLine);++lineIx)
    {
        if(isalpha(aLine[lineIx]))
        {

            aWord[charIx] = charIx == 0 ? toupper(aLine[lineIx]) : tolower(aLine[lineIx]); //capitalize first letter
            charIx++;
        }

        else
        {
            if(charIx > 0) //word was discovered
            {
                aWord[charIx] = '\0';
                charIx = 0;
                aSet->insert(aWord);
                 *aTotal += 1;
            }

        }

    }

    if(charIx > 0) //word was discovered but not stored
    {
        aWord[charIx] = '\0';
        charIx = 0;
        aSet->insert(aWord);
         *aTotal += 1;
    }

}
