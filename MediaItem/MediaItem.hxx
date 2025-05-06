#ifndef MEDIAITEM_HXX
#define MEDIAITEM_HXX

#include <string>
#include <iostream>

class MediaItem {
private:
    std::string media_type;
    std::string title;
    std::string description;
    unsigned short release_year;
    std::string genre;
    std::string media_format;
    unsigned int catalog_number;
public:
    MediaItem(void) noexcept;
    MediaItem(const std::string& media_type, const std::string& title, const std::string& description, const unsigned short release_year, const std::string& genre, const std::string& media_format, const unsigned int catalog_number) noexcept;
    ~MediaItem(void) noexcept = default;
    MediaItem& operator=(const MediaItem& unit) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const MediaItem& unit);
    std::string getMediaType(void) const noexcept;
    std::string getTitle(void) const noexcept;
    std::string getDescription(void) const noexcept;
    unsigned short getReleaseYear(void) const noexcept;
    std::string getGenre(void) const noexcept;
    std::string getMediaFormat(void) const noexcept;
    unsigned int getCatalogNumber(void) const noexcept;
    void setMediaType(const std::string& media_type) noexcept;
    void setTitle(const std::string& title) noexcept;
    void setDescription(const std::string& description) noexcept;
    void setReleaseYear(const unsigned short release_year) noexcept;
    void setGenre(const std::string& genre) noexcept;
    void setMediaFormat(const std::string& media_format) noexcept;
    void setCatalogNumber(const unsigned int catalog_number) noexcept;
};

#endif // MEDIAITEM_HXX