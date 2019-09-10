#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "Song.hpp"

class RadList {
private:
	std::list<Song> queue_;
	std::list<Song>::iterator nowPlaying_;
public:
	void loadPlaylist(const std::string&);
	void next();
	void prev();
	Song nowPlaying();
	void addToQueue(const Song&);
	void playNext(const Song&);
};
