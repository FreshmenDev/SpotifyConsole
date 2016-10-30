#include <iostream>
#include "SongManagementStruct.h"

using std::cout;
using std::cin;
using std::endl;

void printOrder(const int NUMBER_OF_SONGS, SongManagement table[]) 
{
    /** Prints out an ordered list of the songs present*/

    for (int i = 0; i < NUMBER_OF_SONGS; ++i) 
    {
        cout << i + 1 << ") " << table[i].band << " - " << table[i].track << endl;
    }
}

void menu()
{
    /** Prints out the user menu */

    cout << "Enter action you want to make: \n" << endl;
    cout << "1) Play next" << endl;
    cout << "2) Play prev" << endl;
    cout << "3) Group by band" << endl;
    cout << "4) Group by song name" << endl;
    cout << "5) Search song by band " << endl;
    cout << "6) Search song by name " << endl;
    cout << "7) Show playlist " << endl;
    cout << "8) Play specific song (specified by position) " << endl;
    cout << "9) What is playing now? " << endl;
    cout << "10) Show my chart " << endl;
    cout << "11) Sort by popularity " << endl;
    cout << "12) Show the most popular band " << endl;
    cout << "13) Exit " << endl;
}

void printCurrentSongDetails(const int NUMBER_OF_SONGS, SongManagement table[], int currentSongNumber)
{
    /*

    *Prints out the full description of the song playing as well as 
    the descriptions of the previous and next songs

    */

    cout << endl << "Now playing: " <<
        table[currentSongNumber].band << " - " << table[currentSongNumber].track << '\n' << endl;

    if (currentSongNumber > 0) 
    {
        cout << "Previous song: " <<
        table[currentSongNumber - 1].band << " - " << table[currentSongNumber - 1].track << '\n' << endl;
    }

    if (currentSongNumber < NUMBER_OF_SONGS - 1) 
    {
        cout << "Next song: " <<
        table[currentSongNumber + 1].band << " - " << table[currentSongNumber + 1].track << '\n' << endl;
    }
}
