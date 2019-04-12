#include "Song.hpp"


Song::Song(std::string name, std::string artist, std::string album, 
			unsigned int duration, bool explicitLyrics)
	: name_(name),
	artist_(artist),
	album_(album),
	duration_(duration),
	explicit_lyrics_(explicitLyrics)
{
}

std::string Song::name() {
	return name_;
};
std::string Song::artist() {
	return artist_;
};
std::string Song::album() {
	return album_;
};
unsigned int Song::minutes() {
	return duration_ / 60;
};
unsigned int Song::seconds() {
	return duration_ % 60;
};
bool Song::explicit_lyrics() {
	return explicit_lyrics_;
};
