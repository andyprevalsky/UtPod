#include "song.h"

Song::Song() {   

} 

Song::Song(string artist, string title, int size) {
    this->artist = artist;
    this->title = title;
    this->size = size;
}

bool Song::operator < (Song const &s) {
// a </> b
//positive when
//negative when a < b

    if (artist < s.getArtist()) {
        return true;
    } else if (artist > s.getArtist()) {
        return false;
    }

    if (title < s.getTitle()) {
        return true;
    } else if (title > s.getTitle()) {
        return false;
    }

    if (size < s.getSize()) {
        return true;
    }
    return false;
}

bool Song::operator > (Song const &s) {
    return !(*this < s);
}

bool Song::operator == (Song const &s) {
    if (artist == s.getArtist() && title == s.getTitle() && size == s.getSize()) {
        return true;
    }
    return false;
}

Song::~Song() {

}