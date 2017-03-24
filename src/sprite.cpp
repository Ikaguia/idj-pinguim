#include <sprite.hpp>
#include <game.hpp>
#include <resources.hpp>

Sprite::Sprite():texture{nullptr},scaleX{1},scaleY{1}{}
Sprite::Sprite(string file):texture{nullptr},scaleX{1},scaleY{1}{
	open(file);
}
Sprite::~Sprite(){}

void Sprite::open(string file){
	texture = Resources::getImage(file);
	if(SDL_QueryTexture(texture,nullptr,nullptr,&width,&height)){
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

void Sprite::render(int x,int y,float angle){
	SDL_Rect dest;
	dest.x=x;
	dest.y=y;
	dest.w=getWidth();
	dest.h=getHeight();
	SDL_RenderCopyEx(Game::getInstance().getRenderer(),texture,&clipRect,&dest,angle,nullptr,SDL_FLIP_NONE);
}

int Sprite::getWidth(){
	return clipRect.w*scaleX;
}
int Sprite::getHeight(){
	return clipRect.h*scaleY;
}

bool Sprite::isOpen(){
	return (texture!=nullptr);
}

void Sprite::SetScaleX(float scale){
	scaleX=scale;
}
void Sprite::SetScaleY(float scale){
	scaleY=scale;
}
