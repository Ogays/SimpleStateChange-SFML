#include <sstream>
#include <iostream>

#include "../include/A_State.hpp"
#include "../include/B_State.hpp"

#include "../include/DEFINITION.hpp"
#include "../include/MainMenuState.hpp"

namespace Ogay {

    A_State::A_State(std::shared_ptr<GameData> data) : _data(data) {
    }

    void A_State::Init() {
        _data->assets.LoadTexture("State A Background", STATE_A_FILEPATH);
        _data->assets.LoadTexture("Button Next", BUTTON_NEXT_FILEPATH);
        _data->assets.LoadTexture("Button Back", BUTTON_BACK_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("State A Background"));

        _buttonNext.setTexture(this->_data->assets.GetTexture("Button Next"));
        _buttonNext.setPosition(216.f, 330.f);

        _buttonBack.setTexture(this->_data->assets.GetTexture("Button Back"));
        _buttonBack.setPosition(20.f, 330.f);
    }

    void A_State::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();

            if (_data->input.IsSpriteClicked(_buttonNext, sf::Mouse::Left, _data->window))
                _data->machine.AddState(std::unique_ptr<State>(new B_State(_data)), true);

            if (_data->input.IsSpriteClicked(_buttonBack, sf::Mouse::Left, _data->window))
                _data->machine.AddState(std::unique_ptr<State>(new MainMenuState(_data)), true);
        }
    }

    void A_State::Update(float dt) {

    }

    void A_State::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_buttonNext);
        _data->window.draw(_buttonBack);
        _data->window.display();
    }
}

