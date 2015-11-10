#include "GeneralIncludes.h"

Player::Player(Level* level)
{
	lives = 3;
	waveNum = 0;
	myLevel = level;

	HUD::SetLives(lives-1, true);
}

void Player::NextWave()
{
	waveNum++;
	if(waveNum > WaveManager::GetTotalWaves() - 1)
	{
		waveNum = 0;
	}
}

void Player::PlayerDeath()
{
	if(LevelManager::IsPlayerControlled())
		lives--;
	if(lives > 0)
	{
		LevelManager::EndDueToDeath();
	}
	else
	{
		LevelManager::GameOver();
	}
}

void Player::ActivatePlayer()
{
	HUD::SetLives(lives-1, LevelManager::Player1Active());
}

int Player::GetWaveNum()
{
	return waveNum;
}

int Player::GetLives()
{
	return lives;
}