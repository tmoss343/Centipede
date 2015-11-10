#ifndef _Player
#define _Player

class Blaster;
class Level;

class Player
{
public:
	Player(Level* level);

	void NextWave();
	void PlayerDeath();

	void ActivatePlayer();

	int GetWaveNum();
	int GetLives();

private:
	int lives;
	int waveNum;
	Level* myLevel;

};

#endif _Player