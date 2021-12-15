//
// Created by Vsevolod Melnik on 15.12.2021.
//

#include "Picture.h"
#include<semaphore>

// Make person look at the picture.
void Picture::look(int person) {
    gallery->person_looks_on_picture(person);
    queue.acquire();
    set_semaphore.acquire();
    people.insert(person);
    set_semaphore.release();
}

// Make person walk away from a picture.
void Picture::walk_away(int person) {
    set_semaphore.acquire();
    people.erase(person);
    set_semaphore.release();
    queue.release();
    gallery->person_waits(person);
    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(500));
}

// Name of the picture.
std::string Picture::get_name() {
    return name;
}

// Get string presentation of a picture.
std::string Picture::to_string() {
    set_semaphore.acquire();
    std::string str = name + ": ";
    for (int person: people)
        str.append(" " + std::to_string(person));
    set_semaphore.release();
    return str;
}

Picture::Picture(std::string name) {
    this->name = name;
}

void Picture::move_to_gallery(Gallery *gallery) {
    this->gallery = gallery;
}
