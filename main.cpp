#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


struct SongManagement
{
    const char *track;
	const char *band;
	int         popularity;

    const char *topSongs;
    const char *topBands;
    int topSongPopularity;
};

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
     *targetName:            an array of pointers that should point to an int 
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

// how to declare an array of size N inside a function when N is a parameter of that function?
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

void sortTopSongs(const int NUMBER_OF_SONGS, SongManagement table[])
{

	/**Calculates and sorts the top songs by popularity*/
	
    for (int i = 0; i < NUMBER_OF_SONGS; ++i)
    {
        table[i].topSongs = table[i].track;
        table[i].topBands = table[i].band;
        table[i].topSongPopularity = table[i].popularity; 
    }
	
	for (int i = 1; i < NUMBER_OF_SONGS; ++i)
    {
        const char* temporarySongName = table[i].topSongs; 
        const char* temporaryBandName = table[i].topBands;
        int temporarySongPopularity = table[i].topSongPopularity;
        int j = i - 1;
					
        while (j > -1 && table[j].topSongPopularity < temporarySongPopularity)
        {
            table[j + 1].topSongs = table[j].topSongs;
            table[j + 1].topBands = table[j].topBands;
            table[j + 1].topSongPopularity = table[j].topSongPopularity;
            --j;
        }

        table[j + 1].topSongs = temporarySongName;
        table[j + 1].topBands = temporaryBandName;
        table[j + 1].topSongPopularity = temporarySongPopularity;
    }
}

void printOrder(const int NUMBER_OF_SONGS, SongManagement table[], int action) 
    {
        /*

        * Prints out an ordered list of the songs present 
          (action == 1) -> prints out current playlist
          (action == 2) -> prints out top songs chart

        */

        if (action == 1)
        {
            for (int i = 0; i < NUMBER_OF_SONGS; ++i) 
            {
                cout << i + 1 << ") " << table[i].band << " - " << table[i].track << endl;
            }
        }
        else if (action == 2)
        {
            for (int i = 0; i < NUMBER_OF_SONGS; ++i)
            {
                cout << i + 1 << ") " << table[i].topBands << " - " << table[i].topSongs << endl;
            }
        }
        else {
            cout << "Error. Action must be either 1 or 2.\nThe program will shutdown.";
            cin.get();
            exit(0);
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

                cout << "New playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 1);

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

                cout << "New playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 1);

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
                bool nashel = false;

                // declaring an array of pointers, which will respectively point to 
                // each element of the existing bands array of type SongManagement
                const char **comparingTargetName[NUMBER_OF_SONGS];


                // assigning addresses to the pointer array
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    comparingTargetName[i] = &(songArray[i].band);
                }

				search(inputBandName, NUMBER_OF_SONGS, songArray, comparingTargetName, nashel);

                break;
            }
            case 6: 
            {
                std::string inputSongName;
                cout << "Input song name you are looking for: " << endl;
                std::getline(cin, inputSongName);
                bool nashel = false;
				
                // declaring an array of pointers, which will respectively point to 
                // each element of the existing song names array of type SongManagement
                const char **comparingTargetName[NUMBER_OF_SONGS];


                // assigning addresses to the pointer array
                for (int i = 0; i < NUMBER_OF_SONGS; ++i)
                {
                    comparingTargetName[i] = &(songArray[i].track);
                }

                search(inputSongName, NUMBER_OF_SONGS, songArray, comparingTargetName, nashel);

                break;
            }
            case 7: 
            {
                cout << "Playlist:\n" << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 1);
                break;
            }
            case 8: 
            {
                cout << "Playlist:\n" << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 1);

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
                sortTopSongs(NUMBER_OF_SONGS, songArray);

                cout << "Top Songs Chart:\n" << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 2);
                
                break;
            }
            case 11: 
            {
                const char* currentSongName = songArray[currentSongNumber].track;
                const char* currentGroupName = songArray[currentSongNumber].band;
                int currentPopularity = songArray[currentSongNumber].popularity;
                                
                sortSongs(NUMBER_OF_SONGS, songArray, 3);

                cout << "New playlist order:\n " << endl;
                printOrder(NUMBER_OF_SONGS, songArray, 1);

                currentSongNumber = currentSongPosition(NUMBER_OF_SONGS, songArray, currentSongName, currentGroupName);

				cout << "\nCurrent song position: " << currentSongNumber + 1 << endl;

                printCurrentSongDetails(NUMBER_OF_SONGS, songArray, currentSongNumber);

                break;
            }
            case 12:
            {
                sortTopSongs(NUMBER_OF_SONGS, songArray);
                cout << "\nMost popular band is: " << songArray[0].topBands << endl;
                break;
            }
            case 13: 
            {
                continueLoop = false;
                break;
            }
            default:
                cout << "Unknown command." << endl;
        }
    }

    cout << "Goodbye!" << endl;
}