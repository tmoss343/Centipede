#ifndef _Level
#define _Level

class BoolField;
class Player;

class Level
{
public:
	Level();
	virtual void Intialize();

	BoolField* GetField();
	Player* GetPlayer();

	void DeactivateLevel();
	void ActivateLevel();
private:
	BoolField* field;
	Player* thePlayer;
};

#endif _Level