#include <iostream>
#include <string>



int main() {
	const int COUNT_SONGS = 20;

	const char* array_songs[COUNT_SONGS];
	const char* array_bands[COUNT_SONGS];
	int popularity_of_songs[COUNT_SONGS];


	const char* TopSongs[COUNT_SONGS];
	const char* TopBands[COUNT_SONGS];
	int popularity_of_top_songs[COUNT_SONGS];

	int real_number_of_songs = 0;
	int number_of_actual_songs = 0;

	array_songs[0] = "Should I Stay or Should I Go";
	array_bands[0] = "The Clash";
	popularity_of_songs[0] = 0;

	array_songs[1] = "Baby don't lie to me";
	array_bands[1] = "The Fratellis";
	popularity_of_songs[1] = 0;

	array_songs[2] = "Ole Black 'n' Blue Eyes";
	array_bands[2] = "The Fratellis";
	popularity_of_songs[2] = 0;

	array_songs[3] = "Like A Champion";
	array_bands[3] = "The Baseballs";
	popularity_of_songs[3] = 0;

	array_songs[4] = "Jackie and Wilson";
	array_bands[4] = "Hoizer";
	popularity_of_songs[4] = 0;

	array_songs[5] = "Mountains";
	array_bands[5] = "Message To Bears";
	popularity_of_songs[5] = 0;

	array_songs[6] = "When It's Cold I'd Like to Die";
	array_bands[6] = "Moby";
	popularity_of_songs[6] = 0;

	array_songs[7] = "Damn Your Eyes";
	array_bands[7] = "Alex Clare";
	popularity_of_songs[7] = 0;

	array_songs[8] = "Heroes";
	array_bands[8] = "David Bowie";
	popularity_of_songs[8] = 0;

	array_songs[9] = "No Diggity";
	array_bands[9] = "Chet Faker";
	popularity_of_songs[9] = 0;

	array_songs[10] = "Inhaler";
	array_bands[10] = "Foals";
	popularity_of_songs[10] = 0;

	array_songs[11] = "London Thunder";
	array_bands[11] = "Foals";
	popularity_of_songs[11] = 0;

	array_songs[12] = "Spanish Sahara";
	array_bands[12] = "Foals";
	popularity_of_songs[12] = 0;

	array_songs[13] = "Asleep";
	array_bands[13] = "The Smiths";
	popularity_of_songs[13] = 0;

	real_number_of_songs = 14;

	bool continueWork = true;

	while (continueWork) {
		int choice = -1;

		std::cout << std::endl << "Now playing: " <<
			array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;

		if (number_of_actual_songs > 0) {
			std::cout << "Previous song: " <<
				array_bands[number_of_actual_songs - 1] << " - " << array_songs[number_of_actual_songs - 1] << std::endl;
		}

		if (number_of_actual_songs <real_number_of_songs - 1) {
			std::cout << "Next song: " <<
				array_bands[number_of_actual_songs + 1] << " - " << array_songs[number_of_actual_songs + 1] << std::endl;
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

		std::cin >> choice;

		std::cin.ignore();

		switch (choice) {
		case 1: {
			if (number_of_actual_songs != real_number_of_songs - 1) {
				++number_of_actual_songs;
				++popularity_of_songs[number_of_actual_songs];
			}
			break;
		}

		case 2: {
			if (number_of_actual_songs > 0)
			{
				--number_of_actual_songs;
				++popularity_of_songs[number_of_actual_songs];
			}
			break;
		}

		case 3: {
			const char* ar_s = array_songs[number_of_actual_songs]; // массив по песням (array_song - ar_s)
			const char* ar_b = array_bands[number_of_actual_songs]; // также по группам
			int actualPopularity = popularity_of_songs[number_of_actual_songs];


			for (int i = 1; i < real_number_of_songs; ++i)
			{
				const char* for_ar_s = array_songs[i]; // ar_s в цикле
				const char* for_ar_b = array_bands[i]; // ar_b в цикле
				int variable = popularity_of_songs[i];

				int j = i - 1;
				while (j> -1 && std::strcmp(for_ar_b, array_bands[j]) != 0) {
					array_songs[j + 1] = array_songs[j];
					array_bands[j + 1] = array_bands[j];
					popularity_of_songs[j + 1] = popularity_of_songs[j];
					--j;
				}

				array_songs[j + 1] = for_ar_s;
				array_bands[j + 1] = for_ar_b;
				popularity_of_songs[j + 1] = variable;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << array_bands[i] << " - " << array_songs[i] << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i) {
				if (std::strcmp(ar_b, array_bands[i]) == 0
					&& std::strcmp(ar_s, array_songs[i]) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_of_actual_songs + 1 << std::endl;

			std::cout << "Now playing: " <<
				array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;

			if (number_of_actual_songs > 0) {
				std::cout << "Previous song: " <<
					array_bands[number_of_actual_songs - 1] << " - " << array_songs[number_of_actual_songs - 1] << std::endl;
			}

			if (number_of_actual_songs < real_number_of_songs - 1) {
				std::cout << "Next song: " <<
					array_bands[number_of_actual_songs + 1] << " - " << array_songs[number_of_actual_songs + 1] << std::endl;
			}
			break;
		}

		case 4: {
			const char* nameActualSong = array_songs[number_of_actual_songs];
			const char* nameActualBand = array_bands[number_of_actual_songs];
			int popularity_actual_band = popularity_of_songs[number_of_actual_songs];

			for (int i = 1; i<real_number_of_songs; ++i) {
				const char* tempNameOfSong = array_songs[i];
				const char* tempNameOfBand = array_bands[i];
				int popularity_of_temp_song = popularity_of_songs[i];

				int j = i - 1;
				while (j >-1 && std::strcmp(tempNameOfSong, array_songs[j]) != 0) {
					array_songs[j + 1] = array_songs[j];
					array_bands[j + 1] = array_bands[j];
					popularity_of_songs[j + 1] = popularity_of_songs[j];
					--j;
				}


				array_songs[j + 1] = tempNameOfSong;
				array_bands[j + 1] = tempNameOfBand;
				popularity_of_songs[j + 1] = popularity_of_temp_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i<real_number_of_songs; ++i)
			{
				std::cout << array_bands[i] << " - " << array_songs[i] << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i) {
				if (std::strcmp(nameActualBand, array_bands[i]) == 0
					&& std::strcmp(nameActualSong, array_songs[i]) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_of_actual_songs << std::endl;

			std::cout << "Now playing: " <<
				array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;

			if (number_of_actual_songs > 0) {
				std::cout << "Previous song: " <<
					array_bands[number_of_actual_songs - 1] << " - " << array_songs[number_of_actual_songs - 1] << std::endl;
			}

			if (number_of_actual_songs < real_number_of_songs - 1) {
				std::cout << "Next song: " <<
					array_bands[number_of_actual_songs + 1] << " - " << array_songs[number_of_actual_songs + 1] << std::endl;
			}
			break;
		}

		case 5: {
			std::string str;
			std::cout << "Input band name you are looking for: " << std::endl;
			std::getline(std::cin, str);
			bool found = false;
			for (int i = 0; i<real_number_of_songs; ++i) {
				if (std::strcmp(str.c_str(), array_bands[i]) == 0) {
					std::cout << i + 1 << ") " << array_bands[i] << " - " << array_songs[i] << std::endl;
					found = true;
				}
			}

			if (found) {
				std::cout << "Now you can play any song by it position" << std::endl;
			}
			else
			{
				std::cout << "There are no pesny with band name like this " << str << std::endl;
			}

			break;
		}

		case 6: {
			std::string str2;
			std::cout << "Input song name you are looking for: " << std::endl;
			std::getline(std::cin, str2);
			bool found = false;
			for (int i = 0; i < real_number_of_songs; ++i) {
				if (std::strcmp(str2.c_str(), array_songs[i]) == 0) {
					std::cout << i + 1 << ") " << array_bands[i] << " - " << array_songs[i] << std::endl;
					found = true;
				}
			}

			if (found)
			{
				std::cout << "Now you can play any song by it position" << std::endl;
			}

			else {
				std::cout << "There are no pesny with name like this " << str2 << std::endl;
			}

			break;
		}

		case 7: {
			std::cout << "Playlist: " << std::endl;
			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << array_bands[i] << " - " << array_songs[i] << std::endl;
			}
			break;
		}

		case 8: {
			std::cout << "Ok, here is the playlist: " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << i + 1 << ") " << array_bands[i] << " - " << array_songs[i] << std::endl;
			}

			std::cout << "Enter song position, you want to play: " << std::endl;

			int NumberSong;

			std::cin >> NumberSong;

			std::cin.ignore();

			--NumberSong;

			if (NumberSong > -1 && NumberSong<real_number_of_songs) {
				number_of_actual_songs = NumberSong;
				++popularity_of_songs[number_of_actual_songs];
			}

			std::cout << "Now playing: " <<
				array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;

			if (number_of_actual_songs > 0) {
				std::cout << "Previous song: " <<
					array_bands[number_of_actual_songs - 1] << " - " << array_songs[number_of_actual_songs - 1] << std::endl;
			}

			if (number_of_actual_songs<real_number_of_songs - 1) {
				std::cout << "Next song: " <<
					array_bands[number_of_actual_songs + 1] << " - " << array_songs[number_of_actual_songs + 1] << std::endl;
			}

			break;
		}

		case 9: {
			std::cout << "Now playing: " <<
				array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;
			break;
		}

		case 10: {
			for (int i = 0; i < real_number_of_songs; ++i) {
				TopSongs[i] = array_songs[i];
				TopBands[i] = array_bands[i];
				popularity_of_top_songs[i] = popularity_of_songs[i];
			}

			for (int i = 1; i< real_number_of_songs; ++i) {
				const char* tempNameOfSong = TopSongs[i];
				const char* tempNameOfBand = TopBands[i]; 
				int popularity_of_temp_song = popularity_of_top_songs[i];

				int j = i - 1;
				while (j > -1 && popularity_of_top_songs[j] < popularity_of_temp_song) {
					TopSongs[j + 1] = TopSongs[j];
					TopBands[j + 1] = TopBands[j];
					popularity_of_top_songs[j + 1] = popularity_of_top_songs[j];
					--j;
				}

				TopSongs[j + 1] = tempNameOfSong;
				TopBands[j + 1] = tempNameOfBand;
				popularity_of_top_songs[j + 1] = popularity_of_temp_song;
			}

			std::cout << "Chart: " << std::endl;

			for (int i = 0; i <real_number_of_songs; ++i) {
				std::cout << (i + 1) << ") " << TopBands[i] << " - " << TopSongs[i] << std::endl;
			}

			break;
		}

		case 11: {const char* currentSongName = array_songs[number_of_actual_songs];
			const char* currentBandName = array_bands[number_of_actual_songs];
			int currentSongPopularity = popularity_of_songs[number_of_actual_songs];

			for (int i = 1; i < real_number_of_songs; ++i) {
				const char* tempNameOfSong = array_songs[i];
				const char* tempNameOfBand = array_bands[i];
				int popularity_of_temp_song = popularity_of_songs[i];

				int j = i - 1;
				while (j > -1 && popularity_of_songs[j] < popularity_of_temp_song) {
					array_songs[j + 1] = array_songs[j];
					array_bands[j + 1] = array_bands[j];
					popularity_of_songs[j + 1] = popularity_of_songs[j];
					--j;
				}


				array_songs[j + 1] = tempNameOfSong;
				array_bands[j + 1] = tempNameOfBand;
				popularity_of_songs[j + 1] = popularity_of_temp_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << array_bands[i] << " - " << array_songs[i] << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i)
			{
				if (std::strcmp(currentBandName, array_bands[i]) == 0
					&& std::strcmp(currentSongName, array_songs[i]) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Now playing: " << array_bands[number_of_actual_songs] << " - " << array_songs[number_of_actual_songs] << std::endl;

			std::cout << "Song, you are listening on " << number_of_actual_songs + 1 << " position of chart" << std::endl;
			break;
		}


		case 12: {
			for (int i = 0; i < real_number_of_songs; ++i)
			{
				TopSongs[i] = array_songs[i];
				TopBands[i] = array_bands[i];
				popularity_of_top_songs[i] = popularity_of_songs[i];
			}

			for (int i = 1; i < real_number_of_songs; ++i) {
				const char* temp1 = TopSongs[i]; const char* temp2 = TopBands[i];
				int temp3 = popularity_of_top_songs[i];

				int j = i - 1;
				while (j > -1 && popularity_of_top_songs[j] < temp3)
				{
					TopSongs[j + 1] = TopSongs[j];
					TopBands[j + 1] = TopBands[j];
					popularity_of_top_songs[j + 1] = popularity_of_top_songs[j];



					--j;
				}

				TopSongs[j + 1] = temp1;
				TopBands[j + 1] = temp2;
				popularity_of_top_songs[j + 1] = temp3;
			}

			std::cout << "Most popular band is: " << TopBands[0] << std::endl;
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