#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Ogay {
    
    class A_State : public State {
    public:
        A_State(std::shared_ptr<GameData> data);
        
        void Init();
        
        void HandleInput();
        void Update( float dt );
        void Draw( float dt );
        
    private:
        std::shared_ptr<GameData> _data;
        
        sf::Sprite _background;
        sf::Sprite _buttonBack;
        sf::Sprite _buttonNext;
    };
}