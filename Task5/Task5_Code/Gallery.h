//
// Created by Vsevolod Melnik on 15.12.2021.
//

#ifndef TASK5_CODE_GALLERY_H
#define TASK5_CODE_GALLERY_H

#include <iostream>
#include <semaphore>
#include <set>
#include <vector>

#include "Picture.h"

class Picture;

class Gallery {
private:
    bool is_open = true;
    std::binary_semaphore output = std::binary_semaphore (1); // Semaphore for output stream.
    std::counting_semaphore<50> queue = std::counting_semaphore<50>(50); // Semaphore for people.
    std::binary_semaphore set_semaphore = std::binary_semaphore(1); // Semaphore for access to set of people waiting.
    std::set<int> people_waiting = std::set<int>(); // Numbers of people, who are inside the gallery and wait to watch a picture.
    int fps = 20; // Frames per second for rendering.

public:
    std::vector<Picture *> pictures = std::vector<Picture *>();

    Gallery();

    // Let person enter the gallery.
    void enter(int person);

    // Delete person from set of waiting people.
    void person_looks_on_picture(int person);

    // Insert person in set of waiting people.
    void person_waits(int person);

    // Let person exit the gallery.
    void exit(int person);

    void render_library();

    // Close library and stop rendering.
    void close();

    // Set frame rate for rendering.
    void set_fps(int fps);
};


#endif //TASK5_CODE_GALLERY_H
