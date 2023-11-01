#include <bits/stdc++.h>
#include "functions.hpp"
using namespace std;

FlappyBird::FlappyBird() {
    window = make_shared<sf::RenderWindow>(
        sf::VideoMode(1000, 600),
        "Flappy Bird (remix)",
        sf::Style::TitleBar | sf::Style::CLose
        
    );
}