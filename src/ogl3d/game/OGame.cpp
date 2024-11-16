#include "../include/ogl3d/game/OGame.h"
#include "../include/ogl3d/window/OWindow.h"
#include <Windows.h>

OGame::OGame() {
    m_display = new OWindow();
}

OGame::~OGame(){
    delete m_display;
}

void OGame::run(){
    MSG msg;
    while(m_isRunning){
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Sleep(1000);
    }
}

void OGame::quit(){
    m_isRunning = false;
}