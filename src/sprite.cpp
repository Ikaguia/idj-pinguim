#include <sprite.hpp>
#include <game.hpp>
#include <resources.hpp>

Sprite::Sprite():texture{NULL}{}
Sprite::Sprite(string file):texture{NULL}{
	open(file);
}
Sprite::~Sprite(){}

void Sprite::open(string file){
	texture = Resources::getImage(file);
	if(SDL_QueryTexture(texture,NULL,NULL,&width,&height)){
		cout << "Erro ao carregar as dimensões da textura \"" << file << "\", o programa ira encerrar agora" << endl;
		exit(EXIT_FAILURE);
	}
	setClip(0,0,width,height);
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
