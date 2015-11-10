#ifndef _BoolField
#define _BoolField

//Basically a mushroomfield of bools for the player to keep track of what has spawned where and so the level manager can manager only one blaster. 
class BoolField
{
public:
	BoolField();
	bool GetInfoAtField(int i, int j);
	void AddInstance(int i, int j);
	void SetInstance(int i, int j, bool what);

private:
	int spawnChance;

	bool** field;
};

#endif _BoolField