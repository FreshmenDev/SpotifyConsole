#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


struct SongManagement
{
    const char *pesni;
	const char *Gruppa;
	int         popularnost;
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
        table[j + 1].pesni = table[j].pesni;
        table[j + 1].Gruppa = table[j].Gruppa;
        table[j + 1].popularnost = table[j].popularnost;
        --j;
    }
}

void intMoveUpByOne(int &j, int temporarySongPopularity, int *targetName[], SongManagement table[])
{
    /*

     *Moves up all the array elements of struct SongManagement by one position, until the struct's 
     SongManagement int array becomes equal to its temporary counterpart.

     temporarySongPopularity: number that shows the level of popularity
     **targetName:            an array of pointers that should point to an int 
                              member array of type SongManagement
     &j: loop variable

    */
     while (j > -1 && table[j].popularnost < temporarySongPopularity) 
        {
            table[j + 1].pesni = table[j].pesni;
            table[j + 1].Gruppa = table[j].Gruppa;
            table[j + 1].popularnost = table[j].popularnost;
            --j;
        }
}

// how to declare an array size N inside a function when N is a parameter of that function?
void sortSongs(const int numberOfsongs, SongManagement table[], int action)
{
    /*

    *Sorts songs according to their group (action == 1),
    name (action == 2) or popularity (action == 3)

    */


    // declaring arrays of pointers, which will respectively point to 
    // each element of type SongManagement arrays counterparts
    const char **targetBandName[20];
    const char **targetSongName[20];
    int *targetPopularity[20];

    // assigning addresses to the pointer arrays
    for (int k = 0; (k < numberOfsongs); ++k)
    {
        targetBandName[k] = &(table[k].Gruppa);
        targetSongName[k] = &(table[k].pesni);
        targetPopularity[k] = &(table[k].popularnost);
    }


    for (int i = 1; i < numberOfsongs; ++i)
    {
        const char *temporarySongName = table[i].pesni;
        const char *temporaryBandName = table[i].Gruppa;
        int temporarySongPopularity = table[i].popularnost;
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

            table[j + 1].pesni = temporarySongName;
            table[j + 1].Gruppa = temporaryBandName;
            table[j + 1].popularnost = temporarySongPopularity;

    }
}

void printOrder(const int numberOfsongs, SongManagement table[]) 
    {
        /** Prints out an ordered list of the songs present */

        cout << "New playlist order:\n " << endl;
        for (int i = 0; i < numberOfsongs; ++i) 
        {
            cout << table[i].Gruppa << " - " << table[i].pesni << endl;
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

void printPlaylist(const int numberOfsongs, SongManagement table[])
{

    /**Prints out the current playlist*/

    cout << "Playlist: \n" << endl;

    for (int i = 0; i < numberOfsongs; ++i) 
    {
        cout << table[i].Gruppa << " - " << table[i].pesni << endl;
    }
    return;
}

void printCurrentSongDetails(const int numberOfsongs, SongManagement table[], int currentSongNumber)
{
    /*

    *Prints out the full description of the song playing as well as 
    the descriptions of the previous and next songs

    */

    cout << endl << "Now playing: " <<
        table[currentSongNumber].Gruppa << " - " << table[currentSongNumber].pesni << '\n' << endl;

    if (currentSongNumber > 0) 
    {
        cout << "Previous song: " <<
        table[currentSongNumber - 1].Gruppa << " - " << table[currentSongNumber - 1].pesni << '\n' << endl;
    }

    if (currentSongNumber < numberOfsongs - 1) 
    {
        cout << "Next song: " <<
        table[currentSongNumber + 1].Gruppa << " - " << table[currentSongNumber + 1].pesni << '\n' << endl;
    }
}

int currentSongPosition(const int numberOfsongs, SongManagement table[], const char *currentSongName, const char *currentGroupName)
{
    /*

    *Determines the position of the current song. 
    May be called after changes have been made to the song list 

    */

    int currentSongNumber;

    for (int i = 0; i < numberOfsongs; ++i) 
    {
        if (std::strcmp(currentGroupName, table[i].Gruppa) == 0
                && std::strcmp(currentSongName, table[i].pesni) == 0) 
        {
            currentSongNumber = i;
            break;
        }
    }

        return currentSongNumber;
}

void search(std::string searchName, const int numberOfsongs, SongManagement table[], const char **targetName[], bool found)
{
    /*

    *Searches for and displays any songs or group names in the database that match the provided input.

    searchName:   string input of the user
    **targetName: an array of pointers that should point to a member array of type SongManagement
    found:        True if match is found, false otherwise

    */

    for (int i=0; i < numberOfsongs; ++i) 
    {
        if (std::strcmp(searchName.c_str(), *targetName[i]) == 0)
        {
            cout << i + 1 << ") " << *targetName[i] << " - " << table[i].pesni << endl;
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
    const int KOLICHESTVO_PESEN_VSEGO = 20; // maximum number of songs
    const int realnoe_kolichestvo_pesen = 14; // numberOfsongs
    int nomerTeckusheyPensy = 0; // currentSongNumber
	
	SongManagement Massiv[KOLICHESTVO_PESEN_VSEGO] = {

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
    
    const char *pesny_VTope[KOLICHESTVO_PESEN_VSEGO];
    const char *gruppy_v_tope[KOLICHESTVO_PESEN_VSEGO];
    int popularnost_pesen_v_tope[KOLICHESTVO_PESEN_VSEGO];

    bool prodolgitRabotu = true;

    while (prodolgitRabotu) 
    { 
        int vybor = -1;

        printCurrentSongDetails(realnoe_kolichestvo_pesen, Massiv, nomerTeckusheyPensy);
        menu();

        cin >> vybor;

        cin.ignore();

        switch (vybor) 
        {
            case 1: 
            {
                if (nomerTeckusheyPensy != realnoe_kolichestvo_pesen - 1) 
                {
                    ++nomerTeckusheyPensy;
                    ++Massiv[nomerTeckusheyPensy].popularnost; 
                }
                break;
            }
            case 2: 
            {
                if (nomerTeckusheyPensy > 0)
                {
                    --nomerTeckusheyPensy;
                    ++Massiv[nomerTeckusheyPensy].popularnost;
                }
                break;
            }
            case 3: 
            {
                const char* currentSongName = Massiv[nomerTeckusheyPensy].pesni;
                const char* currentGroupName = Massiv[nomerTeckusheyPensy].Gruppa;
                int currentPopularity = Massiv[nomerTeckusheyPensy].popularnost;

                sortSongs(realnoe_kolichestvo_pesen, Massiv, 1);
                printOrder(realnoe_kolichestvo_pesen, Massiv);
                nomerTeckusheyPensy = currentSongPosition(realnoe_kolichestvo_pesen, Massiv, currentSongName, currentGroupName);
              
                cout << "\nCurrent song position: " << nomerTeckusheyPensy + 1 << endl;

                printCurrentSongDetails(realnoe_kolichestvo_pesen, Massiv, nomerTeckusheyPensy);

                break;
            }
            case 4: 
            {
                const char* currentSongName = Massiv[nomerTeckusheyPensy].pesni;
                const char* currentGroupName = Massiv[nomerTeckusheyPensy].Gruppa;
                int currentPopularity = Massiv[nomerTeckusheyPensy].popularnost;

                sortSongs(realnoe_kolichestvo_pesen, Massiv, 2);
                printOrder(realnoe_kolichestvo_pesen, Massiv);
                nomerTeckusheyPensy = currentSongPosition(realnoe_kolichestvo_pesen, Massiv, currentSongName, currentGroupName);

                cout << "\nCurrent song position: " << nomerTeckusheyPensy << endl;

                printCurrentSongDetails(realnoe_kolichestvo_pesen, Massiv, nomerTeckusheyPensy);

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
                const char **comparingTargetName[KOLICHESTVO_PESEN_VSEGO];


                // assigning addresses to the pointer array
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    comparingTargetName[i] = &(Massiv[i].Gruppa);
                }

				search(inputBandName, realnoe_kolichestvo_pesen, Massiv, comparingTargetName, nashel);

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
                const char **comparingTargetName[KOLICHESTVO_PESEN_VSEGO];


                // assigning addresses to the pointer array
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    comparingTargetName[i] = &(Massiv[i].pesni);
                }

                search(inputSongName, realnoe_kolichestvo_pesen, Massiv, comparingTargetName, nashel);

                break;
            }
            case 7: 
            {
                printPlaylist(realnoe_kolichestvo_pesen, Massiv);
                break;
            }
            case 8: 
            {
                printPlaylist(realnoe_kolichestvo_pesen, Massiv);

                cout << "Enter the number of the song you want to play: " << endl;

                int songNomer;

                cin >> songNomer;
                cin.ignore();
                --songNomer;

                if (songNomer > -1 && songNomer < realnoe_kolichestvo_pesen)
                {
                    nomerTeckusheyPensy = songNomer;
                    ++Massiv[nomerTeckusheyPensy].popularnost;
                }

                printCurrentSongDetails(realnoe_kolichestvo_pesen, Massiv, nomerTeckusheyPensy);

                break;
            }
            case 9: 
            {
                cout << "Now playing: " <<
                    Massiv[nomerTeckusheyPensy].Gruppa << " - " << Massiv[nomerTeckusheyPensy].pesni << endl;
                break;
            }
            case 10: 
            {
                for (int i = 0; i < realnoe_kolichestvo_pesen;++i) 
                {
                    pesny_VTope[i] = Massiv[i].pesni;
                    gruppy_v_tope[i] = Massiv[i].Gruppa;
                    popularnost_pesen_v_tope[i] = Massiv[i].popularnost;
                }

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
					
                    const char* vremenoeNazvanyePesny = pesny_VTope[i];
                    const char* vremenoeNazvanyeGruppy = gruppy_v_tope[i];
					int popularnostVremennoyPesny = popularnost_pesen_v_tope[i];
                    int j = i - 1;
					
                    while (j > -1 && popularnost_pesen_v_tope[j] < popularnostVremennoyPesny)
                    {
                        pesny_VTope[j + 1] = pesny_VTope[j];
                        gruppy_v_tope[j + 1] = gruppy_v_tope[j];
                        popularnost_pesen_v_tope[j + 1] = popularnost_pesen_v_tope[j];
                        --j;
                    }

                    pesny_VTope[j + 1] = vremenoeNazvanyePesny;
                    gruppy_v_tope[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen_v_tope[j + 1] = popularnostVremennoyPesny;
                }

                cout << "Chart: " << endl;

                for(int i=0; i <realnoe_kolichestvo_pesen; ++i)
                {
                    cout<< (i + 1) << ") "<< gruppy_v_tope[i]<< " - "<< pesny_VTope[i] << endl;
                }

                break;
            }
            case 11: 
            {
                const char* currentSongName = Massiv[nomerTeckusheyPensy].pesni;
                const char* currentGroupName = Massiv[nomerTeckusheyPensy].Gruppa;
                int currentPopularity = Massiv[nomerTeckusheyPensy].popularnost;

                
                sortSongs(realnoe_kolichestvo_pesen, Massiv, 3);     
                printOrder(realnoe_kolichestvo_pesen, Massiv);
                nomerTeckusheyPensy = currentSongPosition(realnoe_kolichestvo_pesen, Massiv, currentSongName, currentGroupName);

				cout << "\nCurrent song position: " << nomerTeckusheyPensy + 1 << endl;

                printCurrentSongDetails(realnoe_kolichestvo_pesen, Massiv, nomerTeckusheyPensy);

                break;
            }
            case 12:
            {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    pesny_VTope[i] = Massiv[i].pesni;
                    gruppy_v_tope[i] = Massiv[i].Gruppa;
                    popularnost_pesen_v_tope[i] = Massiv[i].popularnost; 
                }

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
                {
                    const char* temp1 = pesny_VTope[i]; 
                    const char* temp2 = gruppy_v_tope[i];
                    int temp3 = popularnost_pesen_v_tope[i];
                    int j = i - 1;
					
                    while (j > -1 && popularnost_pesen_v_tope[j] < temp3)
                    {
                        pesny_VTope[j + 1] = pesny_VTope[j];
                        gruppy_v_tope[j + 1] = gruppy_v_tope[j];
                        popularnost_pesen_v_tope[j + 1] = popularnost_pesen_v_tope[j];
                        --j;
                    }

                    pesny_VTope[j + 1] = temp1;
                    gruppy_v_tope[j + 1] = temp2;
                    popularnost_pesen_v_tope[j + 1] = temp3;
                }

                    cout << "Most popular band is: " << gruppy_v_tope[0] << endl;
                break;
            }
            case 13: 
            {
                prodolgitRabotu = false;
                break;
            }
            default:
                cout << "Unknown command." << endl;
        }
    }

    cout << "Goodbye!" << endl;
}