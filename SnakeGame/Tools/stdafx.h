#pragma once
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

class SnakeGraphics;

constexpr int WORLD_WIDTH = 60;
constexpr int WORLD_HEIGHT = 60;