#include <bits/stdc++.h>
#pragma once
#include <SFML/Graphics.hpp>
#inlcude <memory>
using namespace std;

class FlappyBird {
    shared_ptr<sf::RenderWindow> window;
    float gravity, frame, space;
    int count;

    sf::Texture bg, flappy, pipe;
    shared_ptr<sf::Sprite> background, bird, pipeBottom, pipeTop;
    vector<sf::Sprite> pipes;

    protected:
        void events();
        void draw();

    public:
        FlappyBird();
        void run();
        
};