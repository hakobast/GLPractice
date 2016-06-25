//
// Created by Hakob Astvatsatryan on 6/25/16.
//

#include "Spaceship.h"

void Spaceship::update() {
	if(Input::isKeyDown(Input::Key::Up)){
		translate(Vector2(0.0f, 0.1f));
	}
	if(Input::isKeyDown(Input::Key::Down)){
		translate(Vector2(0.0f, -0.1f));
	}
	if(Input::isKeyDown(Input::Key::Right)){
		translate(Vector2(0.1f, 0.0f));
	}
	if(Input::isKeyDown(Input::Key::Left)){
		translate(Vector2(-0.1f, 0.0f));
	}

	if(Input::isKeyDown(Input::Key::D)){
		rotate(-0.1f);
	}

	if(Input::isKeyDown(Input::Key::A)){
		rotate(0.1f);
	}
}