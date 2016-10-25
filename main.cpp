#include <iostream>
#include <string>

const int TOTAL_NUMBER_OF_SONGS = 20; // количество песен всего

void coutNowPlaying() { //вывод играющей песни. процедура
	std::cout << std::endl << "Now playing: " << arrayGroup[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;
}

void coutPreviousSong() { // вывод предыдущей песни. процедура
	if (numberCurrentSong > 0) {
		std::cout << "Previous song: " << arrayGroup[numberCurrentSong - 1] << " - " << arraySongs[numberCurrentSong - 1] << std::endl;
	}
}

void coutNextSong() { // вывод следующей песни. процедура
	if (numberCurrentSong < real - 1) {
        std::cout << "Next song: " << arrayGroup[numberCurrentSong + 1] << " - " << arraySongs[numberCurrentSong + 1] << std::endl;
	}
}

void coutInPosition() { // вывод позиции
	if (found) {
		std::cout << "Now you can play any song by it position" << std::endl;
	}

	else {
		std::cout << "There are no pesny with name like this " << str << std::endl;
	}
	break;
}

void plusOne() { // 1 and 2 case
	--numberCurrentSong;
	++popularSongs[numberCurrentSong];
}

void newPlaylistOrder() {
	std::cout << "New playlist order " << std::endl;
	for (int i = 0; i < real; ++i) {
		std::cout << arrayGroup[i] << " - " << arraySongs[i] << std::endl;
	}
	for (int i = 0; i < real; ++i) {
		if (std::strcmp(TMP2, arrayGroup[i]) == 0
			&& std::strcmp(TMP, arraySongs[i]) == 0) {
			numberCurrentSong = i;
			break;
		}
	}
}

int main () {

    const char* arraySongs[TOTAL_NUMBER_OF_SONGS]; // массив песен
    const char* arrayGroup[TOTAL_NUMBER_OF_SONGS]; // массив групп
    int popularSongs[TOTAL_NUMBER_OF_SONGS]; // популярность песен

    const char* topSongs[TOTAL_NUMBER_OF_SONGS]; // песни в топе
    const char* topGroup[TOTAL_NUMBER_OF_SONGS]; // группы в топе
    int topPopularSongs[TOTAL_NUMBER_OF_SONGS]; // популярность песен в топе

    int real = 0; // реальное кол-во песен
    int numberCurrentSong = 0; // номер текущей песни

    arraySongs[0] = "Should I Stay or Should I Go";
    arrayGroup[0] = "The Clash";
    popularSongs[0] = 0;

    arraySongs[1] = "Baby don't lie to me";
    arrayGroup[1] = "The Fratellis";
    popularSongs[1] = 0;

    arraySongs[2] = "Ole Black 'n' Blue Eyes";
    arrayGroup[2] = "The Fratellis";
    popularSongs[2] = 0;

    arraySongs[3] = "Like A Champion";
    arrayGroup[3] = "The Baseballs";
    popularSongs[3] = 0;

    arraySongs[4] = "Jackie and Wilson";
    arrayGroup[4] = "Hoizer";
    popularSongs[4] = 0;

    arraySongs[5] = "Mountains";
    arrayGroup[5] = "Message To Bears";
    popularSongs[5] = 0;

    arraySongs[6] = "When It's Cold I'd Like to Die";
    arrayGroup[6] = "Moby";
    popularSongs[6] = 0;

    arraySongs[7] = "Damn Your Eyes";
    arrayGroup[7] = "Alex Clare";
    popularSongs[7] = 0;

    arraySongs[8] = "Heroes";
    arrayGroup[8] = "David Bowie";
    popularSongs[8] = 0;

    arraySongs[9] = "No Diggity";
    arrayGroup[9] = "Chet Faker";
    popularSongs[9] = 0;

    arraySongs[10] = "Inhaler";
    arrayGroup[10] = "Foals";
    popularSongs[10] = 0;

    arraySongs[11] = "London Thunder";
    arrayGroup[11] = "Foals";
    popularSongs[11] = 0;

    arraySongs[12] = "Spanish Sahara";
    arrayGroup[12] = "Foals";
    popularSongs[12] = 0;

    arraySongs[13] = "Asleep";
    arrayGroup[13] = "The Smiths";
    popularSongs[13] = 0;

    real = 14;

    bool continueWork = true;

    while (continueWork) { 
		
		int choise = -1;

        coutNowPlaying();
		coutPreviousSong();
		coutNextSong();

        std::cout << "Enter action you want to make: " << std::endl;
        std::cout << "1) Play next" << std::endl;
        std::cout << "2) Play prev" << std::endl;
        std::cout << "3) Group by band" << std::endl;
        std::cout << "4) Group by song name" << std::endl;
        std::cout << "5) Search song by band " << std::endl;
        std::cout << "6) Search song by name " << std::endl;
        std::cout << "7) Show playlist " << std::endl;
		std::cout << "8) Play specific song (specified by position) " << std::endl;
        std::cout << "9) What is playing now? " << std::endl;
        std::cout << "10) Show my chart " << std::endl;
        std::cout << "11) Sort by popularity " << std::endl;
        std::cout << "12) Show the most popular band " << std::endl;
        std::cout << "13) Exit " << std::endl;

        std::cin >> choise;

        std::cin.ignore();

        switch (choise) {
            case 1: {
                
				if (numberCurrentSong != real - 1) {
                plusOne() 
				}
                break;
            }

            case 2: {
                if (numberCurrentSong > 0) {
                plusOne()
                }
                break;
            }

            case 3: {

                int popular_now = popularSongs[numberCurrentSong]; // текущая популярность
				
                for (int i = 1; i < real; ++i)
                {
                    const char* tmp = arraySongs[i];
                    const char* temp = arrayGroup[i];
                    int variable = popularSongs[i];

                    int j = i-1;
                    while (j> -1 && std::strcmp(temp, arrayGroup[j]) != 0) {
                        arraySongs[j + 1] = arraySongs[j];
                        arrayGroup[j +1] = arrayGroup[j];
                        popularSongs[j+1] = popularSongs[j];
                        --j;
                    }

                   arraySongs[j+1] = tmp;
                   arrayGroup[j+1] = temp;
                   popularSongs[j + 1] = variable;
                }

                newPlaylistOrder();

				std::cout << "Current song position: " << numberCurrentSong + 1 << std::endl;
				coutNowPlaying();
				coutPreviousSong();
				coutNextSong();
                break;
            }

            case 4: {

                for (int i = 1; i<real; ++i) {
                    const char* vNS = arraySongs[i];
                    const char* vNG = arrayGroup[i];
                    int pVP = popularSongs[i];

                    
					int j = i-1;
                    while (j >-1 && std::strcmp(vNS,array_songs[j])!=0) {
                        arraySongs[j + 1] = arraySongs[j];
                        arrayGroup[j + 1] = arrayGroup[j];
                        popularSongs[j + 1] = popularSongs[j];
                        --j;
					}

                    arraySongs[j + 1] = vNS;
                    arrayGroup[j + 1] = vNG;
                    popularSongs[j + 1] = pVP;
                }

                newPlaylistOrder();

                std::cout << "Current song position: "<< numberCurrentSong << std::endl;

                coutNowPlaying();
				coutPreviousSong();
				coutNextSong()
                break;
            }

            case 5: {
                std::string str;
                std::cout << "Input band name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool found = false;
                for (int i=0; i<real; ++i) {
                    if (std::strcmp(str.c_str(), arrayGroup[i]) == 0) {
                        std::cout << i + 1 << ") " << arrayGroup[i] << " - " << arraySongs[i] << std::endl;
                        found = true;
                    }
                }

                coutInPosition();
            }

            case 6: {
                std::string str;
                std::cout << "Input song name you are looking for: " << std::endl;
                std::getline(std::cin, str);
                bool found = false;
                for (int i = 0; i < real; ++i) {
                    if (std::strcmp(str.c_str(), arraySongs[i]) == 0) {
                        std::cout << i + 1 << ") " << arrayGroup[i] << " - " << arraySongs[i] << std::endl;
                        found = true;
                    }
                }

                coutInPosition()
            }

            case 7: {
                std::cout << "Playlist: " << std::endl;
                for (int i = 0; i < real; ++i) {
                    std::cout << arrayGroup[i] << " - " << arraySongs[i] << std::endl;
                }
                break;
            }

            case 8: {
                std::cout << "Ok, here is the playlist: " << std::endl;

                for (int i = 0; i < real; ++i){
                    std::cout << i + 1 << ") " << arrayGroup[i] << " - " << arraySongs[i] << std::endl;
                }

                std::cout <<"Enter song position, you want to play: " << std::endl;

                int songNomer;

                std::cin >> songNomer;

                std::cin.ignore();

                --songNomer;

                if (songNomer > -1 && songNomer<real) {
                    numberCurrentSong = songNomer;
                    ++popularSongs[numberCurrentSong];
                }

                coutNowPlaying();
				coutPreviousSong();
				coutNextSong();

                break;
            }

            case 9: {
                coutNowPlaying();
                break;
            }

            case 10: {
                for (int i =0; i < real;++i) {
                    topSongs[i] = arraySongs[i];
                    topGroup[i] = arrayGroup[i];
                    topPopularSongs[i]=popularSongs[i];
                }

                for (int i = 1;i< real;++i) {
					const char* vNS = topSongs[i]; // временное название песни
					const char* vNG = topGroup[i]; // временное название группы
					int pVP = topPopularSongs[i]; // популярность временной песни

                    int j = i - 1;
                    while (j > -1 && topPopularSongs[j] < pVP) {
                        topSongs[j + 1] = topSongs[j];
						topGroup[j + 1] = topGroup[j];
                        topPopularSongs[j + 1] = topPopularSongs[j];
                        --j;
                    }

                    topSongs[j + 1] = vNS;
                    topGroup[j + 1] = vNG;
                    topPopularSongs[j + 1] = pVP;
                }

                std::cout << "Chart: " << std::endl;

                for(int i=0; i <real; ++i) {
                    std::cout<< (i + 1) << ") "<< topGroup[i]<< " - "<< topSongs[i] << std::endl;
                }

                break;
            }

            case 11: {
				
				const char* currentSongName = arraySongs[numberCurrentSong];
                const char* currentBandName = arrayGroup[numberCurrentSong];
                int currentSongPopularity = popularSongs[numberCurrentSong];

                for (int i = 1; i < real; ++i) { 
					const char* vNS = arraySongs[i]; // временное название песни
                    const char* vNG = arrayGroup[i]; // временное название группы
                    int pVP = popularSongs[i]; // популярность временной песни

                    int j = i - 1;
                    while (j > -1 && popularSongs[j] < pVP) {
                      arraySongs[j + 1] = arraySongs[j];
                      arrayGroup[j + 1] = arrayGroup[j];
                      popularSongs[j + 1] = popularSongs[j];
                      --j;
                    }

                    arraySongs[j + 1] = vNS;
                    arrayGroup[j + 1] = vNG;
                    popularSongs[j + 1] = pVP;
                }

                newPlaylistOrder()
				coutNowPlaying();

                std::cout << "Song, you are listening on " << numberCurrentSong + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
                for (int i = 0; i < real; ++i) {
                    topSongs[i] = arraySongs[i];
                    topGroup[i] = arrayGroup[i];
                    topPopularSongs[i] = popularSongs[i]; 
				}

                for (int i = 1; i < real; ++i) { 
					
					const char* vNS = topSongs[i]; 
					const char* vNG = topSongs[i];
                    int pVP = topPopularSongs[i];

                    int j = i - 1;
                    while (j > -1 && topPopularSongs[j] < pVP) {
                        topSongs[j + 1] = topSongs[j];
                        topGroup[j + 1] = topGroup[j];
                        topPopularSongs[j + 1] = topPopularSongs[j];
                        --j;
                    }

                    topSongs[j + 1] = vNS;
                    topGroup[j + 1] = vNG;
                    topPopularSongs[j + 1] = pVP;
                }

				std::cout << "Most popular band is: " << topGroup[0] << std::endl;
				break;
            }

            case 13: {
                continueWork = false;
                break;
            }

            default:
			std::cout << "Unknown command." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}