#include <iostream>
#include <string>

int main()
{
	const int KOLICHESTVO_PESEN_VSEGO = 20;
	struct information {
		const char* massiv_pesen;
		const char* massivGrupp;
		int popularnost_pesen;
	};

	const char* pesny_VTope[KOLICHESTVO_PESEN_VSEGO];
	const char* gruppy_v_tope[KOLICHESTVO_PESEN_VSEGO];
	int popularnost_pesen_v_tope[KOLICHESTVO_PESEN_VSEGO];

	int realnoe_kolichestvo_pesen = 0;
	int nomerTeckusheyPensy = 0;

	information information_track[KOLICHESTVO_PESEN_VSEGO];
	information_track[0].massiv_pesen = "Should I Stay or Should I Go";
	information_track[0].massivGrupp = "The Clash";
	information_track[0].popularnost_pesen = 0;

	information_track[1].massiv_pesen = "Baby don't lie to me";
	information_track[1].massivGrupp = "The Fratellis";
	information_track[1].popularnost_pesen = 0;

	information_track[2].massiv_pesen = "Ole Black 'n' Blue Eyes";
	information_track[2].massivGrupp = "The Fratellis";
	information_track[2].popularnost_pesen = 0;

	information_track[3].massiv_pesen = "Like A Champion";
	information_track[3].massivGrupp = "The Baseballs";
	information_track[3].popularnost_pesen = 0;

	information_track[4].massiv_pesen = "Jackie and Wilson";
	information_track[4].massivGrupp = "Hoizer";
	information_track[4].popularnost_pesen = 0;

	information_track[5].massiv_pesen = "Mountains";
	information_track[5].massivGrupp = "Message To Bears";
	information_track[5].popularnost_pesen = 0;

	information_track[6].massiv_pesen = "When It's Cold I'd Like to Die";
	information_track[6].massivGrupp = "Moby";
	information_track[6].popularnost_pesen = 0;

	information_track[7].massiv_pesen = "Damn Your Eyes";
	information_track[7].massivGrupp = "Alex Clare";
	information_track[7].popularnost_pesen = 0;

	information_track[8].massiv_pesen = "Heroes";
	information_track[8].massivGrupp = "David Bowie";
	information_track[8].popularnost_pesen = 0;

	information_track[9].massiv_pesen = "No Diggity";
	information_track[9].massivGrupp = "Chet Faker";
	information_track[9].popularnost_pesen = 0;

	information_track[10].massiv_pesen = "Inhaler";
	information_track[10].massivGrupp = "Foals";
	information_track[10].popularnost_pesen = 0;

	information_track[11].massiv_pesen = "London Thunder";
	information_track[11].massivGrupp = "Foals";
	information_track[11].popularnost_pesen = 0;

	information_track[12].massiv_pesen = "Spanish Sahara";
	information_track[12].massivGrupp = "Foals";
	information_track[12].popularnost_pesen = 0;

	information_track[13].massiv_pesen = "Asleep";
	information_track[13].massivGrupp = "The Smiths";
	information_track[13].popularnost_pesen = 0;

	realnoe_kolichestvo_pesen = 14;

	bool prodolgitRabotu = true;

	while (prodolgitRabotu)
	{
		int vybor = -1;

		std::cout << std::endl << "Now playing: " <<
			massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

		if (nomerTeckusheyPensy > 0)
		{
			std::cout << "Previous song: " <<
				massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
		}

		if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1)
		{
			std::cout << "Next song: " <<
				massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
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

		std::cin >> vybor;

		std::cin.ignore();

		switch (vybor)
		{
		case 1:
		{
			if (nomerTeckusheyPensy != realnoe_kolichestvo_pesen - 1)
			{
				++nomerTeckusheyPensy;
				++popularnost_pesen[nomerTeckusheyPensy];
			}
			break;
		}

		case 2:
		{
			if (nomerTeckusheyPensy > 0)
			{
				--nomerTeckusheyPensy;
				++popularnost_pesen[nomerTeckusheyPensy];
			}
			break;
		}

		case 3:
		{
			const char* TMP = massiv_pesen[nomerTeckusheyPensy];
			const char* TMP2 = massivGrupp[nomerTeckusheyPensy];
			int tekushayPopularnost = popularnost_pesen[nomerTeckusheyPensy];


			for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
			{
				const char* tmp = massiv_pesen[i];
				const char* temp = massivGrupp[i];
				int variable = popularnost_pesen[i];

				int j = i - 1;
				while (j > -1 && std::strcmp(temp, massivGrupp[j]) != 0)
				{
					massiv_pesen[j + 1] = massiv_pesen[j];
					massivGrupp[j + 1] = massivGrupp[j];
					popularnost_pesen[j + 1] = popularnost_pesen[j];
					--j;
				}

				massiv_pesen[j + 1] = tmp;
				massivGrupp[j + 1] = temp;
				popularnost_pesen[j + 1] = variable;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
			}

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				if (std::strcmp(TMP2, massivGrupp[i]) == 0
					&& std::strcmp(TMP, massiv_pesen[i]) == 0)
				{
					nomerTeckusheyPensy = i;
					break;
				}
			}

			std::cout << "Current song position: " << nomerTeckusheyPensy + 1 << std::endl;

			std::cout << "Now playing: " <<
				massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

			if (nomerTeckusheyPensy > 0)
			{
				std::cout << "Previous song: " <<
					massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
			}

			if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1)
			{
				std::cout << "Next song: " <<
					massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
			}
			break;
		}

		case 4:
		{
			const char* nazvanieTekusheyPesny = massiv_pesen[nomerTeckusheyPensy];
			const char* nazvanieTekusheyGruppy = massivGrupp[nomerTeckusheyPensy];
			int popularnost_tekushey_Gruppy = popularnost_pesen[nomerTeckusheyPensy];

			for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
			{
				const char* vremenoeNazvanyePesny = massiv_pesen[i];
				const char* vremenoeNazvanyeGruppy = massivGrupp[i];
				int popularnostVremennoyPesny = popularnost_pesen[i];

				int j = i - 1;
				while (j > -1 && std::strcmp(vremenoeNazvanyePesny, massiv_pesen[j]) != 0)
				{
					massiv_pesen[j + 1] = massiv_pesen[j];
					massivGrupp[j + 1] = massivGrupp[j];
					popularnost_pesen[j + 1] = popularnost_pesen[j];
					--j;
				}


				massiv_pesen[j + 1] = vremenoeNazvanyePesny;
				massivGrupp[j + 1] = vremenoeNazvanyeGruppy;
				popularnost_pesen[j + 1] = popularnostVremennoyPesny;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
			}

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				if (std::strcmp(nazvanieTekusheyGruppy, massivGrupp[i]) == 0
					&& std::strcmp(nazvanieTekusheyPesny, massiv_pesen[i]) == 0)
				{
					nomerTeckusheyPensy = i;
					break;
				}
			}

			std::cout << "Current song position: " << nomerTeckusheyPensy << std::endl;

			std::cout << "Now playing: " <<
				massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

			if (nomerTeckusheyPensy > 0)
			{
				std::cout << "Previous song: " <<
					massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
			}

			if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1)
			{
				std::cout << "Next song: " <<
					massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
			}
			break;
		}

		case 5:
		{
			std::string str;
			std::cout << "Input band name you are looking for: " << std::endl;
			std::getline(std::cin, str);
			bool nashel = false;
			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				if (std::strcmp(str.c_str(), massivGrupp[i]) == 0)
				{
					std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
					nashel = true;
				}
			}

			if (nashel)
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
			bool nashel = false;
			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				if (std::strcmp(str2.c_str(), massiv_pesen[i]) == 0)
				{
					std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
					nashel = true;
				}
			}

			if (nashel)
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
			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
			}
			break;
		}

		case 8:
		{
			std::cout << "Ok, here is the playlist: " << std::endl;

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << i + 1 << ") " << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
			}

			std::cout << "Enter song position, you want to play: " << std::endl;

			int songNomer;

			std::cin >> songNomer;

			std::cin.ignore();

			--songNomer;

			if (songNomer > -1 && songNomer < realnoe_kolichestvo_pesen)
			{
				nomerTeckusheyPensy = songNomer;
				++popularnost_pesen[nomerTeckusheyPensy];
			}

			std::cout << "Now playing: " <<
				massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

			if (nomerTeckusheyPensy > 0)
			{
				std::cout << "Previous song: " <<
					massivGrupp[nomerTeckusheyPensy - 1] << " - " << massiv_pesen[nomerTeckusheyPensy - 1] << std::endl;
			}

			if (nomerTeckusheyPensy < realnoe_kolichestvo_pesen - 1)
			{
				std::cout << "Next song: " <<
					massivGrupp[nomerTeckusheyPensy + 1] << " - " << massiv_pesen[nomerTeckusheyPensy + 1] << std::endl;
			}

			break;
		}

		case 9:
		{
			std::cout << "Now playing: " <<
				massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;
			break;
		}

		case 10:
		{
			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				pesny_VTope[i] = massiv_pesen[i];
				gruppy_v_tope[i] = massivGrupp[i];
				popularnost_pesen_v_tope[i] = popularnost_pesen[i];
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

			std::cout << "Chart: " << std::endl;

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << (i + 1) << ") " << gruppy_v_tope[i] << " - " << pesny_VTope[i] << std::endl;
			}

			break;
		}

		case 11:
		{
			const char* currentSongName = massiv_pesen[nomerTeckusheyPensy];
			const char* currentBandName = massivGrupp[nomerTeckusheyPensy];
			int currentSongPopularity = popularnost_pesen[nomerTeckusheyPensy];

			for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
			{
				const char* vremenoeNazvanyePesny = massiv_pesen[i];
				const char* vremenoeNazvanyeGruppy = massivGrupp[i];
				int popularnostVremennoyPesny = popularnost_pesen[i];

				int j = i - 1;
				while (j > -1 && popularnost_pesen[j] < popularnostVremennoyPesny)
				{
					massiv_pesen[j + 1] = massiv_pesen[j];
					massivGrupp[j + 1] = massivGrupp[j];
					popularnost_pesen[j + 1] = popularnost_pesen[j];
					--j;
				}


				massiv_pesen[j + 1] = vremenoeNazvanyePesny;
				massivGrupp[j + 1] = vremenoeNazvanyeGruppy;
				popularnost_pesen[j + 1] = popularnostVremennoyPesny;
			}

			std::cout << "New playlist order " << std::endl;

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				std::cout << massivGrupp[i] << " - " << massiv_pesen[i] << std::endl;
			}

			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				if (std::strcmp(currentBandName, massivGrupp[i]) == 0
					&& std::strcmp(currentSongName, massiv_pesen[i]) == 0)
				{
					nomerTeckusheyPensy = i;
					break;
				}
			}

			std::cout << "Now playing: " << massivGrupp[nomerTeckusheyPensy] << " - " << massiv_pesen[nomerTeckusheyPensy] << std::endl;

			std::cout << "Song, you are listening on " << nomerTeckusheyPensy + 1 << " position of chart" << std::endl;
			break;
		}


		case 12:
		{
			for (int i = 0; i < realnoe_kolichestvo_pesen; ++i)
			{
				pesny_VTope[i] = massiv_pesen[i];
				gruppy_v_tope[i] = massivGrupp[i];
				popularnost_pesen_v_tope[i] = popularnost_pesen[i];
			}

			for (int i = 1; i < realnoe_kolichestvo_pesen; ++i)
			{
				const char* temp1 = pesny_VTope[i]; const char* temp2 = gruppy_v_tope[i];
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

		case 13:
		{
			prodolgitRabotu = false;
			break;
		}

		default:
			std::cout << "Unknown command." << std::endl;
		}
	}

	std::cout << "Goodbye!" << std::endl;
}