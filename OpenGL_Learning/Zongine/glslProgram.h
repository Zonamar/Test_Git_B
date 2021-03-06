#pragma once
#include <GL/glew.h>
#include <string>


namespace Zongine{
	class glslProgram
	{
	public:
		glslProgram();
		~glslProgram();


		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

		void linkShaders();

		void addAttribute(const std::string& attributeName);

		void use();

		void unUse();

		GLint getUniformLocation(const std::string uniformname);



	private:

		int _numAttributes;

		GLuint _programID;

		GLuint _vertexShaderID;

		GLuint _fragmentShaderID;


		void compileShader(const std::string FilePath, GLuint shaderID);

	};

}