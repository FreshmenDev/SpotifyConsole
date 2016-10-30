#include <iostream>
#include <string>

#include "Sorting.h"
#include "Printing.h"
#include "SongManagementStruct.h"
#include "Search.h"

using std::cout;
using std::cin;
using std::endl;


int main () 
{
    const int NUMBER_OF_SONGS = 14;
    int currentSongNumber = 0;
	
	SongManagement songArray[NUMBER_OF_SONGS] = {

		{"Should I Stay or Should I Go"  , "The Clash"       , 0},
		{"Baby don't lie to me"          , "The Fratellis"   , 0},
		{"Ole Black 'n' Blue Eyes"       , "The Fratellis"   , 0},
		{"Like A Champion"               , "The Baseballs"   , 0},
		{"Jackie and Wilson"             , "Hoizer"          , 0},
		{"Mountains"                     , "Message To Bears", 0},
		{"When It's Cold I'd Like to Die", "Moby"            , 0},
		{"Damn Your Eyes"                , "Alex Clare"      , 0},
		{"Heroes"                        , "David Bowie"     , 0},
		{"No Diggity"                    , "Chet Faker"      , 0},
		{"Inhaler"                       , "Foals"           , 0},
		{"London Thunder"                , "Foals"           , 0},
		{"Spanish Sahara"                , "Foals"           , 0},
		{"Asleep"                        , "The Smiths"      , 0}

	};

    SongManagement topSongArray[NUMBER_OF_SONGS];
    
    bool continueLoop = true;

    while (continueLoop) 
    { 
        int selection = -1;

        printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);
        menu();

        cin >> selection;
        cin.ignore();

        switch (selection) 
        {
            case 1: 
            {
                if (currentSongNumber != NUMBER_OF_SONGS - 1) 
                {
                    ++currentSongNumber;
                    ++songArray[currentSongNumber].popularity; 
                }
                break;
            }
            case 2: 
            {
                if (currentSongNumber > 0)
                {
                    --currentSongNumber;
                    ++songArray[currentSongNumber].popularity;
                }
                break;
            }
            case 3: 
            {
                const char* currentSongName = songArray[currentSongNumber].track;
                const char* currentGroupName = songArray[currentSongNumber].band;
                int currentPopularity = songArray[currentSongNumber].popularity;

                sortSongs(NUMBER_OF_SONGS, songArray, 1);

                cout << "\nNew playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray);

                currentSongNumber = currentSongPosition(NUMBER_OF_SONGS, songArray, currentSongName, currentGroupName);
              
                cout << "\nCurrent song position: " << currentSongNumber + 1 << endl;

                printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);

                break;
            }
            case 4: 
            {
                const char* currentSongName = songArray[currentSongNumber].track;
                const char* currentGroupName = songArray[currentSongNumber].band;
                int currentPopularity = songArray[currentSongNumber].popularity;

                sortSongs(NUMBER_OF_SONGS, songArray, 2);

                cout << "\nNew playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray);

                currentSongNumber = currentSongPosition(NUMBER_OF_SONGS, songArray, currentSongName, currentGroupName);

                cout << "\nCurrent song position: " << currentSongNumber << endl;

                printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);

                break;
            }
            case 5: 
            {
                std::string inputBandName;
                cout << "Input band name you are looking for: " << endl;
                std::getline(cin, inputBandName);
                bool found = false;

                // declaring an array of pointers, which will respectively point to 
                // each element of the existing bands array of type SongManagement
                const char **comparingTargetName[NUMBER_OF_SONGS];


                // assigning addresses to the pointer array
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    comparingTargetName[i] = &(songArray[i].band);
                }

                search(inputBandName, NUMBER_OF_SONGS, songArray, comparingTargetName, found);

                break;
            }
            case 6: 
            {
                std::string inputSongName;
                cout << "Input song name you are looking for: " << endl;
                std::getline(cin, inputSongName);
                bool found = false;
				
                // declaring an array of pointers, which will respectively point to 
                // each element of the existing song names array of type SongManagement
                const char **comparingTargetName[NUMBER_OF_SONGS];


                // assigning addresses to the pointer array
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    comparingTargetName[i] = &(songArray[i].track);
                }

                search(inputSongName, NUMBER_OF_SONGS, songArray, comparingTargetName, found);

                break;
            }
            case 7: 
            {
                cout << "\nPlaylist:\n" << endl;
                printOrder(NUMBER_OF_SONGS, songArray);
                break;
            }
            case 8: 
            {
                cout << "\nPlaylist:\n" << endl;
                printOrder(NUMBER_OF_SONGS, songArray);

                cout << "Enter the number of the song you want to play: " << endl;

                int trackNumber;

                cin >> trackNumber;
                cin.ignore();
                --trackNumber;

                if (trackNumber > -1 && trackNumber < NUMBER_OF_SONGS)
                {
                    currentSongNumber = trackNumber;
                    ++songArray[currentSongNumber].popularity;
                }

                printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);

                break;
            }
            case 9: 
            {
                cout << "Now playing: " <<
                    songArray[currentSongNumber].band << " - " << songArray[currentSongNumber].track << endl;
                break;
            }
            case 10: 
            {
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    topSongArray[i] = songArray[i];
                }

                sortSongs(NUMBER_OF_SONGS, topSongArray, 3);

                cout << "\nTop Songs Chart:\n" << endl;
                printOrder(NUMBER_OF_SONGS, topSongArray);
                
                break;
            }
            case 11: 
            {
                const char* currentSongName = songArray[currentSongNumber].track;
                const char* currentGroupName = songArray[currentSongNumber].band;
                int currentPopularity = songArray[currentSongNumber].popularity;
                                
                sortSongs(NUMBER_OF_SONGS, songArray, 3);

                cout << "\nNew playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray);

                currentSongNumber = currentSongPosition(NUMBER_OF_SONGS, songArray, currentSongName, currentGroupName);

                cout << "\nCurrent song position: " << currentSongNumber + 1 << endl;

                printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);

                break;
            }
            case 12:
            {
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    topSongArray[i] = songArray[i];
                }

                sortSongs(NUMBER_OF_SONGS, topSongArray, 3);
                cout << "\nMost popular band is: " << topSongArray[0].band << endl;
                break;
            }
            case 13: 
            {
                continueLoop = false;
                break;
            }
            default:
                cout << "\nUnknown command." << endl;
        }
    }

    cout << "\nGoodbye!" << endl;
}