#include <sprite.hpp>

Sprite::Sprite():texture{NULL}{}
Sprite::Sprite(std::string file):texture{NULL}{
	open(file);
}
Sprite::~Sprite(){
	if(texture)SDL_DestroyTexture(texture);
}

void Sprite::open(std::string file){
	if(texture)SDL_DestroyTexture(texture);
	texture = IMG_LoadTexture(Game::getInstance().getRenderer(),file.c_str());
	if(!texture){
		std::cout << "Erro ao carregar textura \"" << file << "\":" << std::endl;
		std::string s=SDL_GetError();
		std::cout << s << std::endl << "o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	if(SDL_QueryTexture(texture,NULL,NULL,&width,&height)){
		std::cout << "Erro ao carregar as dimensões da textura \"" << file << "\", o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
}
void Sprite::setClip(int x,int y,int w,int h){
	clipRect.x=x;
	clipRect.y=y;
	clipRect.w=w;
	clipRect.h=h;
}
void Sprite::render(int x,int y){
	SDL_Rect dest;
	dest.x=x;
	dest.y=y;
	dest.w=getWidth();
	dest.h=getHeight();
	SDL_RenderCopy(Game::getInstance().getRenderer(),texture,&clipRect,&dest);
}

int Sprite::getWidth(){
	return clipRect.w;
}
int Sprite::getHeight(){
	return clipRect.h;
}

bool Sprite::isOpen(){
	return (texture!=NULL);
}
