#include "SongManagementStruct.h"

#ifndef PRINT_H
#define PRINT_H

void printOrder(const int NUMBER_OF_SONGS, SongManagement table[]);
void menu();
void printCurrentSongDetails(const int NUMBER_OF_SONGS, SongManagement table[], int currentSongNumber);

#endif