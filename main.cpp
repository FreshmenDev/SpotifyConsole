#include <iostream>
#include <string>

// Переменные
const int number_songs_all = 20;
int popular_songs_in_top[number_songs_all];
int actual_number_songs = 0;
int number_current_song = 0;
int selection = -1;
std::string songs_in_top[number_songs_all];
std::string groups_in_top[number_songs_all];


// Структура и двумерный массив
struct alls_song
{
	std::string song;
	std::string group;
	int popularity;
};

alls_song array[number_songs_all] =
{
	{ "Should I Stay or Should I Go","The Clash",0},
	{ "Baby don't lie to me","The Fratellis",0},
	{ "Ole Black 'n' Blue Eyes","The Fratellis",0},
	{ "Like A Champion","The Baseballs",0},
	{ "Jackie and Wilson","Hoizer",0},
	{ "Mountains","Message To Bears",0},
	{ "When It's Cold I'd Like to Die","Moby",0},
	{ "Damn Your Eyes","Alex Clare",0},
	{ "Heroes","David Bowie",0},
	{ "No Diggity","Chet Faker",0},
	{ "Inhaler","Foals",0},
	{ "London Thunder","Foals",0},
	{ "Spanish Sahara","Foals",0},
	{ "Asleep","The Smiths",0}

};
// Функции

int Func_continue_work()
{
	std::cout << std::endl << "Now playing: " << array[number_current_song].group
		<< " - " << array[number_current_song].song << std::endl;

	if (number_current_song > 0)
	{
		std::cout << "Previous song: " << array[number_current_song - 1].group
			<< " - " << array[number_current_song - 1].song << std::endl;
	}

	if (number_current_song < actual_number_songs - 1)
	{
		std::cout << "Next song: " << array[number_current_song + 1].group << " - " << array[number_current_song + 1].song << std::endl;
	}
	return  0;
};

int Func_menu() 
{
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

	return 0;
};





int main()
{
	actual_number_songs = 14;
	bool continue_work = true;
	while (continue_work)
	{
		Func_continue_work();

		Func_menu();

		std::cin >> selection;

		std::cin.ignore();


		switch (selection)
		{
		case 1:
		{
			if (number_current_song != actual_number_songs - 1)
			{
				++number_current_song;
				++array[number_current_song].popularity;
			}
			break;
		}



		case 2:
		{
			if (number_current_song > 0)
			{
				--number_current_song;
				++array[number_current_song].popularity;
			}
			break;
		}



		case 3:
		{
			std::string TMP = array[number_current_song].song;
			std::string TMP2 = array[number_current_song].group;
			int current_popularity = array[number_current_song].popularity;


			for (int i = 1; i < actual_number_songs; ++i)
			{
				std::string tmp = array[i].song;
				std::string temp = array[i].group;
				int variable = array[i].popularity;

				int j = i - 1;
				while (j> -1 && std::strcmp(temp.c_str(), array[j].group.c_str()) != 0)
				{
					array[j + 1].song = array[j].song;
					array[j + 1].group = array[j].group;
					array[j + 1].popularity = array[j].popularity;
					--j;
				}

				array[j + 1].song = tmp;
				array[j + 1].group = temp;
				array[j + 1].popularity = variable;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < actual_number_songs; ++i)
			{
				std::cout << array[i].group << " - " << array[i].song << std::endl;
			}


			for (int i = 0; i < actual_number_songs; ++i)
			{
				if (std::strcmp(TMP2.c_str(), array[i].group.c_str()) == 0 && std::strcmp(TMP.c_str(), array[i].song.c_str()) == 0)
				{
					number_current_song = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_current_song + 1 << std::endl;

			Func_continue_work();

			break;
		}

		case 4:
		{
			std::string name_current_song = array[number_current_song].song;
			std::string name_current_group = array[number_current_song].group;
			int popularity_current_group = array[number_current_song].popularity;

			for (int i = 1; i<actual_number_songs; ++i)
			{
				std::string temporary_name_song = array[i].song.c_str();
				std::string temporary_name_group = array[i].group.c_str();
				int popularity_current_song = array[i].popularity;

				int j = i - 1;
				while (j >-1 && std::strcmp(temporary_name_song.c_str(), array[j].song.c_str()) != 0)
				{
					array[j + 1].song = array[j].song;
					array[j + 1].group = array[j].group;
					array[j + 1].popularity = array[j].popularity;
					--j;
				}


				array[j + 1].song = temporary_name_song;
				array[j + 1].group = temporary_name_group;
				array[j + 1].popularity = popularity_current_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i<actual_number_songs; ++i)
			{
				std::cout << array[i].group << " - " << array[i].song << std::endl;
			}

			for (int i = 0; i < actual_number_songs; ++i)
			{
				if (std::strcmp(name_current_group.c_str(), array[i].group.c_str()) == 0
					&& std::strcmp(name_current_song.c_str(), array[i].song.c_str()) == 0)
				{
					number_current_song = i;
					break;
				}
			}

			std::cout << "Current song position: " << number_current_song << std::endl;

			Func_continue_work();

			break;
		}

		case 5:
		{
			std::string str;
			std::cout << "Input band name you are looking for: " << std::endl;
			std::getline(std::cin, str);
			bool Found = false;
			for (int i = 0; i<actual_number_songs; ++i)
			{
				if (std::strcmp(str.c_str(), array[i].group.c_str()) == 0)
				{
					std::cout << i + 1 << ") " << array[i].group << " - " << array[i].song << std::endl;
					Found = true;
				}
			}

			if (Found)
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
			bool Found = false;
			for (int i = 0; i < actual_number_songs; ++i)
			{
				if (std::strcmp(str2.c_str(), array[i].song.c_str()) == 0)
				{
					std::cout << i + 1 << ") " << array[i].group << " - " << array[i].song << std::endl;
					Found = true;
				}
			}

			if (Found)
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
			for (int i = 0; i < actual_number_songs; ++i)
			{
				std::cout << array[i].group << " - " << array[i].song << std::endl;
			}
			break;
		}

		case 8:
		{
			std::cout << "Ok, here is the playlist: " << std::endl;

			for (int i = 0; i < actual_number_songs; ++i)
			{
				std::cout << i + 1 << ") " << array[i].group << " - " << array[i].song << std::endl;
			}

			std::cout << "Enter song position, you want to play: " << std::endl;

			int Number_song;

			std::cin >> Number_song;

			std::cin.ignore();

			--Number_song;

			if (Number_song > -1 && Number_song<actual_number_songs)
			{
				number_current_song = Number_song;
				++array[number_current_song].popularity;
			}

			Func_continue_work();

			break;
		}

		case 9:
		{
			std::cout << "Now playing: " << array[number_current_song].group
				<< " - " << array[number_current_song].song << std::endl;
			break;
		}

		case 10:
		{
			for (int i = 0; i < actual_number_songs; ++i)
			{
				songs_in_top[i] = array[i].song;
				groups_in_top[i] = array[i].group;
				popular_songs_in_top[i] = array[i].popularity;
			}

			for (int i = 1; i< actual_number_songs; ++i)
			{
				std::string temporary_name_song = songs_in_top[i];
				std::string temporary_name_group = groups_in_top[i];
				int popularity_song = popular_songs_in_top[i];

				int j = i - 1;
				while (j > -1 && popular_songs_in_top[j] < popularity_song)
				{
					songs_in_top[j + 1] = songs_in_top[j];
					groups_in_top[j + 1] = groups_in_top[j];
					popular_songs_in_top[j + 1] = popular_songs_in_top[j];
					--j;
				}

				songs_in_top[j + 1] = temporary_name_song;
				groups_in_top[j + 1] = temporary_name_group;
				popular_songs_in_top[j + 1] = popularity_song;
			}

			std::cout << "Chart: " << std::endl;

			for (int i = 0; i <actual_number_songs; ++i)
			{
				std::cout << (i + 1) << ") " << groups_in_top[i] << " - " << songs_in_top[i] << std::endl;
			}

			break;
		}

		case 11:
		{
			std::string current_song_name = array[number_current_song].song;
			std::string current_band_name = array[number_current_song].group;
			int current_song_popularity = array[number_current_song].popularity;

			for (int i = 1; i < actual_number_songs; ++i)
			{
				std::string temporary_name_song = array[i].song;
				std::string temporary_name_group = array[i].group;
				int popularity_song = array[i].popularity;

				int j = i - 1;
				while (j > -1 && array[j].popularity < popularity_song)
				{
					array[j + 1].song = array[j].song;
					array[j + 1].group = array[j].group;
					array[j + 1] = array[j];
					--j;
				}


				array[j + 1].song = temporary_name_song;
				array[j + 1].group = temporary_name_group;
				array[j + 1].popularity = popularity_song;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < actual_number_songs; ++i)
			{
				std::cout << array[i].group << " - " << array[i].song << std::endl;
			}

			for (int i = 0; i < actual_number_songs; ++i)
			{
				if (std::strcmp(current_band_name.c_str(), array[i].group.c_str()) == 0 && std::strcmp(current_song_name.c_str(), array[i].song.c_str()) == 0)
				{
					number_current_song = i;
					break;
				}
			}

			std::cout << "Now playing: " << array[number_current_song].group << " - " << array[number_current_song].song << std::endl;

			std::cout << "Song, you are listening on " << number_current_song + 1 << " position of chart" << std::endl;
			break;
		}


		case 12:
		{
			for (int i = 0; i < actual_number_songs; ++i)
			{
				songs_in_top[i] = array[i].song;
				groups_in_top[i] = array[i].group;
				popular_songs_in_top[i] = array[i].popularity;
			}

			for (int i = 1; i < actual_number_songs; ++i)
			{
				std::string temp1 = songs_in_top[i];
				std::string temp2 = groups_in_top[i];
				int temp3 = popular_songs_in_top[i];

				int j = i - 1;
				while (j > -1 && popular_songs_in_top[j] < temp3)
				{
					songs_in_top[j + 1] = songs_in_top[j];
					groups_in_top[j + 1] = groups_in_top[j];
					popular_songs_in_top[j + 1] = popular_songs_in_top[j];
					--j;
				}

				songs_in_top[j + 1] = temp1;
				groups_in_top[j + 1] = temp2;
				popular_songs_in_top[j + 1] = temp3;
			}

			std::cout << "Most popular band is: " << groups_in_top[0] << std::endl;
			break;
		}

		case 13:
		{
			continue_work = false;
			break;
		}

		default:
			std::cout << "Unknown command." << std::endl;
		}
	}
	std::cout << "Goodbye!" << std::endl;
}
