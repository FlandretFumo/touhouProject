#include"../list/vbo/vbo.h"

class Player : public  GameObject{
public:
	Player();
	~Player();
private:
	int life = 0;
	int defaule = 5;
};
