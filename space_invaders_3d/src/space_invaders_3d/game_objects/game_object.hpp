#ifndef SPACE_INVADERS_3D_GAME_OBJECTS_GAME_OBJECT_HPP
#define SPACE_INVADERS_3D_GAME_OBJECTS_GAME_OBJECT_HPP

class game_object {
public:
	virtual void on_update(float dt) = 0;
};

#endif // !SPACE_INVADERS_3D_GAME_OBJECTS_GAME_OBJECT_HPP