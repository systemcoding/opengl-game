#pragma once

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <cstdint>
#include <string>
#include <iostream>

#include "../core/include/Window.h"

//////////////////// Actual Game ///////////////////////

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
};

class Game
{
public:
    GameState m_State;	
    bool m_Keys[1024];
    bool m_KeysProcessed[1024];
    uint32_t m_Width, m_Height;
    std::string m_Title;
    float m_Dt;
public:
    Game(uint32_t width, uint32_t height, std::string title);

    void Init(uint32_t width, uint32_t height, std::string title);
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();

    ~Game();
private:
    inline float GetDeltaTime() { return m_Dt; }
};