#pragma once

#include "Song.h"

class Playlist
{

	Playlist(int maxSize);
	Playlist(const Playlist &other);

	void AddSong(const Song &newSong);
	unsigned GetTotalLength() const;
	const Song& GetLongestSong() const;

	Playlist& operator=(const Playlist &other);
	~Playlist();

private:

	void CopyHelper(const Playlist &other);
	void EraseMemory();

	int maxSize;
	int currentSize;
	Song *songs;
};
