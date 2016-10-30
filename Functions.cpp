#include "Functions.h"


void printInformation(int currentSongIndex, int amountOfSongs, Song Songs[]) {
	std::cout << std::endl << "Now playing: " <<
		Songs[currentSongIndex].band << " - " << Songs[currentSongIndex].track << std::endl;

	if (currentSongIndex > 0) {
		std::cout << "Previous song: " <<
			Songs[currentSongIndex - 1].band << " - " << Songs[currentSongIndex - 1].track << std::endl;
	}

	if (currentSongIndex < amountOfSongs - 1) {
		std::cout << "Next song: " <<
			Songs[currentSongIndex + 1].band << " - " << Songs[currentSongIndex + 1].track << std::endl;
	}
}

void printNewPlaylistOrder(int amountOfSongs, Song Songs[]) {
	std::cout << "New playlist order " << std::endl;

	for (int i = 0; i < amountOfSongs; ++i) {
		std::cout << Songs[i].band << " - " << Songs[i].track << std::endl;
	}
}

void sortingSongsByName(int currentSongIndex, int amountOfSongs, Song Songs[], Song TopSongs[]) {
	for (int i = 1; i < amountOfSongs; ++i) {
		const std::string temporaryTrackName = Songs[i].track;
		const std::string temporaryBandName = Songs[i].band;
		int temporaryPopularityVariable = Songs[i].popularity;

		int j = i - 1;
		while (j > -1 && std::strcmp(temporaryBandName.c_str(), Songs[j].band.c_str()) != 0) {
			Songs[j + 1].track = Songs[j].track;
			Songs[j + 1].band = Songs[j].band;
			Songs[j + 1].popularity = Songs[j].popularity;
			--j;
		}

		Songs[j + 1].track = temporaryTrackName;
		Songs[j + 1].band = temporaryBandName;
		Songs[j + 1].popularity = temporaryPopularityVariable;
	}
}

void sortingSongsByPopylarity(int currentSongIndex, int amountOfSongs, Song Songs[], Song TopSongs[]) {
	for (int i = 1; i < amountOfSongs; ++i) {
		const std::string tempSongName = TopSongs[i].track;
		const std::string tempBandName = TopSongs[i].band;
		int tempPopularity = TopSongs[i].popularity;

		int j = i - 1;
		while (j > -1 && TopSongs[j].popularity < tempPopularity) {
			TopSongs[j + 1].track = TopSongs[j].track;
			TopSongs[j + 1].band = TopSongs[j].band;
			TopSongs[j + 1].popularity = TopSongs[j].popularity;
			--j;
		}

		TopSongs[j + 1].track = tempSongName;
		TopSongs[j + 1].band = tempBandName;
		TopSongs[j + 1].popularity = tempPopularity;
	}
}


void changeSongNumber(int currentSongIndex, int amountOfSongs, Song Songs[]) {
	std::string temporaryTrackString = Songs[currentSongIndex].track;
	std::string temporaryBandString = Songs[currentSongIndex].band;

	for (int i = 0; i < amountOfSongs; ++i) {
		if (std::strcmp(temporaryBandString.c_str(), Songs[i].band.c_str()) == 0
			&& std::strcmp(temporaryTrackString.c_str(), Songs[i].track.c_str()) == 0) {
			currentSongIndex = i;
			break;
		}
	}
}

int searchSongByBand(int amountOfSongs, Song Songs[], std::string bandName) {
	int index;
	for (int i = 0; i < amountOfSongs; ++i) {
		if (std::strcmp(bandName.c_str(), Songs[i].band.c_str()) == 0) {
			index = i;
			break;
		}
		else index = -1;
	}
	return index;
}

int searchSongByName(int amountOfSongs, Song Songs[], std::string songName) {
	int index;
	for (int i = 0; i < amountOfSongs; ++i) {
		if (std::strcmp(songName.c_str(), Songs[i].track.c_str()) == 0) {
			index = i;
			break;
		}
		else index = -1;
	}
	return index;
}

void updateTopList(int amountOfSongs, Song Songs[], Song TopSongs[]) {
	for (int i = 0; i < amountOfSongs; ++i) {
		TopSongs[i].track = Songs[i].track;
		TopSongs[i].band = Songs[i].band;
		TopSongs[i].popularity = Songs[i].popularity;
	}
}