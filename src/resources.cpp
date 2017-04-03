#include <resources.hpp>
#include <game.hpp>

std::unordered_map<string,SDL_Texture*> Resources::imageTable;


SDL_Texture* Resources::getImage(string file){
	if(imageTable.count(file))return imageTable[file];
	SDL_Texture* texture = IMG_LoadTexture(Game::getInstance().getRenderer(),file.c_str());
	if(!texture){
		cout << "Erro ao carregar textura \"" << file << "\":" << endl;
		string s=SDL_GetError();
		cout << s << endl << "o programa ira encerrar agora" << endl;
		exit(EXIT_FAILURE);
	}
	return texture;
}

void Resources::clearImages(){
	imageTable.clear();
}
