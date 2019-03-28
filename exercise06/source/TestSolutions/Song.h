#pragma once
#include <cstring>

class Song
{
public:
	Song()
	{
		length = 0;
		artist[0] = '\0';
		name[0] = '\0';
	}

	Song(const char *name, const char *artist, unsigned int length)
		: length(length)
	{
		strcpy(this->name, name);
		strcpy(this->artist, artist);
	}

	char const* GetTitle() const
	{
		return name;
	}

	char const* GetArtist() const
	{
		return artist;
	}

	unsigned int GetLength() const
	{
		return length;
	}

private:
	char name[101];
	char artist[101];
	unsigned int length;
};
