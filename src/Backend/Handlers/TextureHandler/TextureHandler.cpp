#include "TextureHandler.h"

TextureHandler::TextureHandler()
{
    spdlog::info("Texture Handler Initialized");

    this->LoadTextureFromPath("attack_down", "resources/player/attack_down.png");
    this->LoadTextureFromPath("attack_up", "resources/player/attack_up.png");
    this->LoadTextureFromPath("attack_right", "resources/player/attack_right.png");

    this->LoadTextureFromPath("idle_down", "resources/player/idle_down.png");
    this->LoadTextureFromPath("idle_up", "resources/player/idle_up.png");
    this->LoadTextureFromPath("idle_right", "resources/player/idle_right.png");

    this->LoadTextureFromPath("walk_down", "resources/player/walk_down.png");
    this->LoadTextureFromPath("walk_up", "resources/player/walk_up.png");
    this->LoadTextureFromPath("walk_right", "resources/player/walk_right.png");

    spdlog::info("Player Textures Loaded");

    this->LoadTextureFromPath("grass_1", "resources/tiles/tile_022.png");
    this->LoadTextureFromPath("grass_2", "resources/tiles/tile_023.png");
    this->LoadTextureFromPath("grass_3", "resources/tiles/tile_024.png");
    this->LoadTextureFromPath("dirt_1", "resources/tiles/tile_014.png");

    spdlog::info("Tile Textures Loaded");
}

TextureHandler::~TextureHandler()
{
    UnloadAllTextures();
}

TextureHandler &TextureHandler::GetInstance()
{
    static TextureHandler instance;
    return instance;
}

void TextureHandler::LoadTextureFromPath(const std::string &name, const std::string &path)
{
    if (this->m_textures.find(name) == m_textures.end())
        this->m_textures[name] = LoadTexture(path.c_str());
    else
        spdlog::warn("Texture with name {} already exists", name);
}

void TextureHandler::FreeTexture(const std::string &name)
{
    if (this->m_textures.find(name) != m_textures.end())
    {
        UnloadTexture(this->m_textures[name]);
        this->m_textures.erase(name);
    }
    else
        spdlog::warn("Texture with name {} does not exist", name);
}

void TextureHandler::UnloadAllTextures()
{
    for (auto &texture : this->m_textures)
        UnloadTexture(texture.second);
    this->m_textures.clear();

    spdlog::info("All textures unloaded");
}

Texture2D *TextureHandler::GetTexture(const std::string &name)
{
    if (this->m_textures.find(name) != m_textures.end())
        return &this->m_textures[name];
    else
    {
        spdlog::warn("Texture with name {} does not exist", name);
        return nullptr;
    }
}