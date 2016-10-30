#include <iostream>
#include <string>
#include "SongManagementStruct.h"

using std::cout;
using std::endl;


void search(std::string searchName, const int NUMBER_OF_SONGS, SongManagement table[], const char **targetName[], bool found)
{
    /*

    *Searches for and displays any songs or group names in the database that match the provided input.

    searchName:   string input of the user
    **targetName: an array of pointers that should point to a member array of type SongManagement
    found:        True if match is found, false otherwise

    */

    for (int i = 0; i < NUMBER_OF_SONGS; ++i) 
    {
        if (std::strcmp(searchName.c_str(), *targetName[i]) == 0)
        {
            cout << i + 1 << ") " << *targetName[i] << " - " << table[i].track << endl;
            found = true;
        }
    }

    if (found)
    {
        cout << "You can play the song if you enter its position. Check the menu." << endl;
    } 
    else {
        cout << "Name \"" << searchName << "\" not found." << endl;
        cout << "Please try again." << endl;
    }
}
