#include <iostream>
#include <string>

const int AMOUNT_OF_SONGS = 20;

struct Song
{
	char* track;
	char* group;
	int popularity;
}allSongs[AMOUNT_OF_SONGS];

const char* topSongs[AMOUNT_OF_SONGS];
const char* topGroups[AMOUNT_OF_SONGS];
int popularityIndex[AMOUNT_OF_SONGS];
bool change = false;
bool print = false;

int printInformation(int currSong, int all);
void printNewPlaylistOrder(int all);
void sortingStruct(int currSong, int all, bool chng, bool prnt);


int main () 
{
    	int amountOfAllSongs = 0;
	int numberOfTheCurrentSong = 0;

	allSongs[0] = { "Should I Stay or Should I Go", "The Clash", 0 };
	allSongs[1] = { "Baby don't lie to me", "The Fratellis", 0 };
	allSongs[2] = { "Ole Black 'n' Blue Eyes", "The Fratellis", 0 };
	allSongs[3] = { "Like A Champion", "The Baseballs", 0 };
	allSongs[4] = { "Jackie and Wilson", "Hoizer", 0 };
	allSongs[5] = { "Mountains", "Message To Bears", 0 };
	allSongs[6] = { "When It's Cold I'd Like to Die", "Moby", 0 };
	allSongs[7] = { "Damn Your Eyes", "Alex Clare", 0 };
	allSongs[8] = { "Heroes", "David Bowie", 0 };
	allSongs[9] = { "No Diggity", "Chet Faker", 0 };
	allSongs[10] = { "Inhaler", "Foals", 0 };
	allSongs[11] = { "London Thunder", "Foals", 0 };
	allSongs[12] = { "Spanish Sahara", "Foals", 0 };
	allSongs[13] = { "Asleep", "The Smiths", 0 };

	amountOfAllSongs = 14;

	bool continueWork = true;

    while (continueWork) { 
	int selection = -1;

        printInformation(numberOfTheCurrentSong, amountOfAllSongs); // процедура вывода информации о текущей песне, следующей и предыдущей


        std::cout << "Enter action you want to make: \n" <<
			"1) Play next\n" <<
			"2) Play prev\n" <<
			"3) Group by band\n" <<
			"4) Group by song name\n" <<
			"5) Search song by band \n" <<
			"6) Search song by name \n" <<
			"7) Show playlist \n" <<
			"8) Play specific song (specified by position) \n" <<
			"9) What is playing now? \n" <<
			"10) Show my chart \n" <<
			"11) Sort by popularity \n" <<
			"12) Show the most popular band \n" <<
			"13) Exit \n";

        std::cin >> selection;

        std::cin.ignore();

        switch (selection) {
            case 1: {
                if (numberOfTheCurrentSong != amountOfAllSongs - 1) {
                    ++numberOfTheCurrentSong;
                    ++allSongs[numberOfTheCurrentSong].popularity; 
		}
                break;
            }

            case 2: {
                if (numberOfTheCurrentSong > 0)
                {
                    --numberOfTheCurrentSong;
                    ++allSongs[numberOfTheCurrentSong].popularity;
                }
                break;
            }

            case 3: {
                change = true;
		print = true;

		sortingStruct(amountOfAllSongs, amountOfAllSongs, change, print); // вызываю процедуру для сортировки песен, групп и популярностей песен

                std::cout << "Current song position: " << numberOfTheCurrentSong + 1 << std::endl;

                printInformation(numberOfTheCurrentSong, amountOfAllSongs);
                break;
            }

            case 4: {
                change = true;
		print = true;

		sortingStruct(amountOfAllSongs, amountOfAllSongs, change, print);
		
                std::cout<<"Current song position: "<<nomerTeckusheyPensy<< std::endl;

                printInformation(numberOfTheCurrentSong, amountOfAllSongs);
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool found = false;
                for (int i=0; i < amountOfAllSongs; ++i) {
                    if (std::strcmp(str.c_str(), allSongs[i].group) == 0) {
                        std::cout << i + 1 << ") " << allSongs[i].group << " - " << allSongs[i].track << std::endl;
                        found = true;
                    }
                }

                if (found) {
                    std::cout << "Now you can play any song by it position" << std::endl;
                } else
                {
                    std::cout << "There are no songs with band name like this " << str << std::endl;
                }

                break;
            }

            case 6: {
                std::string str2;
                std::cout << "Input song name you are looking for: " << std::endl;
                std::getline(std::cin, str2);
                bool found = false;
                for (int i = 0; i < amountOfAllSongs; ++i) {
                    if (std::strcmp(str2.c_str(), allSongs[i].track) == 0) {
                        std::cout << i + 1 << ") " << allSongs[i].group << " - " << allSongs[i].track << std::endl;
                        found = true;
                    }
                }

                if (found)
                {
                    std::cout << "Now you can play any song by it position" << std::endl;
                }

                else {
                    std::cout << "There are no songs with name like this " << str2 << std::endl;
                }

                break;
            }

            case 7: {
                std::cout << "Playlist: " << std::endl;
                for (int i = 0; i < amountOfAllSongs; ++i) {
                    std::cout << allSongs[i].group << " - " << allSongs[i].track << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < amountOfAllSongs; ++i){
                    std::cout << i + 1 << ") " << allSongs[i].group << " - " << allSongs[i].track << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNomer;

                std::cin >> songNomer;

                std::cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer < amountOfAllSongs) {
                    numberOfTheCurrentSong = songNomer;
                    ++allSongs[numberOfTheCurrentSong].popularity;
                }

                printInformation(numberOfTheCurrentSong, amountOfAllSongs);
                break;
            }

            case 9: {
                std::cout<< "Now playing: "<<
                          allSongs[numberOfTheCurrentSong].group << " - " << allSongs[numberOfTheCurrentSong].track << std::endl;
                break;
            }

            case 10: {
                for (int i =0; i < amountOfAllSongs;++i) {
                    topSongs[i] = allSongs[i].track;
		    topGroups[i] = allSongs[i].group;
		    popularityIndex[i] = allSongs[i].popularity;
                }

                for (int i = 1;i < amountOfAllSongs;++i) {
		    const char* vremenoeNazvanyePesny = topSongs[i];
                    const char* vremenoeNazvanyeGruppy = topGroups[i];
		    int popularnostVremennoyPesny = popularityIndex[i];

                    int j = i - 1;
                    while (j > -1 && popularityIndex[j] < popularnostVremennoyPesny) {
                        topSongs[j + 1] = topSongs[j];
                 	topGroups[j + 1] = topGroups[j];
                        popularityIndex[j + 1] = popularityIndex[j];
                        --j;
                    }

                    pesny_VTope[j + 1] = vremenoeNazvanyePesny;
                    gruppy_v_tope[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen_v_tope[j + 1] = popularnostVremennoyPesny;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0;i < amountOfAllSongs;++i){
                    std::cout<< (i + 1) << ") "<< topGroups[i]<< " - "<< topSongs[i] << std::endl;
                }

                break;
            }

            case 11: {
		change = true;
		const char* currentSongName = massiv_pesen[nomerTeckusheyPensy];
                const char* currentBandName = massivGrupp[nomerTeckusheyPensy];
                int currentSongPopularity = popularnost_pesen[nomerTeckusheyPensy];

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* vremenoeNazvanyePesny = massiv_pesen[i];
                    const char* vremenoeNazvanyeGruppy = massivGrupp[i];
                    int popularnostVremennoyPesny = popularnost_pesen[i];

                    int j = i - 1;
                    while (j > -1 && popularnost_pesen[j] < popularnostVremennoyPesny) {
                      massiv_pesen[j + 1] = massiv_pesen[j];
                      massivGrupp[j + 1] = massivGrupp[j];
                      popularnost_pesen[j + 1] = popularnost_pesen[j];
                      --j;
                    }


                    massiv_pesen[j + 1] = vremenoeNazvanyePesny;
                    massivGrupp[j + 1] = vremenoeNazvanyeGruppy;
                    popularnost_pesen[j + 1] = popularnostVremennoyPesny;
                }

                printNewPlaylistOrder(amountOfAllSongs);

                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    if (std::strcmp(currentBandName, massivGrupp[i]) == 0
                        && std::strcmp(currentSongName, massiv_pesen[i]) == 0) {
                        nomerTeckusheyPensy = i;
                        break; }
                }

                std::cout << "Now playing: " << massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

                std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
                {
                    pesny_VTope[i] = massiv_pesen[i];
                        gruppy_v_tope[i] = massivGrupp[i];
                    popularnost_pesen_v_tope[i] = popularnost_pesen[i]; }

                for (int i = 1; i < realnoe_kolichestvo_pesen; ++i) { const char* temp1 = pesny_VTope[i]; const char* temp2 = gruppy_v_tope[i];
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

                    std::cout << "Most popular band is: " << gruppy_v_tope[0] << std::endl;
                break;
            }

            case 13: {
                prodolgitRabotu = false;
                break;
            }

            default:
                std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}

void printInformation(int currSong, int all) {
	std::cout << std::endl << "Now playing: " <<
		allSongs[currSong].group << " - " << allSongs[currSong].track << std::endl;

	if (currSong > 0) {
		std::cout << "Previous song: " <<
			allSongs[currSong - 1].group << " - " << allSongs[currSong - 1].track << std::endl;
	}

	if (currSong < all - 1) {
		std::cout << "Next song: " <<
			allSongs[currSong + 1].group << " - " << allSongs[currSong + 1].track << std::endl;
	}
}

void printNewPlaylistOrder(int all) {
	std::cout << "New playlist order " << std::endl;

	for (int i = 0; i < all; ++i) {
		std::cout << allSongs[i].group << " - " << allSongs[i].track << std::endl;
	}
}

/*bool case1011() {
	return (j > -1 && popularnost_pesen_v_tope[j] < popularnostVremennoyPesny);
}*/

void sortingStruct(int currSong, int all, bool chng, bool prnt) {
		const char* TMP = allSongs[currSong].track;
		const char* TMP2 = allSongs[currSong].group;
		int currentPopulatiry = allSongs[currSong].popularity;

	for (int i = 1; i < all; ++i) {
		const char* tmp = allSongs[i].track;
		const char* temp = allSongs[i].group;
		int variable = allSongs[i].popularity;

		int j = i - 1;
		while (j > -1 && std::strcmp(temp, allSongs[j].group) != 0) {
			allSongs[j + 1].track = allSongs[j].track;
			allSongs[j + 1].group = allSongs[j].group;
			allSongs[j + 1].popularity = allSongs[j].popularity;
			--j;
		}

		allSongs[j + 1].track = tmp;
		allSongs[j + 1].group = temp;
		allSongs[j + 1].popularity = variable;
	}

	if (prnt) {
		printNewPlaylistOrder(all);
	}

	if (chng) {
		for (int i = 0; i < all; ++i) {
			if (std::strcmp(TMP2, allSongs[i].group) == 0
				&& std::strcmp(TMP, allSongs[i].track) == 0) {
				currSong = i;
				break;
			}
		}
	}
	chng = false;
	prnt = false;
}
