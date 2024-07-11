#pragma once

// Standard Headers
#include <string>
#include <unordered_map>

// External Headers
#include <raylib.h>
#include <spdlog/spdlog.h>
// Internal Headers

class TextureHandler
{
private:
    TextureHandler();

public:
    ~TextureHandler();
    static TextureHandler &GetInstance();

    void LoadTextureFromPath(const std::string &name, const std::string &path);
    void FreeTexture(const std::string &name);
    void UnloadAllTextures();
    Texture2D *GetTexture(const std::string &name);

private:
    std::unordered_map<std::string, Texture2D> m_textures;
};