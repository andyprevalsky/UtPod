#include "song.h"

Song::Song() {   

} 
Song::Song(string artist, string title, int size) {
    this->artist = artist;
    this->title = title;
    this->size = size;
}

bool Song::operator < (Song const &s) {

    if (artist.compare(s.getArtist()) < 0) {
        return true;
    } else if (artist.compare(s.getArtist()) > 0) {
        return false;
    }

    if (title.compare(s.getTitle()) < 0) {
        return true;
    } else if (title.compare(s.getTitle()) > 0) {
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