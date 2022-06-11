#include "Shader.h"


namespace illus2d {
	namespace graphics {

		Shader::Shader(const std::string& vsPath, const std::string& fsPath)
			:p_shaderID(0), p_vsCode(""), p_fsCode(""), p_vsCodePath(vsPath), p_fsCodePath(fsPath)
		{
			// Load the shaders into strings
			p_vsCode = loadShader(vsPath);
			p_fsCode = loadShader(fsPath);

			unsigned int vertexShaderID = compileShader(GL_VERTEX_SHADER, p_vsCode);
			unsigned int fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, p_fsCode);

			p_shaderID = glCreateProgram();
			glAttachShader(p_shaderID, vertexShaderID);
			glAttachShader(p_shaderID, fragmentShaderID);
			glLinkProgram(p_shaderID);
			glValidateProgram(p_shaderID);

			glDeleteShader(vertexShaderID);
			glDeleteShader(fragmentShaderID);
		}

		std::string Shader::loadShader(const std::string& shaderPath)
		{
			std::ifstream stream(shaderPath);
			std::string shaderCode;
			std::string line;

			while (std::getline(stream, line))
			{
				shaderCode += line + "\n";
			}
			return shaderCode;
		}

		unsigned int Shader::compileShader(unsigned int shaderType, const std::string& shaderCode)
		{
			unsigned int shaderID = glCreateShader(shaderType);
			const char* code = shaderCode.c_str();

			glShaderSource(shaderID, 1, &code, 0);
			glCompileShader(shaderID);

			// Error handling
			int result;
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE)
			{
				int length;
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
				char* errorMessage = new char[length];
				glGetShaderInfoLog(shaderID, length, &length, errorMessage);

				if (shaderType == GL_VERTEX_SHADER)
					std::cout << "|| VERTEX SHADER ERROR: ||" << errorMessage << std::endl;
				else
					std::cout << "|| FRAGMENT SHADER ERROR: ||" << errorMessage << std::endl;

				delete[] errorMessage;
			}

			return shaderID;
		}

		// Shader uniforms
		void Shader::setUniformVec2f(const char* uniName, const illus2d::maths::vec2& vec)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform1fv(location, 1, &vec.x);
		}
		void Shader::setUniformVec3f(const char* uniName, const illus2d::maths::vec3& vec)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform3fv(location, 1, &vec.x);
		}

		void Shader::setUniformVec4f(const char* uniName, const illus2d::maths::vec4& vec)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform4fv(location, 1, &vec.x);

		}
		void Shader::setUniformMat4f(const char* uniName, const illus2d::maths::mat4& mat)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniformMatrix4fv(location, 1, GL_TRUE, &mat.mat4x4[0][0]);
		}

		void Shader::setUniform1i(const char* uniName, const int& data)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform1i(location, data);
		}
		void Shader::setUniform1iv(const char* uniName, const int* const data)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform1iv(location, 1, data);
		}

		void Shader::setUniform1f(const char* uniName, const float& data)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform1f(location, data);
		}
		void Shader::setUniform1fv(const char* uniName, const float* const data)
		{
			int location = glGetUniformLocation(p_shaderID, uniName);
			if (location <= -1)
			{
				std::cout << "Cannot find uniform named: " << uniName << std::endl;
				return;
			}
			glUniform1fv(location, 1, data);
		}

		Shader::~Shader()
		{
			glDeleteProgram(p_shaderID);

		}
		void Shader::Bind() const
		{
			glUseProgram(p_shaderID);
		}

		void Shader::Unbind() const
		{
			glUseProgram(0);
		}


	}
}

