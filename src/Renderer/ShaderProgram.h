#pragma once

#include <string>
#include <glad/glad.h>

namespace Renderer{
    class ShaderProgram{
    public:
        ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
        ~ShaderProgram();
        bool isCompiled() const { return m_isCompiled; }
        void use() const;
        
        //ShaderProgram& operetor=(ShaderProgram&);
        ShaderProgram(ShaderProgram& shaderProgram);
    private:
        ShaderProgram();
        //ShaderProgram(ShaderProgram&);
        
        bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
        bool m_isCompiled;
        GLuint m_ID;
    };
}
