#pragma once

#include <glm/glm.hpp>
#include <Zongine/SpriteBatch.h>
#include <Zongine/glTexture.h>

class Bullet
{
public:
	Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime);
	~Bullet();

	void init(glm::vec2 pos,glm::vec2 dir, float speed,int lifeTime);
	void draw(Zongine::SpriteBatch& spriteBatch);
	bool update();






private:
	float _speed;
	glm::vec2 _direction;
	glm::vec2 _position;
	Zongine::GLTexture _texture;
	int _lifeTime;


};

