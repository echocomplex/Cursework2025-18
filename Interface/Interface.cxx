#include "Interface.hxx"

void Interface::clearInputBuffer(void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::getMediaItem(MediaItem& item) {
    std::string temp;
    unsigned temp_number = 0;

    std::cout << "Enter Media Type (video/audio/image): ";
    std::getline(std::cin, temp);
    item.setMediaType(temp);

    std::cout << "Enter Title: ";
    std::getline(std::cin, temp);
    item.setTitle(temp);

    std::cout << "Enter Description: ";
    std::getline(std::cin, temp);
    item.setDescription(temp);

    std::cout << "Enter Release Year: ";
    std::cin >> temp_number;
    this->clearInputBuffer();
    item.setReleaseYear(temp_number);

    std::cout << "Enter Genre: ";
    std::getline(std::cin, temp);
    item.setGenre(temp);

    std::cout << "Enter Media Format (CD/DVD/VHS etc): ";
    std::getline(std::cin, temp);
    item.setMediaFormat(temp);

    std::cout << "Enter Catalog Number: ";
    std::cin >> temp_number;
    this->clearInputBuffer();
    item.setCatalogNumber(temp_number);
}

int Interface::removeItem(void) {
    int number;
    while (true) {
        std::cout << "Enter item number to delete (1-" << this->unit.size() << "): ";
        
        if (!(std::cin >> number)) {
            std::cin.clear();
            this->clearInputBuffer();
            std::cerr << "Error: Please enter a number\n\n";
            continue;
        }

        if (number > 0 && number <= this->unit.size()) {
            return number - 1;
        }
        
        std::cerr << "Error: Number must be between 1 and " << this->unit.size() << "\n\n";
    }
}

void Interface::displayMenu(void) {
    std::cout << "\n\n=== Media Library Menu ===" << std::endl;
    std::cout << "1. Display all media" << std::endl;
    std::cout << "2. Add new media item" << std::endl;
    std::cout << "3. Remove media item" << std::endl;
    std::cout << "4. Find by Genre" << std::endl;
    std::cout << "5. Find by Media Format" << std::endl;
    std::cout << "6. Count by Media Format" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    std::cout << "Enter your choice (1-7): ";
}

void Interface::pool(void) {
    short choice = 0;
    MediaItem newItem;
    List<MediaItem> results;
    std::string temp;
    
    while (true) {
        this->displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter 1-7: ";
            this->clearInputBuffer();
        }

        this->clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\n[All media items]\n";
                std::cout << this->unit << std::endl;
                break;
            case 2:
                std::cout << "\n[Adding new media item]\n";
                this->getMediaItem(newItem);
                this->unit.append(newItem);
                break;
            case 3:
                std::cout << "\n[Removing media item]\n";
                this->unit.remove(this->removeItem());
                break;
            case 4:
                std::cout << "Enter genre to search: ";
                std::getline(std::cin, temp);
                std::cout << "\n[Searching by genre: " << temp << "]\n";
                this->unit.searchByGenre(results, temp);
                for (int i = 0; i < results.length(); ++i) 
                    std::cout << results[i] << std::endl;
                results.clear();
                break;
            case 5:
                std::cout << "Enter media format to search: ";
                std::getline(std::cin, temp);
                std::cout << "\n[Searching by format: " << temp << "]\n";
                this->unit.searchByMediaFormat(results, temp);
                for (int i = 0; i < results.length(); ++i) 
                    std::cout << results[i] << std::endl;
                results.clear();
                break;
            case 6:
                std::cout << "Enter media format to count: ";
                std::getline(std::cin, temp);
                std::cout << "Found " << this->unit.countMediaByFormat(temp) 
                          << " items with format " << temp << std::endl;
                break;
            case 7:
                std::cout << "\nExiting program...\n";
                return;
        }

        std::cout << "\nOperation completed. Press Enter to continue...";
        this->clearInputBuffer();
    }
}