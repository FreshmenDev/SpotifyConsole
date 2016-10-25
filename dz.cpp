

#include <iostream>
#include <string>

struct Song
{
	char* song_name;
	char* band_name;
	int popularity_of_songs;

};

char* popularity_of_top_songs;
int real_number_of_songs = 0;
Song	songs[5];


void show_current_status(int position) {
	std::cout << "Now playing: " <<
		songs[position].band_name << " - " << songs[position].song_name << std::endl;

	if (position > 0) {
		std::cout << "Previous song: " <<
			songs[position - 1].band_name << " - " << songs[position - 1].song_name << std::endl;
	}

	if (position < real_number_of_songs - 1) {
		std::cout << "Next song: " <<
			songs[position + 1].band_name << " - " << songs[position + 1].song_name << std::endl;
	}
}
int main() {
	 const int COUNT_SONGS = 20;

	int number_of_actual_songs = 0;


	songs[0] = { "Should I Stay or Should I Go", "The Clash", 0 };
	songs[1] = { "Baby don't lie to me", "The Fratellis", 0 };
	songs[2] = { "Ole Black 'n' Blue Eyes", "he Fratellis", 0 };
	songs[3] = { "Like A Champion", "The Baseballs", 0 };
	songs[4] = { "Jackie and Wilson", "Hoizer", 0 };
	songs[5] = { "Mountains", "Message To Bears", 0 };
	songs[6] = { "When It's Cold I'd Like to Die", "Moby", 0 };
	songs[7] = { "Damn Your Eyes", "Alex Clare", 0 };
	songs[8] = { "Heroes", "David Bowie", 0 };
	songs[9] = { "No Diggity", "Chet Faker", 0 };
	songs[10] = { "Inhaler", "Foals", 0 };
        songs[11] = { "London Thunder", "Foals", 0 };
	songs[12] = { "Spanish Sahara", "Foals", 0 };
	songs[13] = { "Asleep", "The Smiths", 0 };
	
	 char* top_songs[COUNT_SONGS];
	 char* top_bands[COUNT_SONGS];

	real_number_of_songs = 14;

	bool continue_work = true;

	while (continue_work) {
		int choice = -1;

		show_current_status(number_of_actual_songs);


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
				++songs[number_of_actual_songs].popularity_of_songs;
			}
			break;
		}

		case 2: {
			if (number_of_actual_songs > 0)
			{
				--number_of_actual_songs;
				++songs[number_of_actual_songs].popularity_of_songs;
			}
			break;
		}

		case 3: {
			char* ar_s = songs[number_of_actual_songs].song_name; // массив по песням (array_song - ar_s)
			char* ar_b = songs[number_of_actual_songs].band_name; // также по группам
			int actualPopularity = songs[number_of_actual_songs].popularity_of_songs;


			for (int i = 1; i < real_number_of_songs; ++i)
			{
				char* temp_ar_s = songs[i].song_name;
				char* temp_ar_b = songs[i].band_name; 
				int variable = songs[i].popularity_of_songs;

				int j = i - 1;
				while (j> -1 && std::strcmp(temp_ar_b, songs[j].band_name) != 0) {
					songs[j + 1].song_name = songs[j].song_name;
					songs[j + 1].band_name = songs[j].band_name;
					songs[j + 1].popularity_of_songs = songs[j].popularity_of_songs;
					--j;
				}

				songs[j + 1].song_name = temp_ar_s;
				songs[j + 1].band_name = temp_ar_b;
				songs[j + 1].popularity_of_songs = variable;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << songs[i].band_name << " - " << songs[i].song_name << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i) {
				if (std::strcmp(ar_b, songs[i].band_name) == 0
					&& std::strcmp(ar_s, songs[i].song_name) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_of_actual_songs + 1 << std::endl;

			show_current_status(number_of_actual_songs);
			break;
		}

		case 4: {
			 char* name_actual_song = songs[number_of_actual_songs].song_name;
			 char* name_actual_band = songs[number_of_actual_songs].band_name;
			int popularity_actual_band = songs[number_of_actual_songs].popularity_of_songs;

			for (int i = 1; i<real_number_of_songs; ++i) {
				char* temp_name_of_song = songs[i].song_name;
				char* temp_name_of_band = songs[i].band_name;
				int popularity_of_temp_song = songs[i].popularity_of_songs;

				int j = i - 1;
				while (j >-1 && std::strcmp(temp_name_of_song, songs[j].song_name) != 0) {
					songs[j + 1].song_name = songs[j].song_name;
					songs[j+1].band_name = songs[j].band_name;
					songs[j + 1].popularity_of_songs = songs[j].popularity_of_songs;
					--j;
				}


			    songs[j + 1].song_name = temp_name_of_song;
				songs[j + 1].band_name = temp_name_of_band;
				songs[j + 1].popularity_of_songs = popularity_of_temp_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i<real_number_of_songs; ++i)
			{
				std::cout << songs[i].band_name << " - " << songs[i].song_name << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i) {
				if (std::strcmp(name_actual_band, songs[i].band_name) == 0
					&& std::strcmp(name_actual_song, songs[i].song_name) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_of_actual_songs << std::endl;

			
			break;
		}

		case 5: {
			std::string str;
			std::cout << "Input band name you are looking for: " << std::endl;
			std::getline(std::cin, str);
			bool found = false;
			for (int i = 0; i<real_number_of_songs; ++i) {
				if (std::strcmp(str.c_str(), songs[i].band_name) == 0) {
					std::cout << i + 1 << ") " << songs[i].band_name << " - " << songs[i].song_name << std::endl;
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
				if (std::strcmp(str2.c_str(), songs[i].song_name) == 0) {
					std::cout << i + 1 << ") " << songs[i].band_name << " - " << songs[i].song_name << std::endl;
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
				std::cout << songs[i].band_name << " - " << songs[i].song_name << std::endl;
			}
			break;
		}

		case 8: {
			std::cout << "Ok, here is the playlist: " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << i + 1 << ") " << songs[i].band_name << " - " << songs[i].song_name << std::endl;
			}

			std::cout << "Enter song position, you want to play: " << std::endl;

			int number_song;

			std::cin >> number_song;

			std::cin.ignore();

			--number_song;

			if (number_song > -1 && number_song<real_number_of_songs) {
				number_of_actual_songs = number_song;
				++songs[number_of_actual_songs].popularity_of_songs;
			}

			std::cout << "Now playing: " <<
				songs[number_of_actual_songs].band_name << " - " << songs[number_of_actual_songs].song_name << std::endl;

			if (number_of_actual_songs > 0) {
				std::cout << "Previous song: " <<
					songs[number_of_actual_songs - 1].band_name << " - " << songs[number_of_actual_songs - 1].song_name << std::endl;
			}

			if (number_of_actual_songs<real_number_of_songs - 1) {
				std::cout << "Next song: " <<
					songs[number_of_actual_songs + 1].band_name << " - " << songs[number_of_actual_songs + 1].song_name << std::endl;
			}

			break;
		}

		case 9: {
			std::cout << "Now playing: " <<
				songs[number_of_actual_songs].band_name << " - " << songs[number_of_actual_songs].song_name << std::endl;
			break;
		}

		case 10: {
			
			for (int i = 0; i < real_number_of_songs; ++i) {
				top_songs[i] = songs[i].song_name;
				top_bands[i] = songs[i].band_name;
				popularity_of_top_songs[i] = songs[i].popularity_of_songs;
			}

			for (int i = 1; i< real_number_of_songs; ++i) {
				 char* temp_name_of_song = top_songs[i];
				 char* temp_name_of_band = top_bands[i];
				int popularity_of_temp_song = popularity_of_top_songs[i];

				int j = i - 1;
				while (j > -1 && popularity_of_top_songs[j] < popularity_of_temp_song) {
					top_songs[j + 1] = top_songs[j];
					top_bands[j + 1] = top_bands[j];
					popularity_of_top_songs[j + 1] = popularity_of_top_songs[j];
					--j;
				}

				top_songs[j + 1] = temp_name_of_song;
				top_bands[j + 1] = temp_name_of_band;
				popularity_of_top_songs[j + 1] = popularity_of_temp_song;
			}

			std::cout << "Chart: " << std::endl;

			for (int i = 0; i <real_number_of_songs; ++i) {
				std::cout << (i + 1) << ") " << top_bands[i] << " - " << top_songs[i] << std::endl;
			}

			break;
		}

		case 11: { char* current_song_name = songs[number_of_actual_songs].song_name;
			 char* currentBandName = songs[number_of_actual_songs].band_name;
			int currentSongPopularity = songs[number_of_actual_songs].popularity_of_songs;

			for (int i = 1; i < real_number_of_songs; ++i) {
				 char* temp_name_of_song = songs[i].song_name;
				 char* temp_name_of_band = songs[i].band_name;
				int popularity_of_temp_song = songs[i].popularity_of_songs;

				int j = i - 1;
				while (j > -1 && songs[j].popularity_of_songs < popularity_of_temp_song) {
					songs[j+1].song_name = songs[j].song_name;
					songs[j+1].band_name = songs[j].band_name;
					songs[j+1].popularity_of_songs = songs[j].popularity_of_songs;
					--j;
				}


				songs[j+1].song_name = temp_name_of_song;
				songs[j+1].band_name = temp_name_of_band;
				songs[j+1].popularity_of_songs = popularity_of_temp_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < real_number_of_songs; ++i) {
				std::cout << songs[i].band_name << " - " << songs[i].song_name << std::endl;
			}

			for (int i = 0; i < real_number_of_songs; ++i)
			{
				if (std::strcmp(currentBandName, songs[i].band_name) == 0
					&& std::strcmp(current_song_name, songs[i].song_name) == 0) {
					number_of_actual_songs = i;
					break;
				}
			}

			std::cout << "Now playing: " << songs[number_of_actual_songs].band_name << " - " << songs[number_of_actual_songs].song_name << std::endl;

			std::cout << "Song, you are listening on " << number_of_actual_songs + 1 << " position of chart" << std::endl;
			break;
		}


		case 12: {
			
			for (int i = 0; i < real_number_of_songs; ++i)
			{
				top_songs[i] = songs[i].song_name;
				top_bands[i] = songs[i].band_name;
				popularity_of_top_songs[i] = songs[i].popularity_of_songs;
			}

			for (int i = 1; i < real_number_of_songs; ++i) {
				 char* current_song = top_songs[i];
				 char* current_band = top_bands[i];
				int current_popularity = popularity_of_top_songs[i];

				int j = i - 1;
				while (j > -1 && popularity_of_top_songs[j] < current_popularity)
				{
					top_songs[j + 1] = top_songs[j];
					top_bands[j + 1] = top_bands[j];
					popularity_of_top_songs[j + 1] = popularity_of_top_songs[j];



					--j;
				}

				top_songs[j + 1] = current_song;
				top_bands[j + 1] = current_band;
				popularity_of_top_songs[j + 1] = current_popularity;
			}

			std::cout << "Most popular band is: " << top_bands[0] << std::endl;
			break;
		}

		case 13: {
			continue_work = false;
			break;
		}

		default:
			std::cout << "Unknown command." << std::endl;
		}
	}

	std::cout << "Goodbye!" << std::endl;
}

