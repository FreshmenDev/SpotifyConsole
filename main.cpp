#include <iostream>
#include <string>
#include <cstring>

const int AMOUNT_OF_SONGS = 20;

struct Song {
	std::string track;
	std::string group;
	int popularity;
} allSongs[AMOUNT_OF_SONGS];

struct Popular {
	std::string topSongs;
	std::string topGroups;
	int popularityIndex;
} topList[AMOUNT_OF_SONGS];

bool needToCompareTwoStrings, needToComparePopularity, findBandName, findSongName;
std::string stringBand, stringSong;

void printInformation(int currentSongIndex, int amountOfSongs);
void printNewPlaylistOrder(int amountOfSongs);
void sortingSongs(int currentSongIndex, int amountOfSongs);
void changeSongNumber(int currentSongIndex, int amountOfSongs);
void searchingSong(int amountOfSongs, std::string stringForOutputtingBandOrSong);
void updateTopList(int amountOfSongs);


int main () {
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

        	printInformation(numberOfTheCurrentSong, amountOfAllSongs); 
		// процедура вывода информации о текущей песне, следующей и предыдущей

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
                if (numberOfTheCurrentSong > 0) {
                    --numberOfTheCurrentSong;
                    ++allSongs[numberOfTheCurrentSong].popularity;
                }
                break;
            }

            case 3: {
                needToCompareTwoStrings = true; needToComparePopularity = false;
		// нужно ли менять номер текущего трека, выводить информацию, мы находимся в Case3,4,11 или 10, 12
		sortingSongs(numberOfTheCurrentSong, amountOfAllSongs);
		// вызываю процедуру для сортировки песен, групп и популярностей песен
		printNewPlaylistOrder(amountOfAllSongs); // выводит порядок воспроизведения песен на экран
		    
		changeSongNumber(numberOfTheCurrentSong, amountOfAllSongs); // изменяет старый номер трека на новый 
		    
                std::cout << "Current song position: " << numberOfTheCurrentSong + 1 << std::endl;

                printInformation(numberOfTheCurrentSong, amountOfAllSongs);
                break;
            }

            case 4: {
                needToCompareTwoStrings = true;
		sortingSongs(numberOfTheCurrentSong, amountOfAllSongs);

		printNewPlaylistOrder(amountOfAllSongs); 

		changeSongNumber(numberOfTheCurrentSong, amountOfAllSongs);
		
                std::cout<<"Current song position: "<< numberOfTheCurrentSong << std::endl;

                printInformation(numberOfTheCurrentSong, amountOfAllSongs);
                break;
            }

            case 5: {
		stringBand = "band";
		findBandName = true, findSongName = false;	
		searchingSong(amountOfAllSongs, stringBand); // ищем трек по названия группы или песни
                break;
            }

            case 6: {
		stringSong = "song";
		findSongName = true;
		searchingSong(amountOfAllSongs, stringSong);
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

                int songNumber;

                std::cin >> songNumber;

                std::cin.ignore();

                --songNumber;

                if (songNumber > -1 && songNumber < amountOfAllSongs) {
                    numberOfTheCurrentSong = songNumber;
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
		needToComparePopularity = true;
		
                updateTopList(amountOfAllSongs);

                sortingSongs(numberOfTheCurrentSong, amountOfAllSongs);

                std::cout << "Chart: " << std::endl;

                for(int i=0;i < amountOfAllSongs;++i){
                    std::cout<< (i + 1) << ") "<< topList[i].topGroups << " - " << topList[i].topSongs << std::endl;
                }

                break;
            }

            case 11: {
		needToCompareTwoStrings = true;
		sortingSongs(numberOfTheCurrentSong, amountOfAllSongs);

		printNewPlaylistOrder(amountOfAllSongs);

		changeSongNumber(numberOfTheCurrentSong, amountOfAllSongs);

                std::cout << "Now playing: " << allSongs[numberOfTheCurrentSong].group << " - " << allSongs[numberOfTheCurrentSong].track << std::endl;

                std::cout << "Song, you are listening on " << numberOfTheCurrentSong + 1 << " position of chart" << std::endl;
                break;
            }


            case 12: {
		needToComparePopularity = true;
		
                updateTopList(amountOfAllSongs);
		
		sortingSongs(numberOfTheCurrentSong, amountOfAllSongs);

                std::cout << "Most popular band is: " << topList[0].topGroups << std::endl;
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

void printInformation(int currentSongIndex, int amountOfSongs) { // процедура вывода информации о текущей песне, следующей и предыдущей
	std::cout << std::endl << "Now playing: " <<
		allSongs[currentSongIndex].group << " - " << allSongs[currentSongIndex].track << std::endl;

	if (currentSongIndex > 0) {
		std::cout << "Previous song: " <<
			allSongs[currentSongIndex - 1].group << " - " << allSongs[currentSongIndex - 1].track << std::endl;
	}

	if (currentSongIndex < amountOfSongs - 1) {
		std::cout << "Next song: " <<
			allSongs[currentSongIndex + 1].group << " - " << allSongs[currentSongIndex + 1].track << std::endl;
	}
}

void printNewPlaylistOrder(int amountOfSongs) {
	std::cout << "New playlist order " << std::endl;

	for (int i = 0; i < amountOfSongs; ++i) {
		std::cout << allSongs[i].group << " - " << allSongs[i].track << std::endl;
	}
}
		// процедура для сортировки структур данных, часто повторяющийся код в Case3, 4, 11 и Case10, 12
void sortingSongs(int currentSongIndex, int amountOfSongs) {
	if (needToCompareTwoStrings) {	// условие для Case3, 4, 11
		for (int i = 1; i < amountOfSongs; ++i) {
			const std::string temporaryTrackName = allSongs[i].track;
			const std::string temporaryGropuName = allSongs[i].group;
			int temporaryPopularityVariable = allSongs[i].popularity;

			int j = i - 1;			// если j > -1 и две строки не равны, то выполнить тело цикла
			while (j > -1 && std::strcmp(temporaryGropuName.c_str(), allSongs[j].group.c_str()) != 0) {
				allSongs[j + 1].track = allSongs[j].track;
				allSongs[j + 1].group = allSongs[j].group;
				allSongs[j + 1].popularity = allSongs[j].popularity;
				--j;

				allSongs[j + 1].track = temporaryTrackName;
				allSongs[j + 1].group = temporaryGropuName;
				allSongs[j + 1].popularity = temporaryPopularityVariable;
		}
	}
	if (needToComparePopularity) {	// условие для Case10, 12
		for (int i = 1; i < amountOfSongs; ++i) {
			const std::string tempSongName = topList[i].topSongs;
			const std::string tempBandName = topList[i].topGroups;
			int tempPopularity = topList[i].popularityIndex;

			int j = i - 1;
			while (j > -1 && topList[j].popularityIndex < tempPopularity) {
				topList[j + 1].topSongs = topList[j].topSongs;
				topList[j + 1].topGroups = topList[j].topGroups;
				topList[j + 1].popularityIndex = topList[j].popularityIndex;
					--j;
				}

				topList[j + 1].topSongs = tempSongName;
				topList[j + 1].topGroups = tempBandName;
				topList[j + 1].popularityIndex = tempPopularity;
				}
			}
	}
	needToCompareTwoStrings = false; needToComparePopularity = false;
}

void changeSongNumber(int currentSongIndex, int amountOfSongs) { // изменяет старый номер трека на новый 
	std::string temporaryTrackString = allSongs[currentSongIndex].track;
	std::string temporaryGroupString = allSongs[currentSongIndex].group;

	for (int i = 0; i < amountOfSongs; ++i) {
		if (std::strcmp(temporaryGroupString.c_str(), allSongs[i].group.c_str()) == 0
			&& std::strcmp(temporaryTrackString.c_str(), allSongs[i].track.c_str()) == 0) {
			currentSongIndex = i;
			break;
		}
	}
}

	// процедура для поиска композиции по ее названию или названию группы
void searchingSong(int amountOfSongs, std::string stringForOutputtingBandOrSong) {
	std::string bandOrSongName;
	std::cout << "Input " << stringForOutputtingBandOrSong << " name you are looking for: " << std::endl;
	std::getline(std::cin, bandOrSongName);
	bool found = false;
	if (findBandName) {	// в данном случае для поиска названия группы
		for (int i = 0; i < amountOfSongs; ++i) {
			if (std::strcmp(bandOrSongName.c_str(), allSongs[i].group.c_str()) == 0) {
				std::cout << i + 1 << ") " << allSongs[i].group << " - " << allSongs[i].track << std::endl;
				found = true;
			}
		}
	}
	if (findSongName) {	// для поиска названия песни
		for (int i = 0; i < amountOfSongs; ++i) {
			if (std::strcmp(bandOrSongName.c_str(), allSongs[i].track.c_str()) == 0) {
				std::cout << i + 1 << ") " << allSongs[i].group << " - " << allSongs[i].track << std::endl;
				found = true;
			}
		}
	}

	if (found) {
		std::cout << "Now you can play any song by it position" << std::endl;
	}

	else {
		std::cout << "There are no songs with " << stringForOutputtingBandOrSong << " name like this " << bandOrSongName << std::endl;
	}
	findBandName = false; findSongName = false; 
}

void updateTopList(int amountOfSongs) { // обновление элементов структуры topList, используемое в Case10 и 12
	for (int i = 0; i < amountOfSongs; ++i) {
		topList[i].topSongs = allSongs[i].track;
		topList[i].topGroups = allSongs[i].group;
		topList[i].popularityIndex = allSongs[i].popularity;
	}
}
