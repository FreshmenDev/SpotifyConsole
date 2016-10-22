#include <iostream>
#include <string>

int main()
{
	const int TOTAL_NUMBER_OF_SONGS = 20;
	struct information 
	{
		const char* arraySongs;
		const char* arrayGroups;
		int popularSongs;
	};

	const char* songsInTheTop[TOTAL_NUMBER_OF_SONGS];
	const char* groupInTheTop[TOTAL_NUMBER_OF_SONGS];
	int popularSongsInTheTop[TOTAL_NUMBER_OF_SONGS];

	int realNumberSongs = 0;
	int numberCurrentSong = 0;

	information information_track[TOTAL_NUMBER_OF_SONGS];
	information_track[0].arraySongs = "Should I Stay or Should I Go";
	information_track[0].arrayGroups = "The Clash";
	information_track[0].popularSongs = 0;

	information_track[1].arraySongs = "Baby don't lie to me";
	information_track[1].arrayGroups = "The Fratellis";
	information_track[1].popularSongs = 0;

	information_track[2].arraySongs = "Ole Black 'n' Blue Eyes";
	information_track[2].arrayGroups = "The Fratellis";
	information_track[2].popularSongs = 0;

	information_track[3].arraySongs = "Like A Champion";
	information_track[3].arrayGroups = "The Baseballs";
	information_track[3].popularSongs = 0;

	information_track[4].arraySongs = "Jackie and Wilson";
	information_track[4].arrayGroups = "Hoizer";
	information_track[4].popularSongs = 0;

	information_track[5].arraySongs = "Mountains";
	information_track[5].arrayGroups = "Message To Bears";
	information_track[5].popularSongs = 0;

	information_track[6].arraySongs = "When It's Cold I'd Like to Die";
	information_track[6].arrayGroups = "Moby";
	information_track[6].popularSongs = 0;

	information_track[7].arraySongs = "Damn Your Eyes";
	information_track[7].arrayGroups = "Alex Clare";
	information_track[7].popularSongs = 0;

	information_track[8].arraySongs = "Heroes";
	information_track[8].arrayGroups = "David Bowie";
	information_track[8].popularSongs = 0;

	information_track[9].arraySongs = "No Diggity";
	information_track[9].arrayGroups = "Chet Faker";
	information_track[9].popularSongs = 0;

	information_track[10].arraySongs = "Inhaler";
	information_track[10].arrayGroups = "Foals";
	information_track[10].popularSongs = 0;

	information_track[11].arraySongs = "London Thunder";
	information_track[11].arrayGroups = "Foals";
	information_track[11].popularSongs = 0;

	information_track[12].arraySongs = "Spanish Sahara";
	information_track[12].arrayGroups = "Foals";
	information_track[12].popularSongs = 0;

	information_track[13].arraySongs = "Asleep";
	information_track[13].arrayGroups = "The Smiths";
	information_track[13].popularSongs = 0;

	realNumberSongs = 14;

	bool ContinueWork = true;

	while (ContinueWork)
	{
		int selection = -1;

		std::cout << std::endl << "Now playing: " <<
			arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;

		if (numberCurrentSong > 0)
		{
			std::cout << "Previous song: " <<
				arrayGroups[numberCurrentSong - 1] << " - " << arraySongs[numberCurrentSong - 1] << std::endl;
		}

		if (numberCurrentSong < realNumberSongs - 1)
		{
			std::cout << "Next song: " <<
				arrayGroups[numberCurrentSong + 1] << " - " << arraySongs[numberCurrentSong + 1] << std::endl;
		}


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

		std::cin >> selection;

		std::cin.ignore();

		switch (selection)
		{
		case 1:
		{
			if (numberCurrentSong != realNumberSongs - 1)
			{
				++numberCurrentSong;
				++popularSongs[numberCurrentSong];
			}
			break;
		}

		case 2:
		{
			if (numberCurrentSong > 0)
			{
				--numberCurrentSong;
				++popularSongs[numberCurrentSong];
			}
			break;
		}

		case 3:
		{
			const char* TMP = arraySongs[numberCurrentSong];
			const char* TMP2 = arrayGroups[numberCurrentSong];
			int currentPopular = popularSongs[numberCurrentSong];


			for (int i = 1; i < realNumberSongs; ++i)
			{
				const char* tmp = arraySongs[i];
				const char* temp = arrayGroups[i];
				int variable = popularSongs[i];

				int j = i - 1;
				while (j > -1 && std::strcmp(temp, arrayGroups[j]) != 0)
				{
					arraySongs[j + 1] = arraySongs[j];
					arrayGroups[j + 1] = arrayGroups[j];
					popularSongs[j + 1] = popularSongs[j];
					--j;
				}

				arraySongs[j + 1] = tmp;
				arrayGroups[j + 1] = temp;
				popularSongs[j + 1] = variable;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
			}

			for (int i = 0; i < realNumberSongs; ++i)
			{
				if (std::strcmp(TMP2, arrayGroups[i]) == 0
					&& std::strcmp(TMP, arraySongs[i]) == 0)
				{
					numberCurrentSong = i;
					break;
				}
			}

			std::cout << "Current song position: " << numberCurrentSong + 1 << std::endl;

			std::cout << "Now playing: " <<
				arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;

			if (numberCurrentSong > 0)
			{
				std::cout << "Previous song: " <<
					arrayGroups[numberCurrentSong - 1] << " - " << arraySongs[numberCurrentSong - 1] << std::endl;
			}

			if (numberCurrentSong < realNumberSongs - 1)
			{
				std::cout << "Next song: " <<
					arrayGroups[numberCurrentSong + 1] << " - " << arraySongs[numberCurrentSong + 1] << std::endl;
			}
			break;
		}

		case 4:
		{
			const char* nameCurrentSong = arraySongs[numberCurrentSong];
			const char* nameCurrentGroup = arrayGroups[numberCurrentSong];
			int popularCurrentGroup = popularSongs[numberCurrentSong];

			for (int i = 1; i < realNumberSongs; ++i)
			{
				const char* temporaryNameSong = arraySongs[i];
				const char* temporaryNameGroup = arrayGroups[i];
				int popularTemporarySong = popularSongs[i];

				int j = i - 1;
				while (j > -1 && std::strcmp(temporaryNameSong, arraySongs[j]) != 0)
				{
					arraySongs[j + 1] = arraySongs[j];
					arrayGroups[j + 1] = arrayGroups[j];
					popularSongs[j + 1] = popularSongs[j];
					--j;
				}


				arraySongs[j + 1] = temporaryNameSong;
				arrayGroups[j + 1] = temporaryNameGroup;
				popularSongs[j + 1] = popularTemporarySong;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
			}

			for (int i = 0; i < realNumberSongs; ++i)
			{
				if (std::strcmp(nameCurrentGroup, arrayGroups[i]) == 0
					&& std::strcmp(nameCurrentSong, arraySongs[i]) == 0)
				{
					numberCurrentSong = i;
					break;
				}
			}

			std::cout << "Current song position: " << numberCurrentSong << std::endl;

			std::cout << "Now playing: " <<
				arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;

			if (numberCurrentSong > 0)
			{
				std::cout << "Previous song: " <<
					arrayGroups[numberCurrentSong - 1] << " - " << arraySongs[numberCurrentSong - 1] << std::endl;
			}

			if (numberCurrentSong < realNumberSongs - 1)
			{
				std::cout << "Next song: " <<
					arrayGroups[numberCurrentSong + 1] << " - " << arraySongs[numberCurrentSong + 1] << std::endl;
			}
			break;
		}

		case 5:
		{
			std::string str;
			std::cout << "Input band name you are looking for: " << std::endl;
			std::getline(std::cin, str);
			bool search = false;
			for (int i = 0; i < realNumberSongs; ++i)
			{
				if (std::strcmp(str.c_str(), arrayGroups[i]) == 0)
				{
					std::cout << i + 1 << ") " << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
					search = true;
				}
			}

			if (search)
			{
				std::cout << "Now you can play any song by it position" << std::endl;
			}
			else
			{
				std::cout << "There are no pesny with band name like this " << str << std::endl;
			}

			break;
		}

		case 6:
		{
			std::string str2;
			std::cout << "Input song name you are looking for: " << std::endl;
			std::getline(std::cin, str2);
			bool search = false;
			for (int i = 0; i < realNumberSongs; ++i)
			{
				if (std::strcmp(str2.c_str(), arraySongs[i]) == 0)
				{
					std::cout << i + 1 << ") " << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
					search = true;
				}
			}

			if (search)
			{
				std::cout << "Now you can play any song by it position" << std::endl;
			}

			else
			{
				std::cout << "There are no pesny with name like this " << str2 << std::endl;
			}

			break;
		}

		case 7:
		{
			std::cout << "Playlist: " << std::endl;
			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
			}
			break;
		}

		case 8:
		{
			std::cout << "Ok, here is the playlist: " << std::endl;

			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << i + 1 << ") " << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
			}

			std::cout << "Enter song position, you want to play: " << std::endl;

			int songNumber;

			std::cin >> songNumber;

			std::cin.ignore();

			--songNumber;

			if (songNumber > -1 && songNumber < realNumberSongs)
			{
				numberCurrentSong = songNumber;
				++popularSongs[numberCurrentSong];
			}

			std::cout << "Now playing: " <<
				arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;

			if (numberCurrentSong > 0)
			{
				std::cout << "Previous song: " <<
					arrayGroups[numberCurrentSong - 1] << " - " << arraySongs[numberCurrentSong - 1] << std::endl;
			}

			if (numberCurrentSong < realNumberSongs - 1)
			{
				std::cout << "Next song: " <<
					arrayGroups[numberCurrentSong + 1] << " - " << arraySongs[numberCurrentSong + 1] << std::endl;
			}

			break;
		}

		case 9:
		{
			std::cout << "Now playing: " <<
				arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;
			break;
		}

		case 10:
		{
			for (int i = 0; i < realNumberSongs; ++i)
			{
				songsInTheTop[i] = arraySongs[i];
				groupInTheTop[i] = arrayGroups[i];
				popularSongsInTheTop[i] = popularSongs[i];
			}

			for (int i = 1; i < realNumberSongs; ++i)
			{
				const char* temporaryNameSong = songsInTheTop[i];
				const char* temporaryNameGroup = groupInTheTop[i];
				int popularTemporarySong = popularSongsInTheTop[i];

				int j = i - 1;
				while (j > -1 && popularSongsInTheTop[j] < popularTemporarySong)
				{
					songsInTheTop[j + 1] = songsInTheTop[j];
					groupInTheTop[j + 1] = groupInTheTop[j];
					popularSongsInTheTop[j + 1] = popularSongsInTheTop[j];
					--j;
				}

				songsInTheTop[j + 1] = temporaryNameSong;
				groupInTheTop[j + 1] = temporaryNameGroup;
				popularSongsInTheTop[j + 1] = popularTemporarySong;
			}

			std::cout << "Chart: " << std::endl;

			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << (i + 1) << ") " << groupInTheTop[i] << " - " << songsInTheTop[i] << std::endl;
			}

			break;
		}

		case 11:
		{
			const char* currentSongName = arraySongs[numberCurrentSong];
			const char* currentBandName = arrayGroups[numberCurrentSong];
			int currentSongPopularity = popularSongs[numberCurrentSong];

			for (int i = 1; i < realNumberSongs; ++i)
			{
				const char* temporaryNameSong = arraySongs[i];
				const char* temporaryNameGroup = arrayGroups[i];
				int popularTemporarySong = popularSongs[i];

				int j = i - 1;
				while (j > -1 && popularSongs[j] < popularTemporarySong)
				{
					arraySongs[j + 1] = arraySongs[j];
					arrayGroups[j + 1] = arrayGroups[j];
					popularSongs[j + 1] = popularSongs[j];
					--j;
				}


				arraySongs[j + 1] = temporaryNameSong;
				arrayGroups[j + 1] = temporaryNameGroup;
				popularSongs[j + 1] = popularTemporarySong;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realNumberSongs; ++i)
			{
				std::cout << arrayGroups[i] << " - " << arraySongs[i] << std::endl;
			}

			for (int i = 0; i < realNumberSongs; ++i)
			{
				if (std::strcmp(currentBandName, arrayGroups[i]) == 0
					&& std::strcmp(currentSongName, arraySongs[i]) == 0)
				{
					numberCurrentSong = i;
					break;
				}
			}

			std::cout << "Now playing: " << arrayGroups[numberCurrentSong] << " - " << arraySongs[numberCurrentSong] << std::endl;

			std::cout << "Song, you are listening on " << numberCurrentSong + 1 << " position of chart" << std::endl;
			break;
		}


		case 12:
		{
			for (int i = 0; i < realNumberSongs; ++i)
			{
				songsInTheTop[i] = arraySongs[i];
				groupInTheTop[i] = arrayGroups[i];
				popularSongsInTheTop[i] = popularSongs[i];
			}

			for (int i = 1; i < realNumberSongs; ++i)
			{
				const char* temp1 = songsInTheTop[i]; const char* temp2 = groupInTheTop[i];
				int temp3 = popularSongsInTheTop[i];

				int j = i - 1;
				while (j > -1 && popularSongsInTheTop[j] < temp3)
				{
					songsInTheTop[j + 1] = songsInTheTop[j];
					groupInTheTop[j + 1] = groupInTheTop[j];
					popularSongsInTheTop[j + 1] = popularSongsInTheTop[j];



					--j;
				}

				songsInTheTop[j + 1] = temp1;
				groupInTheTop[j + 1] = temp2;
				popularSongsInTheTop[j + 1] = temp3;
			}

			std::cout << "Most popular band is: " << groupInTheTop[0] << std::endl;
			break;
		}

		case 13:
		{
			ContinueWork = false;
			break;
		}

		default:
			std::cout << "Unknown command." << std::endl;
		}
	}

	std::cout << "Goodbye!" << std::endl;
}