#include <game.hpp>

Game* Game::instance;

Game::Game(std::string title,int height,int width){
	if(instance){
		std::cout << "Erro, mais de uma instancia de 'Game' instanciada, o programa ira encerrar agora" << std::endl;
		exit(EXIT_FAILURE);
	}
	instance=this;
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
		std::string s=SDL_GetError();
		std::cout << "Erro SDL encontrado:\n" << s << std::endl << "o programa ira encerrar agora" << std::endl;
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
};

Game::~Game(){
	SDL_DestroyRenderer(renderer);
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

void Game::run(){
	while(!state->QuitRequested()){
		state->update();
		state->render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
