#ifndef _CentipedeBodyPart
#define _CentipedeBodyPart

#include "TEAL\CommonElements.h"
#include "Enums.h"

class Mushroom;
class MushroomField;
class Bullet;
class Centipede;

class CentipedeBodyPart : public GameObject
{
public:
	//PublicFunctions
	CentipedeBodyPart();
	void Initialize(MushroomField* field, sf::Vector2f position, Centipede* theCreator, int speed, int buildNumber);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	CentipedeBodyPart* GetAncestor();
	void setAncestor(CentipedeBodyPart* olderSibling);
	void setDescendant(CentipedeBodyPart* youngerSibling);
	void RemoveAncestor();

	virtual void Collision( GameObject *go){};
	void Collision( Bullet *other );

	bool isPoisoned();

	Enumerators::centipedeMovementMode Follow(CentipedeBodyPart* olderSibling);
	//PublicVariables
	Enumerators::centipedeMovementMode currentState, previousState;

private:
	//Private Variables
	MushroomField* mushroomField;
	Centipede* creator;

	CentipedeBodyPart* ancestor;
	CentipedeBodyPart* descendant;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	sf::Vector2f  Pos, SpawnOffset;

	int centipedeBodyPartWidth, centipedeBodyPartHeight, moveDir, numberInBuildList;
	float SPEED, directionalSPEED, distanceToNextLookAhead;
	bool beenToTheEnd, turning, hasAncestor, hasDescendant, poisoned;

	//Private Functions
	sf::Vector2f getLastPosition();

	void ReRegisterCollide();
	void TransitionRow(int dir);
	void LookAhead();
	void MakeTailToHead();

	void Move();
	void Turn();
};
#endif _CentipedeBodyPart