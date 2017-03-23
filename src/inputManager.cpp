#include <inputManager.hpp>

InputManager::InputManager():mouseUpdate{{0}},updateCounter{0},quitRequested{false}{}
InputManager::~InputManager(){}

void InputManager::Update(){
	SDL_GetMouseState(&mouseX,&mouseY);
	quitRequested=false;

	SDL_Event event;
	while(SDL_PollEvent(&event)){	
		if(event.type==SDL_QUIT)quitRequested=true;
		else if(event.type==SDL_MOUSEBUTTONDOWN){
			if(mouseState[event.button.button]!=true){
				mouseUpdate[event.button.button]=updateCounter;
				mouseState[event.button.button]=true;
			}
		}
		else if(event.type==SDL_MOUSEBUTTONUP){
			if(mouseState[event.button.button]!=false){
				mouseUpdate[event.button.button]=updateCounter;
				mouseState[event.button.button]=false;
			}
		}
		else if(event.type==SDL_KEYDOWN){
			if(!event.key.repeat){
				keyState[event.key.keysym.sym]=true;
				keyUpdate[event.key.keysym.sym]=updateCounter;
			}
		}
		else if(event.type==SDL_KEYUP){
			keyState[event.key.keysym.sym]=false;
			keyUpdate[event.key.keysym.sym]=updateCounter;
		}
	}
	updateCounter++;
}

bool InputManager::KeyPress(int key){
	return (keyState[key] && keyUpdate[key]==updateCounter-1);
}
bool InputManager::KeyRelease(int key){
	return ((!keyState[key]) && keyUpdate[key]==updateCounter-1);
}
bool InputManager::IsKeyDown(int key){
	return (keyState[key]);
}

bool InputManager::MousePress(int button){
	return (mouseState[button] && mouseUpdate[button]==updateCounter-1);
}
bool InputManager::MouseRelease(int button){
	return ((!mouseState[button]) && mouseUpdate[button]==updateCounter-1);
}
bool InputManager::IsMouseDown(int button){
	return (mouseState[button]);
}

int InputManager::GetMouseX(){
	return mouseX;
}
int InputManager::GetMouseY(){
	return mouseY;
}

bool InputManager::QuitRequested(){
	return quitRequested;
}

InputManager& InputManager::GetInstance(){
	static InputManager uniqueInst;
	return uniqueInst;
}
