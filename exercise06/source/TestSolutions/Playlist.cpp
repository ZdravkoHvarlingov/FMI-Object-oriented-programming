#include "pch.h"
#include "Playlist.h"

Playlist::Playlist(int maxSize)
{
	this->songs = new Song[maxSize];
	this->currentSize = 0;
	this->maxSize = maxSize;
}

Playlist::Playlist(const Playlist & other)
{
	CopyHelper(other);
}

void Playlist::AddSong(const Song & newSong)
{
	if (currentSize == maxSize)
	{
		return;
	}

	songs[currentSize] = newSong;
	++currentSize;
}

unsigned Playlist::GetTotalLength() const
{
	unsigned int totalLength = 0;
	for (int i = 0; i < currentSize; i++)
	{
		totalLength += songs[i].GetLength();
	}

	return totalLength;
}

const Song & Playlist::GetLongestSong() const
{
	int	longestSongInd = 0;
	for (int i = 1; i < currentSize; i++)
	{
		if (songs[i].GetLength() > songs[longestSongInd].GetLength())
		{
			longestSongInd = i;
		}
	}

	return songs[longestSongInd];
}

Playlist & Playlist::operator=(const Playlist & other)
{
	if (this != &other)
	{
		EraseMemory();
		CopyHelper(other);
	}

	return *this;
}

Playlist::~Playlist()
{
	EraseMemory();
}

void Playlist::CopyHelper(const Playlist & other)
{
	songs = new Song[other.maxSize];
	currentSize = other.currentSize;
	maxSize = other.maxSize;

	for (int i = 0; i < currentSize; i++)
	{
		songs[i] = other.songs[i];
	}
}

void Playlist::EraseMemory()
{
	delete[] songs;
}
