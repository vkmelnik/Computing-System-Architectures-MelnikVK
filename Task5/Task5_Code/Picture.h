//
// Created by Vsevolod Melnik on 15.12.2021.
//

#ifndef TASK5_CODE_PICTURE_H
#define TASK5_CODE_PICTURE_H

#include<string>
#include<set>
#include<semaphore>
#include "Gallery.h"

class Gallery;

class Picture {
private:
    std::counting_semaphore<10> queue = std::counting_semaphore<10>(10); // Semaphore for people.
    std::binary_semaphore set_semaphore = std::binary_semaphore(1); // Semaphore for access to set of people watching.
    std::set<int> people = std::set<int>(); // Numbers of people, who look at this picture.
    std::string name; // Name of the picture.
    Gallery *gallery{}; // Gallery, where this picture is in.

public:

    // Make person look at the picture.
    void look(int person);

    // Make person walk away from a picture.
    void walk_away(int person);

    // Name of the picture.
    std::string get_name();

    // Get string presentation of a picture.
    std::string to_string();

    void move_to_gallery(Gallery* gallery);

    Picture(std::string name);
};


#endif //TASK5_CODE_PICTURE_H
