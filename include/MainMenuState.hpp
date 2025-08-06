#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Ogay {
    
    class MainMenuState : public State {
    public:
        MainMenuState(std::shared_ptr<GameData> data);
        
        void Init();
        
        void HandleInput();
        void Update( float dt );
        void Draw( float dt );
        
    private:
        std::shared_ptr<GameData> _data;
        
        sf::Sprite _background;
        sf::Sprite _buttonNext;
    };
}