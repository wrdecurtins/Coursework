#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

//Global variables
using namespace std;

const int infinity = 700; //virtual infinity value
const int MAXSTATION = 24;
const int MAXTRAINS = 30;
const int INVALIDSTATION = -1;

//train structure
struct TRAINS
{
    int Dstation;
    int Astation;
    int Dtime;
    int Atime;
    int travel;
};

//global train
TRAINS train[MAXSTATION][MAXSTATION];
int shortestPath[MAXSTATION][MAXSTATION];
int midpoint[MAXSTATION][MAXSTATION];
int walk[MAXTRAINS];
int counted = 0;
int walkVal = 1;
string stations[MAXSTATION];

//final prototypes
void loadTrains();
void loadStations();
void displayStations();
void shortest();
void displayPath(int begin, int end);

//utility prototypes
void clearWalk();
void path(int begin, int end);
int stationLookup(string stationName);

//test prototypes
void printShortest();
void printTrain();
void printWalk();
void printMidpoint();

int main()
{
    int input;
    string ch, start, destination;

    loadStations();
    //loadStations_test();

    loadTrains();
    //loadTrains_test();

    shortest();

    //printTrain();
    //printMidpoint();
    //printShortest();

    while ( input != 4 )
    {
        cout << "======================================" << endl;
        cout << "1. List Stations and #'s" << endl;
        cout << "2. Find Shortest Travel Time on Trains" << endl;
        cout << "3. Find Shortest Time Overall" << endl;
        cout << "4. EXIT" << endl;

        cin >> input;
        //cout << endl;

        if (input == 1)
        {
            cout << endl;
            displayStations();

            cout << "Enter anything to continue ";
            cin >>ch;
            cout << endl;
        }
        else if (input == 2)
        {
            int startInt;
            cout << "Enter a starting station: ";
            cin>>start;

            startInt = stationLookup(start);
            if (startInt == INVALIDSTATION)
            {
                stringstream try1(start);

                try {
                    try1 >> startInt;
                    if (startInt > counted || startInt < 0)
                    {
                        cout << "Invalid Station Name, please refer to the station list or check your spelling" << endl;
                        continue;
                    }
                }catch( int i) {
                cout << "Invalid Station Name, please refer to the station list or check your spelling" << endl;
                continue;}
            }

            int endInt;
            cout << "Enter a destination station: ";
            cin>>destination;
            cout <<endl;

            endInt = stationLookup(destination);
            if (endInt == INVALIDSTATION)
            {
                stringstream try2(destination);

                try {
                    try2 >> endInt;
                    if (endInt > counted || endInt < 0)
                    {
                        cout << "Invalid Station Name, please refer to the station list or check your spelling" << endl;
                        continue;
                    }
                }catch( int i) {
                    cout << "Invalid Station Name, please refer to the station list or check your spelling" << endl;
                    continue;}
            }

            walkVal = 1;
            displayPath(startInt, endInt);

            //printWalk();
        }
        else if (input == 3)
        {
            cout << "Sorry this feature is in development" << endl << endl;
            cout << "Enter anything to continue ";
            cin >>ch;
            cout << endl;
        }
        else if (input == 4)
        {
            continue;
        }
        else
        {
            cout << "Invalid input" << endl << endl;
            cout << "Enter anything to continue ";
            cin >>ch;
            cout << endl;
        }


    }
    return 0;
}

int stationLookup(string stationName)
{
    transform(stationName.begin(), stationName.end(), stationName.begin(), ::toupper);

    for ( int k = 0; k < counted; k++ )
    {
        string tmp = stations[k];
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        if ( tmp == stationName)
        {
            return k;
        }
    }
    return INVALIDSTATION;
}

void displayPath(int begin, int end)
{
    if( begin == end )
    {
        cout << "YOU ARE ALREADY HERE !!!!" << endl <<endl;
        return;
    }

    if ( shortestPath[begin][end] == infinity )
    {
        cout << "There is no train going from " << stations[begin] << " to " << stations[end] << endl << endl;
        return;
    }


    int minutes, hours;

    minutes = shortestPath[begin][end] % 60;
    hours = (shortestPath[begin][end] - minutes)/60;

    clearWalk();

    walk[0] = begin;

    path(begin, end);

    int k = 0;

    while(walk[k] != INVALIDSTATION)
    {
        k++;
    }
    walk[k] = end;
    k = 0;

    cout << "To go from " << stations[begin] << " to " << stations[end] << " you will need to ride on trains for " << hours << " hours and " << minutes << " minutes" << endl << endl;

    cout << "You will take the following trains:" << endl << endl;

    while( walk[k+1] != INVALIDSTATION)
    {
        string startTime, endTime;

        ostringstream strhours, strminutes;
        ostringstream strhours2, strminutes2;
        minutes = train[walk[k]][walk[k+1]].Dtime % 60;
        hours = train[walk[k]][walk[k+1]].Dtime - minutes;
        hours = hours / 60;

        if (hours >= 12 )
        {
            hours = hours % 12;
            strhours << hours;
            string hoursString = strhours.str();
            strminutes << minutes;
            string minutesString = strminutes.str();
            if (minutes < 10)
            {
                if (hours < 10)
                    startTime = "0" + hoursString + ":0" + minutesString + " PM ";
                else
                    startTime = hoursString + ":0" + minutesString + " PM ";
            }
            else
            {
                if (hours < 10)
                    startTime = "0" + hoursString + ":" + minutesString + " PM ";
                else
                    startTime = hoursString + ":" + minutesString + " PM ";
            }
        }
        else
        {
            strhours << hours;
            string hoursString = strhours.str();
            strminutes << minutes;
            string minutesString = strminutes.str();
            if (minutes < 10)
            {
                if (hours < 10)
                    startTime = "0" + hoursString + ":0" + minutesString + " AM ";
                else
                    startTime = hoursString + ":0" + minutesString + " AM ";
            }
            else
            {
                if (hours < 10)
                    startTime = "0" + hoursString + ":" + minutesString + " AM ";
                else
                    startTime = hoursString + ":" + minutesString + " AM ";
            }
        }

        minutes = train[walk[k]][walk[k+1]].Atime % 60;
        hours = train[walk[k]][walk[k+1]].Atime - minutes;
        hours = hours / 60;

        if (hours >= 12)
        {
            hours = hours % 12;
            strhours2 << hours;
            string hoursString = strhours2.str();
            strminutes2 << minutes;
            string minutesString = strminutes2.str();
            if (minutes < 10)
            {
                if (hours < 10)
                    endTime = "0" + hoursString + ":0" + minutesString + " PM ";
                else
                    endTime = hoursString + ":0" + minutesString + " PM ";
            }
            else
            {
                if (hours < 10)
                    endTime = "0" + hoursString + ":" + minutesString + " PM ";
                else
                    endTime = hoursString + ":" + minutesString + " PM ";
            }
        }
        else
        {
            strhours2 << hours;
            string hoursString = strhours2.str();
            strminutes2 << minutes;
            string minutesString = strminutes2.str();
            if (minutes < 10)
            {
                if (hours < 10)
                    endTime = "0" + hoursString + ":0" + minutesString + " AM ";
                else
                    endTime = hoursString + ":0" + minutesString + " AM ";
            }
            else
            {
                if (hours < 10)
                    endTime = "0" + hoursString + ":" + minutesString + " AM ";
                else
                    endTime = hoursString + ":" + minutesString + " AM ";
            }
        }

        cout << "Leave " << stations[walk[k]] << " at " << startTime <<  " and arrive at " << stations[walk[k+1]] << " at " << endTime << endl;
        k++;
    }
    cout << endl;
}

void path( int begin, int end) //for initial call always set this value to 1
{
    int m;

    m = midpoint[begin][end];

    if (m == INVALIDSTATION )
        return;


    path(begin,m);


    walk[walkVal] = m;

    walkVal++;

    path(m,end);
}

void clearWalk()// use before path
{
    for (int k = 0; k < MAXTRAINS; k++ )
        walk[k] = INVALIDSTATION;
}

void shortest()
{
    for( int i = 0; i < counted; i++ )
    {
        for ( int j = 0; j < counted; j++ )
        {
            shortestPath[i][j] = train[i][j].travel;
            midpoint[i][j] = INVALIDSTATION;
        }
    }

    for ( int i = 0; i < counted; i++ )
        shortestPath[i][i] = 0;

    //printTrain();
    //cout << endl << endl;
    //Shortest();

    for ( int k = 0; k < counted; k++ )
        for (int i = 0; i < counted; i++ )
            for (int j = 0; j < counted; j++ )
            {
                if ( shortestPath[i][k] + shortestPath[k][j] < shortestPath[i][j] )
                {
                    shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];
                    midpoint[i][j] = k;
                }
            }
}

void displayStations()
{
    for ( int i = 0; i < counted; i++ )
    {
        cout << i << " " << stations[i] << endl;
    }
    cout << endl;
}

void loadTrains()
{

    int x, y;
    ifstream infile;

    //default traveltimes to infinity
    for (int i = 0; i < MAXSTATION; i++)
    {
        for (int j = 0; j < MAXSTATION; j++)
        {
            train[i][j].travel = infinity;
        }

        train[i][i].travel = 0;
    }

    infile.open("trains.dat");
    if (infile.fail())
    {
        cout<< "trains.dat does not exist" << endl;
        infile.clear();
        return;
    }

    infile>>x;
    infile>>y;

    while(!infile.eof())
    {
        train[x][y].Dstation = x;
        train[x][y].Dstation = y;
        infile>>train[x][y].Dtime;
        infile>>train[x][y].Atime;

        train[x][y].travel = train[x][y].Atime - train[x][y].Dtime;

        infile>>x;
        infile>>y;
    }

    infile.close();
}

void loadStations()
{
    counted = 0;
    ifstream infile; // create file variable FV
    infile.open("stations.dat");// set fv to physical file and open it

    for (int k = 0; k < MAXSTATION; k++)
    {
        stations[k] = "-700";
    }

    if(infile.fail())
    {
        cout << "stations.dat does not exist" << endl;
        infile.clear();
        return;
    }

    int num;
    string name;

    infile>>num;
    infile>>name;

    if (stations[num] == "-700")
    {
        stations[num] = name;
        counted++;
    }
    infile>>num;
    infile>>name;

    while(!infile.eof())
    {
        stations[num] = name;
        counted++;

        infile>>num;
        infile>>name;
    }

    infile.close(); //close the file
}

void printShortest()
{
    for (int k = 0; k < counted; k++)
    {
        cout << k << ": ";
        for (int i = 0; i < counted; i++)
            cout << shortestPath[k][i] << " ";
        cout << endl;
    }
}
void printTrain()
{
    for (int k = 0; k < counted; k++)
    {
        cout << k << ": ";
        for (int i = 0; i < counted; i++)
            cout << train[k][i].travel << " ";
        cout << endl;
    }
}

void printWalk()
{
    cout << "walk : ";
    int i = 0;
    while ( walk[i] != INVALIDSTATION )
    {
        cout << walk[i] << " ";
        i++;
    }
    cout << endl;
}

void printMidpoint()
{
    for (int k = 0; k < counted; k++)
    {
        cout << k << ": ";
        for (int i = 0; i < counted; i++)
            cout << midpoint[k][i] << " ";
        cout << endl;
    }
}