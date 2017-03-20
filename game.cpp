#include <game.hpp>

Game* Game::instance=NULL;

Game::Game(std::string title,int width,int height){
	if(instance){
		std::cout << "Erro, mais de uma instancia de 'Game' instanciada, o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	instance=this;
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
		std::cout << "Erro SDL encontrado:\n" << SDL_GetError() << std::endl << "o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	int img_init = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	if(img_init != (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
		std::cout << "Erro na inicialização da IMG_Init:" << std::endl;
		if(!(img_init & IMG_INIT_JPG))std::cout << "erro ao inicializar JPG" << std::endl;
		if(!(img_init & IMG_INIT_PNG))std::cout << "erro ao inicializar PNG" << std::endl;
		if(!(img_init & IMG_INIT_TIF))std::cout << "erro ao inicializar TIF" << std::endl;
		std::cout << "o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
   	window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
	if(!window){
		std::cout << "Erro ao instanciar janela da SDL, o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	if(!window){
		std::cout << "Erro ao instanciar renderizador da SDL, o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	state = new State;
	if(!state){
		std::cout << "Erro ao inicializar o estado de jogo, o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
};

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();
}


Game& Game::getInstance(){
	return (*instance);
}

State& Game::getState(){
	return (*state);
}

SDL_Renderer* Game::getRenderer(){
	return renderer;
}

#include <unistd.h>

void Game::run(){
	while(!(state->QuitRequested())){
		state->update();
		state->render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
