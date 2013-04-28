/*-----------------------------------------------------------------------------------------
Project: 9-5 Lab and Stations
Author: Jonathan Chan
Description: environment for a lab and stations that users can login and logout
Notes: 2/3 started initialized, and created the int*
       2/5 Was similar to 9-3.. weird bug. Not sure where it is....(maybe print/initialize)
-----------------------------------------------------------------------------------------*/
#include <iostream>;

using namespace std;

int* GetStation(int** lab, int rows, int cols);//returns the station number according to rows and cols
int* Login(int* station, int id);//logs in a 5-digit id number
int* Logoff(int* station);//logs out of a station
int* Search(int**lab, int id, int &labNum, int &stationNum);//searches through the array returns the station. keeps
                                                            //call by reference to keep labNum and stationNum
int** Initialize(int** lab);//initializes all stations to 0(no user)
void Print(int** lab);//prints the array


int main()
{

    int** lab = new int*[4+1];//create space for size pointer and all the labs
    int** labWalker = lab;//walk down lab rows
    int* stationWalker;//walk down stations
    *labWalker = new int[5];//set for sizeRef pointer
    int numLabs = 0;

    int* sizeRef = *labWalker;

    *sizeRef++ = 4;
    *sizeRef++ = 5;//try changing this
    *sizeRef++ = 6;
    *sizeRef++ = 4;
    *sizeRef =3;//setting sizes for the labs;

    sizeRef = *labWalker;
    numLabs = *sizeRef;

    labWalker++;
    sizeRef++;//set it to the length of the first int pointer

    for(int i = 0; i<numLabs;i++)
    {
        *labWalker=new int[*sizeRef];
        sizeRef++;
        labWalker++;
    }
    labWalker = lab;


    lab = Initialize(lab);

    labWalker++;
    stationWalker = *labWalker;



    stationWalker = GetStation(lab,2,5);
    Login(stationWalker, 12345);
    stationWalker = GetStation(lab,1,5);
    Login(stationWalker, 12346);
    stationWalker = GetStation(lab,3,2);
    Login(stationWalker, 12347);
    stationWalker = GetStation(lab,4,1);
    Login(stationWalker, 12348);

    //cout << "LOGIN 1234, 3, 5\n";

    Print(lab);

    cout << "\n\n\n";

//    int labNum=1, stationNum=1;
//    stationWalker = Search(lab, 12345, labNum, stationNum);

//    if(stationWalker != NULL)//found
//    {
//        cout << "USER FOUND IN LAB: " << labNum << " STATION: " << stationNum << endl;
//    }
//    else if(stationWalker==NULL)
//    {
//        cout << "USER NOT FOUND\n";
//    }
    labWalker = lab;
    sizeRef = *labWalker;
    int size = *sizeRef;


    cout << **lab << endl;
    for(int i=0; i<size; i++)
    {
        delete[] *labWalker++;
    }

    delete[] lab;

    cout << **lab;
    return 0;
}

/*---------------------------------------------------------------------------------------
 *Name - GetStation
 *Arguments - int pointer, rows, cols
 *Return values - returns an int pointer to the station
 *Description - increments the rows and cols until at the station, then return station
 *Notes -2/5/13 - Not too hard, not sure what bugs may arise seems to work fine.
-----------------------------------------------------------------------------------------*/
int* GetStation(int** lab, int rows, int cols)
{
    int**labWalker = lab;
    int* stationWalker;
    int* sizeRef = *labWalker;

    labWalker++;//move away from size pointer
    sizeRef++;
    if(rows>*sizeRef)
    {
        rows=*sizeRef;//bounds check rows
    }
    int numRows=rows-1;//off by 1 fix

    for(int i =0; i<numRows; i++)
    {
        labWalker++;//move down number of rows
        sizeRef++;//move corresponding size
    }

    stationWalker = *labWalker;//set station walker to the start of the proper row

    if(cols>*sizeRef)
    {
        cols=*sizeRef;//bounds check cols
    }
    int numCols=cols-1;//off by 1 fix
    for(int j=0; j<numCols;j++)
    {
        stationWalker++;
    }


    return(stationWalker);//returns the position wanted
}

/*---------------------------------------------------------------------------------------
 *Name - Login
 *Arguments - int pointer, id
 *Return values - returns an int pointer to the station
 *Description - uses GetStation to find the station wanted, then sets the id with some error checks
 *Notes -2/5/13 - Working fine.
-----------------------------------------------------------------------------------------*/
int* Login(int* station, int id)
{
    if(id<99999 && id>9999)//id#check....how to check for something ex 01234
    {
        if(*station == 0)
        {
            *station = id;
        }
        else if(*station !=0)
        {
            cout << "Station Occupied\n";
        }
    }
    else if(id>99999 || id < 10000)
    {
        cout <<"ERROR IN ID #\n";
    }
    return station;
}

/*---------------------------------------------------------------------------------------
 *Name - LogOff
 *Arguments - int pointer
 *Return values - returns an int pointer to the station
 *Description - uses search or GetStation to get pointer location then sets it to 0(or no user)
 *Notes -2/5/13 - fairly easy
-----------------------------------------------------------------------------------------*/
int* Logoff(int* station)
{
    *station = 0;
    return station;
}

/*---------------------------------------------------------------------------------------
 *Name - Search
 *Arguments - int pointer, ints id, labNum, stationNum
 *Return values - returns an int pointer to the station
 *Description - looks for the id number in all labs
                calls labNum and stationNum by reference to keep it updated outside.
 *Notes -2/5/13 - Works fine.
-----------------------------------------------------------------------------------------*/
int* Search(int**lab, int id, int &labNum, int &stationNum)
{
    int** labWalker = lab;
    int* sizeRef = *labWalker;//hold the size pointer
    labWalker++;
    int* stationWalker =  *labWalker;
    int numLabs = *sizeRef;

    labNum=1;
    stationNum=1;

    sizeRef++;

    for(int i=0; i<numLabs; i++)
    {

        for(int j=0; j<*sizeRef; j++)
        {
            if(*stationWalker==id)//if found, then return the position
            {
                return stationWalker;
            }
            stationWalker++;//walk down the station
            stationNum++;//increment the station number
        }
        labNum++;
        stationNum = 1;//reset station position
        labWalker++;//next lab
        stationWalker = *labWalker;//reset station walker position

    }


    //if not found lab/station number =-1 and return null pointer
    labNum=-1;
    stationNum=-1;
    return(NULL);



}

/*---------------------------------------------------------------------------------------
 *Name - Initialize.
 *Arguments - int pointer pointer.
 *Return values - returns the initialized pointer pointer
 *Description - fills the int** with 0s or no user.
 *Notes -2/5/13 - Not too hard
-----------------------------------------------------------------------------------------*/
int** Initialize(int** lab)
{
    int** labWalker = lab;
    int* sizeRef = *labWalker;
    labWalker++;//move away from the size pointer
    int* stationWalker = *labWalker;//set station walker equal to the first row of stations/ the first lab;
    int labNum = *sizeRef;//set the initial unchanging size/the num of labs
    *sizeRef++;//move to length of the other int pointers

    for(int i=0; i<labNum; i++)
    {
        for(int j=0; j<*sizeRef;j++)
        {
            *stationWalker++=0;
        }
        sizeRef++;
        labWalker++;
        stationWalker = *labWalker;
    }
    return lab;

}

/*---------------------------------------------------------------------------------------
 *Name - Print
 *Arguments - int pointer pointer
 *Return values - returns nothing, output array.
 *Description - prints the lab to see it
 *Notes -2/5/13 - Not too hard
-----------------------------------------------------------------------------------------*/
void Print(int** lab)
{
    int** labWalker = lab;
    int* sizeRef = *labWalker;//hold the size pointer
    labWalker++;
    int* stationWalker =  *labWalker;


    int labNum = *sizeRef;//set the size of the first things

    for(int i=0; i<labNum; i++)
    {
        sizeRef++;
        cout<<"Lab#" << i+1 << "   ";
        for(int j = 0; j<*sizeRef; j++)
        {
            if(*stationWalker!=0)
            {
                cout <<j+1<< ":|" << *stationWalker << "| ";
            }
            else if(*stationWalker==0)
            {
                cout <<j+1 << ":|Empty| ";
            }
            stationWalker++;
        }
        cout << endl;
        labWalker++;
        stationWalker = *labWalker;

    }
}
