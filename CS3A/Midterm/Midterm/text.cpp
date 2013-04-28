#include "text.h"
#include "stringvar.h"
#include <iostream>
#include <fstream>

using namespace std;

Text::Text()//default constructor
{
    cout << "Text Constructor";
        cin.get();
    words =  new StringVar[50];
    frequency = new int[50];
    for(int i = 0; i<50; i++)
    {
        frequency[i] = 0;
    }
    uniqueCount = 0;
    max = 50;

}

Text::Text(int num)//one argument constructor
{
    cout << "text max constructor\n";
        cin.get();
    max = num;
    words = new StringVar[max];
    frequency = new int[max];
    for(int i = 0; i<max; i++)
    {
        frequency[i] = 0;
    }
    uniqueCount = 0;

}

Text::Text(const Text &copyThis)//copy constructor
{
    cout << "text copy constructor";
        cin.get();
    words = new StringVar[copyThis.uniqueCount];
    frequency = new int[copyThis.uniqueCount];
    for(int i=0; i<copyThis.uniqueCount; i++)
    {
        words[i] = copyThis.words[i];
        frequency[i] = copyThis.frequency[i];
        uniqueCount = copyThis.uniqueCount;
    }

}

Text::~Text()//destructor
{
    cout << " text bye";
        cin.get();
    delete [] words;
    delete [] frequency;

}

/*---------------------------------------------------------------------------------------
 *Name - <<
 *Arguments - ostream out StringVar A
 *Return values - ostream out
 *Description - outputs a text file
 *Notes -2/18/13 - pretty simple
----------------------------------------------------------------------------------------*/
ostream& operator <<(ostream &out, const Text &A)//outputs
{
    cout << "output text\n";
        cin.get();
    for(int i=0; i<A.uniqueCount; i++)
    {
        out << A.words[i] << " --- " << A.frequency[i] << endl;
    }

    out << "UNIQUE COUNT = " <<A.uniqueCount;

    return out;
}

//Text operator +=(const Text &T, const StringVar &A)
//{
//    if(T.Search(A) == -1)//unique word found
//    {
//        T.words[T.uniqueCount] = A;
//        T.frequency[T.uniqueCount]++;
//        T.uniqueCount++;
//    }
//    else if(T.Search(A) != -1)
//    {
//        T.frequency[T.Search(A)]++;//increase the frequency of where it was found.
//    }
//    return T;
//}


/*---------------------------------------------------------------------------------------
 *Name - Append
 *Arguments - StringVar A
 *Return values - void fnction
 *Description - appends a word to the Text words array
 *Notes -2/18/13 - currently adds as it goes, not sorting
----------------------------------------------------------------------------------------*/
void Text::Append(StringVar A)
{
    cout << "Append\n";
        cin.get();

    if(uniqueCount==max)
    {
//        cout<<"FUSE LIT\n";
        cout << "Getting more space\n";
        Reallocate();
        cout << "Done\n";

//        cout <<"EXPLOSION\n";
    }

    if(uniqueCount==0)
    {
       // cout << "FIRST WORD\n";
//        words[0] = A;
        frequency[0]++;
        uniqueCount++;
        //cout << "FIRST WORD ADDED, UNIQUE COUNT = " << uniqueCount << endl;

    }
    else
    {
        //cout << "Before Search";
        int index = Search(A);
        //cout << "SEARCHED\n";
        if(words[index] == A)
        {
            frequency[index]++;
            //cout << "Test";
        }
        else
        {
            ShiftDown(index);
            words[index] = A;
            frequency[index]=1;
            uniqueCount++;
        }
    }
    A.explode();

//    else if(Search(A) == -1)//unique word found
//    {

//        words[uniqueCount] = A;
//        frequency[uniqueCount]++;
//        uniqueCount++;
//        //cout << "UNIQUE WORD ADDED - New Unique Count = " << uniqueCount << endl;
//    }
//    else if (Search(A) != -1)
//    {
//        frequency[Search(A)]++;//increase the frequency of where it was found.
//        //cout << "REPEAT WORD ADDED\n";
//    }

    //    else
    //    {
    //        index = Search(A);
    //        if (sArray[index]==A)
    //            increment freq at index
    //        else
    //                    shiftDown(index) //shifts down sArray AND freq array starting at pos index
    //                    sArray[index]= a
    //                    freq[index]=1

    //    }

}

/*---------------------------------------------------------------------------------------
 *Name - Search
 *Arguments - StringVar A
 *Return values - returns position if found, otherwise returns -1
 *Description - returns index if found
 *Notes -2/18/13 - not too hard, i want to make a function for tolower
----------------------------------------------------------------------------------------*/

int Text::Search(StringVar A)
{
    cout << "Search\n";
        cin.get();

    if(uniqueCount==0)
    {
        return -1;
    }
        int i=0;
        try
        {
            while(i<uniqueCount&&(!(A<=words[i])))
            {
                i++;
    //            cout << "I " << i << endl;
    //            cout << uniqueCount << endl;
            }
        }
        catch(...) {
            cout << "Other exception." << endl;
        }
        A.explode();
        return i;
/*
        //    for(int i=0; i<uniqueCount; i++)
        //    {

        //        if(A == words[i])//if words==word
        //        {
        //            return i;//return location it is found.
        //        }
        //    }

        //    int i=0;
        //    while(!(A<=words[i]) && i<uniqueCount)
        //    {
        //        i++;
        //       cout << "I " << i << endl;
        //        cout << uniqueCount << endl;
        //    }
        //    return i;
        */

}

/*---------------------------------------------------------------------------------------
 *Name - Reallocate
 *Arguments - none
 *Return values - void fnction
 *Description - expands the size of stringvar array if count>max
 *Notes -2/18/13 - like vector double
----------------------------------------------------------------------------------------*/
void Text::Reallocate()
{
    cout << "Reallocate\n";
        cin.get();
    StringVar* bigger;
    int* intBigger;
    bigger = new StringVar[max*2];
    intBigger = new int [max*2];

    //cout << "middle\n";
    for(int i = 0; i<uniqueCount; i++)
    {

        bigger[i] = words[i];
        intBigger[i]  = frequency[i];
    }
    //out << "rewriting\n";
    delete []  words;
    delete []  frequency;
    //cout << "later\n";

    words = bigger;
    frequency  = intBigger;

//    delete [] bigger;
//    delete [] intBigger;


   //cout << "max " << max << "***********************\nOSION\n*************************** max*2 " << max*2;
    max = max*2;



    //cout << "end\n";
}

/*---------------------------------------------------------------------------------------
 *Name - ShiftDown
 *Arguments - int index
 *Return values - void function
 *Description - shifts down from an index from the end
 *Notes -2/18/13 - couldn't think of how to do it from the front so i went from the back
----------------------------------------------------------------------------------------*/
void Text::ShiftDown(int index)
{
    cout << "Shift Down\n";
        cin.get();
    for(int i = uniqueCount; i>=index; i--)
    {
        words[i+1] = words[i];
        frequency[i+1] = frequency[i];
    }
}




/*---------------------------------------------------------------------------------------
 *Name - ReadFile
 *Arguments - fileName
 *Return values - void function
 *Description - reads file and tokenizes
 *Notes -2/18/13 - copied from main
----------------------------------------------------------------------------------------*/
void Text::ReadFile(char* fileName)
{
    long secondsBegin;
    long secondsEnd;
    secondsBegin = static_cast<long>(time(NULL));

    cout << "start\n";
    cout << "Hi\n";

    int num = 0;



    ifstream file;
    file.open(fileName);

    ofstream bob;
    bob.open("parsed.txt");

    StringVar word;

    char* block = new char [10000];
    int start = 0;
    while(!file.eof())
    {
        file.getline(block, 10000, '\n');
        //cout << block << endl;
        while(block[start] != '\0')
        {


            word = word.GetWord(block, start);
            Append(word);
            word.explode();
        }
        block;
        start = 0;
    }
    secondsEnd = static_cast<long>(time(NULL));

    cout << "End\n It took " << secondsEnd-secondsBegin << " seconds to wordify the file\n";
    file.close();
    bob << *this;
    bob.close();
}

