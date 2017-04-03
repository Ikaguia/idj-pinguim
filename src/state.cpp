#include <state.hpp>


State::State():quitRequested{false},bg{Sprite("img/ocean.jpg")}{
	loadAssets();
}

State::~State(){
	objectArray.clear();
}

void State::input() {
	SDL_Event event;
	int mouseX, mouseY;
	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);
	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {
		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT)quitRequested = true;
		// Se o evento for clique...
		else if(event.type == SDL_MOUSEBUTTONDOWN) {
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				Face* face = (Face*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(face->box.contains((float)mouseX, (float)mouseY)) {
					// Aplica dano
					face->Damage(rand() % 10 + 10);
					// Sai do loop (só queremos acertar um)
					break;
				}
			}
		}
		else if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if(event.key.keysym.sym == SDLK_ESCAPE)quitRequested = true;
			// Se não, crie um objeto
			else addObject((float)mouseX, (float)mouseY);
		}
	}
}

void State::addObject(float mouseX,float mouseY){
	Vec2 v(200,0);
	int ri=rand()%36000;
	float rf=ri/100.0;
	v = v.rotate(rf);
	objectArray.emplace_back(std::unique_ptr<GameObject>(new Face(v.x+mouseX,v.y+mouseY)));
}

bool State::QuitRequested(){
	return quitRequested;
}

void State::loadAssets(){}
void State::render(){
	bg.render(0,0);
	for(const auto &i:objectArray)i->render();
}
void State::update(){
	input();
	int i=0;
	while(i<objectArray.size()){
		if(objectArray[i]->isDead())objectArray.erase(objectArray.begin() + i);
		else i++;
	}
}
