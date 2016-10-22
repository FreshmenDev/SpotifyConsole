#include "stdafx.h"
#include <iostream>
#include <string>

// Переменные
const int Number_of_songs_all = 20;
int Popular_songs_in_the_top[Number_of_songs_all];
int Popular_songs[Number_of_songs_all];
int Actual_number_of_songs = 0;
int Number_of_the_current_song = 0;
int Selection = -1;
std::string An_array_of_songs[Number_of_songs_all];
std::string An_array_of_groups[Number_of_songs_all];
std::string The_songs_in_the_top[Number_of_songs_all];
std::string The_groups_in_the_top[Number_of_songs_all];

// Присваивание массивов
std::string An_array_of_songs[Number_of_songs_all] =
	{
		"Should I Stay or Should I Go",
		"Baby don't lie to me",
		"Ole Black 'n' Blue Eyes",
		"Like A Champion",
		"Jackie and Wilson",
		"Mountains",
		"When It's Cold I'd Like to Die",
		"Damn Your Eyes",
		"Heroes",
		"No Diggity",
		"Inhaler",
		"London Thunder",
		"Spanish Sahara",
		"Asleep"
	};


	int Popular_songs[Number_of_songs_all] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	std::string An_array_of_groups[Number_of_songs_all] =
	{
		"The Clash",
		"The Fratellis",
		"The Fratellis",
		"The Baseballs",
		"Hoizer",
		"Message To Bears",
		"Moby",
		"Alex Clare",
		"David Bowie",
		"Chet Faker",
		"Foals",
		"Foals",
		"Foals",
		"The Smiths",
	};

int Func_Continue_work(int Number_of_the_current_song)
{
		std::cout << std::endl << "Now playing: " << An_array_of_groups[Number_of_the_current_song]
			<< " - " << An_array_of_songs[Number_of_the_current_song] << std::endl;

		if (Number_of_the_current_song > 0)
		{
			std::cout << "Previous song: " << An_array_of_groups[Number_of_the_current_song - 1]
				<< " - " << An_array_of_songs[Number_of_the_current_song - 1] << std::endl;
		}

		if (Number_of_the_current_song < Actual_number_of_songs - 1)
		{
			std::cout << "Next song: " << An_array_of_groups[Number_of_the_current_song + 1] << " - " << An_array_of_songs[Number_of_the_current_song + 1] << std::endl;
		}
	return  0;
};





int main()
{
	Actual_number_of_songs = 14;
	bool Continue_work = true;
	while (Continue_work)
	{
		Func_Continue_work(Number_of_the_current_song);

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

		std::cin >> Selection;

		std::cin.ignore();
	}

	switch (Selection)
	{
	case 1:
	{
		if (Number_of_the_current_song != Actual_number_of_songs - 1)
		{
			++Number_of_the_current_song;
			++Popular_songs[Number_of_the_current_song];
		}
		break;
	}



	case 2:
	{
		if (Number_of_the_current_song > 0)
		{
			--Number_of_the_current_song;
			++Popular_songs[Number_of_the_current_song];
		}
		break;
	}



	case 3:
	{
		std::string TMP = An_array_of_songs[Number_of_the_current_song];
		std::string TMP2 = An_array_of_groups[Number_of_the_current_song];
		int Current_popularity = Popular_songs[Number_of_the_current_song];
		

		for (int i = 1; i < Actual_number_of_songs; ++i)
		{
			std::string tmp = An_array_of_songs[i];
			std::string temp = An_array_of_groups[i];
			int variable = Popular_songs[i];

			int j = i - 1;
			while (j> -1 && std::strcmp(temp.c_str(), An_array_of_groups[j].c_str()) != 0)
			{
				An_array_of_songs[j + 1] = An_array_of_songs[j];
				An_array_of_groups[j + 1] = An_array_of_groups[j];
				Popular_songs[j + 1] = Popular_songs[j];
				--j;
			}

			An_array_of_songs[j + 1] = tmp;
			An_array_of_groups[j + 1] = temp;
			Popular_songs[j + 1] = variable;
		}

		std::cout << "New playlist order " << std::endl;

		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			std::cout << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
		}


		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			if (std::strcmp(TMP2.c_str(), An_array_of_groups[i].c_str()) == 0 && std::strcmp(TMP.c_str(), An_array_of_songs[i].c_str()) == 0)
			{
				Number_of_the_current_song = i;
				break;
			}
		}

		std::cout << "Current song position: " << Number_of_the_current_song + 1 << std::endl;

		Func_Continue_work(Number_of_the_current_song);

		break;
	}

	case 4:
	{
		std::string The_name_of_the_current_song = An_array_of_songs[Number_of_the_current_song];
		std::string The_name_of_the_current_group = An_array_of_groups[Number_of_the_current_song];
		int The_popularity_of_the_current_group = Popular_songs[Number_of_the_current_song];

		for (int i = 1; i<Actual_number_of_songs; ++i)
		{
			std::string The_temporary_name_of_the_song = An_array_of_songs[i].c_str();
			std::string The_temporary_name_of_the_group = An_array_of_groups[i].c_str();
			int The_popularity_of_the_current_song = Popular_songs[i];

			int j = i - 1;
			while (j >-1 && std::strcmp(The_temporary_name_of_the_song.c_str(), An_array_of_songs[j].c_str()) != 0)
			{
				An_array_of_songs[j + 1] = An_array_of_songs[j];
				An_array_of_groups[j + 1] = An_array_of_groups[j];
				Popular_songs[j + 1] = Popular_songs[j];
				--j;
			}


			An_array_of_songs[j + 1] = The_temporary_name_of_the_song;
			An_array_of_groups[j + 1] = The_temporary_name_of_the_group;
			Popular_songs[j + 1] = The_popularity_of_the_current_song;
		}

		std::cout << "New playlist order " << std::endl;

		for (int i = 0; i<Actual_number_of_songs; ++i)
		{
			std::cout << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
		}

		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			if (std::strcmp(The_name_of_the_current_group.c_str(), An_array_of_groups[i].c_str()) == 0
				&& std::strcmp(The_name_of_the_current_song.c_str(), An_array_of_songs[i].c_str()) == 0)
			{
				Number_of_the_current_song = i;
				break;
			}
		}

		std::cout << "Current song position: " << Number_of_the_current_song << std::endl;

		Func_Continue_work(Number_of_the_current_song);

		break;
	}

	case 5:
	{
		std::string str;
		std::cout << "Input band name you are looking for: " << std::endl;
		std::getline(std::cin, str);
		bool Found = false;
		for (int i = 0; i<Actual_number_of_songs; ++i)
		{
			if (std::strcmp(str.c_str(), An_array_of_groups[i].c_str()) == 0)
			{
				std::cout << i + 1 << ") " << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
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
		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			if (std::strcmp(str2.c_str(), An_array_of_songs[i].c_str()) == 0)
			{
				std::cout << i + 1 << ") " << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
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
		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			std::cout << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
		}
		break;
	}

	case 8:
	{
		std::cout << "Ok, here is the playlist: " << std::endl;

		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			std::cout << i + 1 << ") " << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
		}

		std::cout << "Enter song position, you want to play: " << std::endl;

		int Number_song;

		std::cin >> Number_song;

		std::cin.ignore();

		--Number_song;

		if (Number_song > -1 && Number_song<Actual_number_of_songs)
		{
			Number_of_the_current_song = Number_song;
			++Popular_songs[Number_of_the_current_song];
		}

		Func_Continue_work(Number_of_the_current_song);

		break;
	}

	case 9:
	{
		std::cout << "Now playing: " << An_array_of_groups[Number_of_the_current_song]
			<< " - " << An_array_of_songs[Number_of_the_current_song] << std::endl;
		break;
	}

	case 10:
	{
		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			The_songs_in_the_top[i] = An_array_of_songs[i];
			The_groups_in_the_top[i] = An_array_of_groups[i];
			Popular_songs_in_the_top[i] = Popular_songs[i];
		}

		for (int i = 1; i< Actual_number_of_songs; ++i)
		{
			std::string The_temporary_name_of_the_song = The_songs_in_the_top[i];
			std::string The_temporary_name_of_the_group = The_groups_in_the_top[i];
			int The_popularity_of_the_song = Popular_songs_in_the_top[i];

			int j = i - 1;
			while (j > -1 && Popular_songs_in_the_top[j] < The_popularity_of_the_song)
			{
				The_songs_in_the_top[j + 1] = The_songs_in_the_top[j];
				The_groups_in_the_top[j + 1] = The_groups_in_the_top[j];
				Popular_songs_in_the_top[j + 1] = Popular_songs_in_the_top[j];
				--j;
			}

			The_songs_in_the_top[j + 1] = The_temporary_name_of_the_song;
			The_groups_in_the_top[j + 1] = The_temporary_name_of_the_group;
			Popular_songs_in_the_top[j + 1] = The_popularity_of_the_song;
		}

		std::cout << "Chart: " << std::endl;

		for (int i = 0; i <Actual_number_of_songs; ++i)
		{
			std::cout << (i + 1) << ") " << The_groups_in_the_top[i] << " - " << The_songs_in_the_top[i] << std::endl;
		}

		break;
	}

	case 11:
	{
		std::string Current_song_name = An_array_of_songs[Number_of_the_current_song];
		std::string Current_band_name = An_array_of_groups[Number_of_the_current_song];
		int Current_song_popularity = Popular_songs[Number_of_the_current_song];

		for (int i = 1; i < Actual_number_of_songs; ++i)
		{
			std::string The_temporary_name_of_the_song = An_array_of_songs[i];
			std::string The_temporary_name_of_the_group = An_array_of_groups[i];
			int The_popularity_of_the_song = Popular_songs[i];

			int j = i - 1;
			while (j > -1 && Popular_songs[j] < The_popularity_of_the_song)
			{
				An_array_of_songs[j + 1] = An_array_of_songs[j];
				An_array_of_groups[j + 1] = An_array_of_groups[j];
				Popular_songs[j + 1] = Popular_songs[j];
				--j;
			}


			An_array_of_songs[j + 1] = The_temporary_name_of_the_song;
			An_array_of_groups[j + 1] = The_temporary_name_of_the_group;
			Popular_songs[j + 1] = The_popularity_of_the_song;
		}

		std::cout << "New playlist order " << std::endl;

		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			std::cout << An_array_of_groups[i] << " - " << An_array_of_songs[i] << std::endl;
		}

		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			if (std::strcmp(Current_band_name.c_str(), An_array_of_groups[i].c_str()) == 0 && std::strcmp(Current_song_name.c_str(), An_array_of_songs[i].c_str()) == 0)
			{
				Number_of_the_current_song = i;
				break;
			}
		}

		std::cout << "Now playing: " << An_array_of_groups[Number_of_the_current_song] << " - " << An_array_of_songs[Number_of_the_current_song] << std::endl;

		std::cout << "Song, you are listening on " << Number_of_the_current_song + 1 << " position of chart" << std::endl;
		break;
	}


	case 12:
	{
		for (int i = 0; i < Actual_number_of_songs; ++i)
		{
			The_songs_in_the_top[i] = An_array_of_songs[i];
			The_groups_in_the_top[i] = An_array_of_groups[i];
			Popular_songs_in_the_top[i] = Popular_songs[i];
		}

		for (int i = 1; i < Actual_number_of_songs; ++i)
		{
			std::string temp1 = The_songs_in_the_top[i];
			std::string temp2 = The_groups_in_the_top[i];
			int temp3 = Popular_songs_in_the_top[i];

			int j = i - 1;
			while (j > -1 && Popular_songs_in_the_top[j] < temp3)
			{
				The_songs_in_the_top[j + 1] = The_songs_in_the_top[j];
				The_groups_in_the_top[j + 1] = The_groups_in_the_top[j];
				Popular_songs_in_the_top[j + 1] = Popular_songs_in_the_top[j];
				--j;
			}

			The_songs_in_the_top[j + 1] = temp1;
			The_groups_in_the_top[j + 1] = temp2;
			Popular_songs_in_the_top[j + 1] = temp3;
		}

		std::cout << "Most popular band is: " << The_groups_in_the_top[0] << std::endl;
		break;
	}

	case 13:
	{
		Continue_work = false;
		break;
	}

	default:
		std::cout << "Unknown command." << std::endl;
	}

	std::cout << "Goodbye!" << std::endl;
}
