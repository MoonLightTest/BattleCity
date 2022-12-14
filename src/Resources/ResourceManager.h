#pragma once

#include <string>
#include <memory>
#include <map>

namespace Renderer
{
    class ShaderProgram;
}

class ResourceManager{
public:
    ResourceManager(const std::string& executablePath);

    std::shared_ptr<Renderer::ShaderProgram> loadShaders(
        const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
    std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);

private:
    typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
    ShaderProgramsMap m_shaderPrograms;

    std::string m_path;
    
    ResourceManager(const ResourceManager&);

    std::string getFileString(const std::string& relativeFilePath) const;
};