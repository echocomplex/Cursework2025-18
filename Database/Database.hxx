#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <List.hxx>
#include <MediaItem.hxx>
#include <Filer.hxx>
#include <iostream>
#include <Crypter.hxx>
#include <ctime>

class Database {
protected:
    Filer file;
    std::string filename;
    std::string filename_enc;
    List<MediaItem> data;
    Crypter crypter;
public:
    Database(void);
    Database(const std::string& filename);
    Database(const List<MediaItem>& unit, const std::string& filename);
    Database(const Database& unit);
    ~Database(void);
    Database& operator=(const Database& unit) noexcept;
    MediaItem& operator[](const unsigned int index) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Database& unit);
    const MediaItem& operator[](const unsigned int index) const noexcept;
    void append(const MediaItem& unit) noexcept;
    void remove(const unsigned int index) noexcept;
    unsigned int size() noexcept;
    void searchByGenre(List<MediaItem>& results, const std::string& genre) const noexcept;
    void searchByMediaFormat(List<MediaItem>& results, const std::string& format) const noexcept;
    unsigned short countMediaByFormat(const std::string& format) const noexcept;
};

#endif // DATABASE_HXX