#ifndef INTERFACE_HXX
#define INTERFACE_HXX

#include <iostream>
#include <MediaItem.hxx>
#include <List.hxx>
#include <Database.hxx>

class Interface {
private:
    Database unit;
    void displayMenu(void);
    void getMediaItem(MediaItem& item);
    int removeItem(void);
    void clearInputBuffer(void);
public:
    Interface(void) = default;
    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    ~Interface(void) noexcept = default;
    void pool(void);
};

#endif // INTERFACE_HXX