#include "Bullet.h"

#include <Zongine/ResourceManager.h>

Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime)
{
	_position = pos;
	_direction = dir;
	_speed = speed;
	_texture = Zongine::ResourceManager::getTexture("Textures/JimmyJump/PNG/Bullet.png");
	_lifeTime = lifeTime;

}


Bullet::~Bullet()
{
}


void Bullet::init(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime)
{
	_position = pos;
	_direction = dir;
	_speed = speed;
	_texture = Zongine::ResourceManager::getTexture("Textures/JimmyJump/PNG/Bullet.png");
	_lifeTime = lifeTime;

}
void Bullet::draw(Zongine::SpriteBatch& spriteBatch)
{
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	
	Zongine::Color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	glm::vec4 posAndSize = glm::vec4(_position.x, _position.y, 20, 20);

	spriteBatch.draw(posAndSize, uv, _texture.id, 0.0f, color);
}

bool Bullet::update()
{
	_position += _direction * _speed;
	_lifeTime--;


	if (_lifeTime == 0)
	{
		return true;
	}
	return false;

}