#include <iostream>
#include "SongManagementStruct.h"

using std::cout;
using std::cin;

void charMoveUpByOne(int &j, const char *temporaryName, const char **targetName[], SongManagement table[])
{
    /*

    *Moves up all the array elements of struct SongManagement by one position, until the previously-assigned
     temporary song/band name is equal to the struct's SongManagement const char* array counterpart

     temporaryName: song or band name
     **targetName:   an array of pointers that should point to a const char* 
                     member array of type SongManagement
     &j: loop variable
    */

    while (j > -1 && std::strcmp(temporaryName, *targetName[j]) != 0)
    {
        table[j + 1].track = table[j].track;
        table[j + 1].band = table[j].band;
        table[j + 1].popularity = table[j].popularity;
        --j;
    }
}

void intMoveUpByOne(int &j, int temporarySongPopularity, int *targetName[], SongManagement table[])
{
    /*

     *Moves up all the array elements of struct SongManagement by one position, until the struct's 
     SongManagement int array becomes equal to its temporary counterpart.

     temporarySongPopularity: number that shows the level of popularity
     *targetName:             an array of pointers that should point to an int 
                              member array of type SongManagement
     &j: loop variable

    */
     while (j > -1 && table[j].popularity < temporarySongPopularity) 
     {
        table[j + 1].track = table[j].track;
        table[j + 1].band = table[j].band;
        table[j + 1].popularity = table[j].popularity;
        --j;
     }
}

void sortSongs(const int NUMBER_OF_SONGS, SongManagement table[], int action)
{
    /*

    *Sorts songs according to their group (action == 1),
    name (action == 2) or popularity (action == 3)

    */
    
    // declaring arrays of pointers, which will respectively point to 
    // each element of type SongManagement arrays counterparts 
    // (track, band, popularity)
    const char **targetBandName[14];
    const char **targetSongName[14];
    int *targetPopularity[14];

    // assigning addresses to the pointer arrays
    for (int k = 0; (k < NUMBER_OF_SONGS); ++k)
    {
        targetBandName[k] = &(table[k].band);
        targetSongName[k] = &(table[k].track);
        targetPopularity[k] = &(table[k].popularity);
    }


    for (int i = 1; i < NUMBER_OF_SONGS; ++i)
    {
        const char *temporarySongName = table[i].track;
        const char *temporaryBandName = table[i].band;
        int temporarySongPopularity = table[i].popularity;
        int j = i-1;

        //determining if it's a name or group sort
        switch (action)
        {
            case 1:  // Group Sort
            {
                charMoveUpByOne(j, temporaryBandName, targetBandName, table);
                break;
            }
            case 2: // Name Sort
            {
                charMoveUpByOne(j, temporaryBandName, targetSongName, table);
                break;
            }
            case 3: // Popularity Sort
            {
               intMoveUpByOne(j, temporarySongPopularity, targetPopularity, table);
               break;
            }
            default: //putting up a bug-warning message in case of invalid "action" value
            {
                cout << "Error. Action must be either 1, 2 or 3.\nThe program will shutdown.";
                cin.get();
                exit(0);
            }
        }

            table[j + 1].track = temporarySongName;
            table[j + 1].band = temporaryBandName;
            table[j + 1].popularity = temporarySongPopularity;

    }
}


int currentSongPosition(const int NUMBER_OF_SONGS, SongManagement table[], const char *currentSongName, const char *currentGroupName)
{
    /*

    *Determines the position of the current song. 
    May be called after changes have been made to the song list 

    */

    int currentSongNumber;

    for (int i = 0; i < NUMBER_OF_SONGS; ++i) 
    {
        if (std::strcmp(currentGroupName, table[i].band) == 0
                && std::strcmp(currentSongName, table[i].track) == 0) 
        {
            currentSongNumber = i;
            break;
        }
    }

        return currentSongNumber;
}
