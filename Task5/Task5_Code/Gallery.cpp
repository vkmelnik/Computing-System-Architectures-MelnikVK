//
// Created by Vsevolod Melnik on 15.12.2021.
//

#include "Gallery.h"
#include <chrono>
#include <thread>
#include <semaphore>

Gallery::Gallery() {
    for (int i = 0; i < 5; ++i) {
        std::string name = "Picture " + std::to_string(i);
        pictures.push_back(new Picture(name));
        pictures[pictures.size() - 1]->move_to_gallery(this);
    }
}

// Let person enter the gallery.
void Gallery::enter(int person) {
    queue.acquire();
    set_semaphore.acquire();
    people_waiting.insert(person);
    set_semaphore.release();
}

// Delete person from set of waiting people.
void Gallery::person_looks_on_picture(int person) {
    set_semaphore.acquire();
    people_waiting.erase(person);
    set_semaphore.release();
}

// Insert person in set of waiting people.
void Gallery::person_waits(int person) {
    set_semaphore.acquire();
    people_waiting.insert(person);
    set_semaphore.release();
}

// Let person exit the gallery.
void Gallery::exit(int person) {
    set_semaphore.acquire();
    people_waiting.erase(person);
    set_semaphore.release();
    queue.release();
}

void Gallery::render_library() {
    while (is_open) {
        output.acquire();
        system("clear");
        std::cout << "People between pictures: ";
        set_semaphore.acquire();
        for (int person: people_waiting)
            std::cout << person << ' ';
        set_semaphore.release();
        std::cout << std::endl << "People watching pictures:" << std::endl;
        for (auto &picture: pictures)
            std::cout << picture->to_string() << std::endl;
        output.release();
        std::this_thread::sleep_for(std::chrono::duration<double, ::std::milli>(1000 / fps));
    }
}

void Gallery::close() {
    is_open = false;
}

void Gallery::set_fps(int fps) {
    this->fps = fps;
}
