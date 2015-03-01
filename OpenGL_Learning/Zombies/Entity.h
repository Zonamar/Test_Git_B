#pragma once

#include <glm/glm.hpp>
#include <Zongine/glTexture.h>
#include <Zongine/SpriteBatch.h>

enum EntityType{
			PLAYER,
			HUMAN,
			ZOMBIE,
			BULLET,



			NUM_ENTITY
};


class Entity
{
public:
	Entity(glm::vec2 startLoc,EntityType newType);
	~Entity();

	void init();

	void draw(Zongine::SpriteBatch &spriteBatch);

	void update();


private:

	void humanLogic();
	void zombieLogic();
	void playerLogic();
	void bulletLogic();




	glm::vec2 _location;
	
	Zongine::GLTexture _texture;

	float _speed;



};

