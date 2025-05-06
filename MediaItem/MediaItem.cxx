#include "MediaItem.hxx"

MediaItem::MediaItem(void) noexcept {
    this->release_year = 0;
    this->catalog_number = 0;
}

MediaItem::MediaItem(const std::string& media_type, const std::string& title, const std::string& description, const unsigned short release_year, const std::string& genre, const std::string& media_format, const unsigned int catalog_number) noexcept {
    this->media_type = media_type;
    this->title = title;
    this->description = description;
    this->release_year = release_year;
    this->genre = genre;
    this->media_format = media_format;
    this->catalog_number = catalog_number;
}

MediaItem& MediaItem::operator=(const MediaItem& unit) noexcept {
    this->media_type = unit.media_type;
    this->title = unit.title;
    this->description = unit.description;
    this->release_year = unit.release_year;
    this->genre = unit.genre;
    this->media_format = unit.media_format;
    this->catalog_number = unit.catalog_number;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MediaItem& unit) {
    os << 
        unit.media_type << ", " <<
        unit.title << ", " <<
        unit.description << ", " <<
        unit.release_year << ", " <<
        unit.genre << ", " <<
        unit.media_format << ", " <<
        unit.catalog_number;
    return os;
}

std::string MediaItem::getMediaType(void) const noexcept {
    return this->media_type;
}

std::string MediaItem::getTitle(void) const noexcept {
    return this->title;
}

std::string MediaItem::getDescription(void) const noexcept {
    return this->description;
}

unsigned short MediaItem::getReleaseYear(void) const noexcept {
    return this->release_year;
}

std::string MediaItem::getGenre(void) const noexcept {
    return this->genre;
}

std::string MediaItem::getMediaFormat(void) const noexcept {
    return this->media_format;
}

unsigned int MediaItem::getCatalogNumber(void) const noexcept {
    return this->catalog_number;
}

void MediaItem::setMediaType(const std::string& media_type) noexcept {
    this->media_type = media_type;
}

void MediaItem::setTitle(const std::string& title) noexcept {
    this->title = title;
}

void MediaItem::setDescription(const std::string& description) noexcept {
    this->description = description;
}

void MediaItem::setReleaseYear(const unsigned short release_year) noexcept {
    this->release_year = release_year;
}

void MediaItem::setGenre(const std::string& genre) noexcept {
    this->genre = genre;
}

void MediaItem::setMediaFormat(const std::string& media_format) noexcept {
    this->media_format = media_format;
}

void MediaItem::setCatalogNumber(const unsigned int catalog_number) noexcept {
    this->catalog_number = catalog_number;
}