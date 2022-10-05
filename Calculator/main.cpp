#include "Game.h"
#include <Windows.h>
//#include <boost/filesystem.hpp>

std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePointers;

int main()
{
	Game* game = new Game;

	/*const std::string filename = "res/data.dat";
	if (boost::filesystem::exists(filename))
	{
		std::ifstream infile(filename);
		boost::archive::binary_iarchive archive(infile);
		archive >> *game;
	}*/

	//FreeConsole();
	srand(time(0));
	game->start();

	/*std::ofstream outfile(filename);
	boost::archive::binary_oarchive archive(outfile);
	archive << *game;*/

	delete game;
	return 0;
}