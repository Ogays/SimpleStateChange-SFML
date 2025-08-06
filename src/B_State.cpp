#include <sstream>
#include <iostream>
#include "../include/B_State.hpp"
#include "../include/A_State.hpp"

#include "../include/MainMenuState.hpp"
#include "../include/DEFINITION.hpp"

namespace Ogay {

    B_State::B_State(std::shared_ptr<GameData> data) : _data(data) {
    }

    void B_State::Init() {
        _data->assets.LoadTexture("State B Background", STATE_B_FILEPATH);
        _data->assets.LoadTexture("Button Exit", BUTTON_EXIT_FILEPATH);
        _data->assets.LoadTexture("Button Back", BUTTON_BACK_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("State B Background"));

        _buttonExit.setTexture(this->_data->assets.GetTexture("Button Exit"));
        _buttonExit.setPosition(216.f, 330.f);

        _buttonBack.setTexture(this->_data->assets.GetTexture("Button Back"));
        _buttonBack.setPosition(20.f, 330.f);
    }

    void B_State::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();

            if (_data->input.IsSpriteClicked(_buttonBack, sf::Mouse::Left, _data->window))
                _data->machine.AddState(std::unique_ptr<State>(new A_State(_data)), true);

            if (_data->input.IsSpriteClicked(_buttonExit, sf::Mouse::Left, _data->window))
                _data->window.close();
        }
    }

    void B_State::Update(float dt) {

    }

    void B_State::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_buttonExit);
        _data->window.draw(_buttonBack);
        _data->window.display();
    }
}

