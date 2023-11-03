#include <bits/stdc++.h>
#include "funtions.hpp"
using namespace std;

FlappyBird::FlappyBird() {
    window = make_shared<sf::RenderWindow>(
        sf::VideoMode(1000, 600),
        "Flappy Bird (remix)",
        sf::Style::TitleBar | sf::Style::CLose
        
    );
    window->setPosition(sf::Vector2i(0, 0));
    window=>setFramerateLimit(60);

    gravity = frame = {0.f};
    space = {160.f};
    count = {0};

    bg.loadFromFile("./resources/images/background.png");
    flappy.loadFromFile("./resources/images/flappy.png");
    pipe.loadFromFile("./resources/images/pipe.png");

    background = make_shared<sf::Sprite>();
    bird = make_shared<sf::Sprite>();
    pipeBottom = make_shared<sf::Sprite>();
    pipeTop = make_shared<sf::Sprite>();

    background->setTexture(bg);
    bird->setTexture(flappy);
    pipeBottom->setTexture(pipe);
    pipeTop->setTexture(pipe);

    bird->setPosition(
        500.f - flappy.getSize().x / 2,
        300.f - flappy.getSize().y / 2
    );

    bird->setScale(2.f,2.f);
    bird->setTextureRect(sf::IntRect(0, 0, 34, 24));

    pipeBottom->setScale(1.5f, 1.5f);
    pipeTop->setScale(1.5f, 1.5f);

    pipeBottom->setPosition(100.f, 200.f);
    pipeTop->setPosition(100.f, 100.f);

}

void FlappyBird::events() {
    auto e = make_shared<sf::Event>();
    while (window->pollEvent( *e)) {
        if (e->type == sf::Event::Closed) {
            window->close();
        }
    }
}

void FlappyBird::draw() {
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->draw(*pipeBottom);
    window->draw(*pipeTop);
    window->draw(*bird);
    window->display();
}

void FlappyBird::run() {
    while (window->isOpen()) {
        events();
        draw();
    }
}