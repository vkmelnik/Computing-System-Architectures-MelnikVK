//
// Created by Vsevolod Melnik on 15.12.2021.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <set>
#include <semaphore>
#include "Gallery.h"

using namespace std;

Gallery gallery = Gallery();

void person(int number) {
    gallery.enter(number);
    for (int i = 0; i < gallery.pictures.size(); ++i) {
        // Look on next picture.
        gallery.pictures[i]->look(number);
        int time = rand() % 5000 + 1000;
        this_thread::sleep_for(chrono::duration<double, ::milli>(time));
        gallery.pictures[i]->walk_away(number);
    }
    gallery.exit(number);
}

void render() {
    gallery.render_library();
}

void enter_fps() {
    int fps = 0;
    while (fps < 1 || fps > 60) {
        std::cout << "Big fps is not advised for terminals with slow writing speed." << endl;
        std::cout << "Enter frame per second rate for rendering gallery in console (between 1 and 60): ";
        string fps_string;
        std::cin >> fps_string;
        try {
            fps = stoi(fps_string);
            if (fps < 1 || fps > 60) {
                std::cout << "Incorrect frame per second rate value." << endl;
            }
        } catch (exception e) {
            std::cout << "Enter a number." << endl;
        }
    }
    gallery.set_fps(fps);
}

int main() {
    std::srand(std::time(nullptr));

    std::cout << "Welcome to gallery simulator!" << endl;
    enter_fps();
    thread *rendering = new thread(render);

    // Let people enter the gallery.
    vector<thread*> people = vector<thread*>();
    for (int i = 0; i < 70; ++i) {
        thread *t = new thread(person, i);
        people.push_back(t);
        this_thread::sleep_for(chrono::duration<double, ::milli>(100));
    }

    // Wait for everyone to leave.
    for (int i = 0; i < 70; ++i) {
        people[i]->join();
    }
    gallery.close();
    rendering->join();
    std::cout << "The gallery is closed.";
}
