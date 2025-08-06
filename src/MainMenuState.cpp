#include <sstream>
#include <iostream>
#include "../include/MainMenuState.hpp"
#include "../include/A_State.hpp"
#include "../include/DEFINITION.hpp"

namespace Ogay {

    MainMenuState::MainMenuState(std::shared_ptr<GameData> data) : _data(data) {
    }

    void MainMenuState::Init() {
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_FILEPATH);
        _data->assets.LoadTexture("Next Button", BUTTON_NEXT_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
        _buttonNext.setTexture(this->_data->assets.GetTexture("Next Button"));
        _buttonNext.setPosition(118.0f, 330.0f);
    }

    void MainMenuState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type)
                _data->window.close();

            if (_data->input.IsSpriteClicked(_buttonNext, sf::Mouse::Left, _data->window))
                _data->machine.AddState(std::unique_ptr<State>(new A_State(_data)), true);
        }
    }

    void MainMenuState::Update(float dt) {

    }

    void MainMenuState::Draw(float dt) {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_buttonNext);

        _data->window.display();
    }
}
