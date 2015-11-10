#ifndef _SceneManager
#define _SceneManager

#include "TEAL\CommonElements.h"

class SceneManager : public GameObject
{
public:
	SceneManager();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
private:
};

#endif _SceneManager