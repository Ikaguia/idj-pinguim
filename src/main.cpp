#include <game.hpp>

int main (int argc, char** argv){
	Game game("Cristiano Krug Brust - 15/0008058",1024,600);
	Game::getInstance().run();
	return 0;
}