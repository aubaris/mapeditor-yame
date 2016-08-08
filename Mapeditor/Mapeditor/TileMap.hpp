#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();
	void changeTile(unsigned int x, unsigned int y, int value);
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	void changeTileFromMousePosition(int x, int y, int value);
	void changeTilesFromRectangle(sf::FloatRect rect, int value);

	void loadFromFile(std::ifstream *file);
	void saveToFile(std::ofstream *file) const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void updateVertices(unsigned int x, unsigned int y);

	void writeString(std::ofstream *file, const std::string& str) const;
	std::string readString(std::ifstream *file);

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::string m_texturePath;

	int *m_tiles;
	sf::Vector2u m_tileSize;
	sf::Vector2u m_mapSize;
};

#endif