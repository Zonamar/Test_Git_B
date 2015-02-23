#include "glslProgram.h"
#include <fstream>
#include "MyError.h"
#include <vector>

glslProgram::glslProgram() : _programID(0), _vertexShaderID(0), _fragmentShaderID(0), _numAttributes(0)
{

	
}


glslProgram::~glslProgram()
{
}


void glslProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	
	_programID = glCreateProgram();

	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0)
	{
		fatalError("Vertex Shader Failed to init");
	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0)
	{
		fatalError("Fragment Shader Failed to init");
	}

	compileShader(vertexShaderFilePath, _vertexShaderID);
	compileShader(fragmentShaderFilePath, _fragmentShaderID);


}

void glslProgram::linkShaders()
{
	

	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	glLinkProgram(_programID);

	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);



		//We don't need the program anymore.
		glDeleteProgram(_programID);
		//Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		//print the error log and quit
		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shaders failed to link!");
	}


	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);




}

void glslProgram::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
	

}

void glslProgram::compileShader(const std::string FilePath, GLuint shaderID)
{
	

	std::ifstream File(FilePath);
	if (File.fail())
	{
		fatalError("Failed to open" + FilePath);
	}

	std::string fileCont;
	std::string line;

	while (std::getline(File, line))
	{
		fileCont += line + '\n';
	}

	File.close();
	const char* contPtr = fileCont.c_str();
	glShaderSource(shaderID, 1, &contPtr, nullptr);

	glCompileShader(shaderID);

	GLint success = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{

		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);


		glDeleteShader(shaderID);

		std::printf("%s\n", &(errorLog[0]));

		fatalError("Shader failed to compile from" + FilePath);
	}


}

void glslProgram::use()
{

	glUseProgram(_programID);

	for (int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}

}

void glslProgram::unUse()
{
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}