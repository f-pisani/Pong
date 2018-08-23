#ifndef B2DEBUGDRAW_HPP
#define B2DEBUGDRAW_HPP

#include <iostream>
#include <Box2D.h>
#include <SFML\Graphics.hpp>

#define PIXELS_METER 32

struct b2AABB;

class b2DrawDebug : public b2Draw
{
    public:
        b2DrawDebug(sf::RenderWindow* target);
        b2DrawDebug(b2DrawDebug& c);
        void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
        void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
        void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
        void DrawTransform(const b2Transform&);
        void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
        void DrawAABB(b2AABB* aabb, const b2Color& color);

    private:
        sf::RenderWindow* m_target;
};

#endif // DEBUGDRAW_HPP
