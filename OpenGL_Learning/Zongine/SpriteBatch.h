#pragma once

#include<GL\glew.h>
#include"myVertex.h"
#include<glm/glm.hpp>
#include<vector>


namespace Zongine{

	enum class GlyphSortType
	{
		NONE,
		FRONT_TO_BACK,
		BACK_TO_FRONT,
		TEXTURE,

	};



	struct Glyph{

		Vertex topLeft;
		Vertex bottomLeft;
		Vertex topRight;
		Vertex bottomRight;
		GLuint texture;
		float depth;


	};

	class RenderBatch
	{
	public :
		RenderBatch(GLuint offSet, GLuint numVerts, GLuint text) : offset(offSet), numVertices(numVerts), texture(text){};
		GLuint offset;
		GLuint numVertices;
		GLuint texture;
		

	};


	class SpriteBatch
	{

	public:

		SpriteBatch();
		~SpriteBatch();

		void begin(GlyphSortType sortType = GlyphSortType::TEXTURE); 

		void end();

		void draw(const glm::vec4 &destRect,const glm::vec4 &uvRect, GLuint texture,float depth,const Color &color);

		void renderBatch();

		void init();

	private:

		void createRenderBatches();

		void createVertexArray();
		void sortGlyphs();

		static bool compareFrontToBack(Glyph * a, Glyph * b);
		static bool compareBackToFront(Glyph * a, Glyph * b);
		static bool compareTexture(Glyph * a, Glyph * b);


		

		GlyphSortType _sortType;



		GLuint _vbo;
		GLuint _vao;
		std::vector<Glyph*> _glyphs;

		std::vector<RenderBatch> _renderBatches;



	};





}

