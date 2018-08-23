#ifndef PONG_HPP
#define PONG_HPP

#include <SFML/Graphics.hpp>
#include "b2DrawDebug.hpp"

#define PPM 32 // Pixels Per Meters

enum class BallDirection
{
    Left,
    Right
};

enum class GameState
{
    Paddle1Win,
    Paddle2Win,
    PartyInProgress,
    PressSpaceToStart
};

class Pong : public sf::RenderWindow
{
    public:
        Pong();
        ~Pong();
        void update();
        void display();

    private:
        void aiPaddle1();
        void aiPaddle2();
        void ballVelocityControl();
        void pInitShapes();
        void pCreateBackground();
        void pCreatePaddle1();
        void pCreatePaddle2();
        void pCreateBall();
        void pReset();
        GameState m_gameState;
        sf::Clock m_chrono;
        float velocityXlimit;
        // Graphics
        sf::Font g_fontPixelArt;
        sf::Text g_txtWinner;
        sf::Text g_txtPressSpaceToStart;
        sf::Text g_txtPressEnterToContinue;
        sf::RectangleShape g_paddle1;
        sf::RectangleShape g_paddle2;
        sf::CircleShape g_ball;
        sf::RectangleShape g_topWall;
        sf::RectangleShape g_bottomWall;

        // Physics
        float p_timeStep;
        b2DrawDebug p_b2DebugDraw;
        b2World *p_b2World;
        b2BodyDef p_b2BodyDef_topWall;
        b2BodyDef p_b2BodyDef_bottomWall;
        b2BodyDef p_b2BodyDef_paddle1;
        b2BodyDef p_b2BodyDef_paddle2;
        b2BodyDef p_b2BodyDef_ball;
        b2Body* p_b2Body_topWall;
        b2Body* p_b2Body_bottomWall;
        b2Body* p_b2Body_paddle1;
        b2Body* p_b2Body_paddle2;
        b2Body* p_b2Body_ball;
        b2PolygonShape p_b2PolygonShape_wall;
        b2PolygonShape p_b2PolygonShape_paddle;
        b2CircleShape p_b2CircleShape_ball;
        b2Fixture* p_b2Fixture_topWall;
        b2Fixture* p_b2Fixture_bottomWall;
        b2Fixture* p_b2Fixture_paddle1;
        b2Fixture* p_b2Fixture_paddle2;
        b2Fixture* p_b2Fixture_ball;
        b2PrismaticJointDef p_b2JointDef_paddle1;
        b2PrismaticJointDef p_b2JointDef_paddle2;
        b2Joint* p_b2Joint_paddle1;
        b2Joint* p_b2Joint_paddle2;
};

#endif // PONG_HPP
