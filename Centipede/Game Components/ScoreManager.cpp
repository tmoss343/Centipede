#include "GeneralIncludes.h"

ScoreManager* ScoreManager::instance;

ScoreManager::ScoreManager()
{
	highscoreInfo = new HighscoreTable;
	FileReader::OpenFile("resources/HighScoreDisplayInfo.txt", highscoreInfo);
}

void ScoreManager::ResetScore()
{
	Instance().player2Score = 0;
	Instance().player1Score = 0;
	HUD::SetScore(Instance().player1Score, LevelManager::Player1Active());
	HUD::SetScore(Instance().player2Score, !LevelManager::Player1Active());
}

void ScoreManager::AddScore(int v)
{
	if(LevelManager::IsPlayerControlled())
	{
		if(LevelManager::Player1Active())
		{
			Instance().player1Score += v;
			HUD::SetScore(Instance().player1Score, LevelManager::Player1Active());
		}
		else
		{
			Instance().player2Score += v;
			HUD::SetScore(Instance().player2Score, LevelManager::Player1Active());
		}
		if(Instance().player1Score > Instance().highscoreInfo->highscores[0] || Instance().player2Score > Instance().highscoreInfo->highscores[0])
		{
			Instance().highscoreInfo->highscores[0] = setHighscore();
			HUD::SetHighscore(Instance().highscoreInfo->highscores[0]);
		}
	}
}

void ScoreManager::ReReadScore()
{
	Instance().highscoreInfo = new HighscoreTable;
	FileReader::OpenFile("resources/HighScoreDisplayInfo.txt", Instance().highscoreInfo);
}

int ScoreManager::GetScore()
{
	if(LevelManager::Player1Active())
		return Instance().player1Score;
	else
		return Instance().player2Score;
}

int ScoreManager::GetHighestScore()
{
	return Instance().highscoreInfo->highscores[0];
}

int ScoreManager::setHighscore()
{
	if(LevelManager::Player1Active())
		return Instance().player1Score;
	else
		return Instance().player2Score;
}

bool ScoreManager::PlayerGetsGameOver()
{
	return Instance().GameOver();
}

bool ScoreManager::GameOver()
{
	bool tmpReturn = false;
	for(int i = 6; i >= 0; i--)//Since I know there will only ever be 7 highscores
	{
		if(GetScore() > highscoreInfo->highscores[i])
		{
			if(GetScore() == player1Score)
				highscoreInfo->highscores[i] = player1Score;
			else
				highscoreInfo->highscores[i] = player2Score;
			highscoreUpdatePos = i;
			highscoreToUpdate = highscoreInfo->highscores[i];
			tmpReturn = true;
		}
	}
	return tmpReturn;
}

int ScoreManager::GetHighscoreToUpdate()
{
	return Instance().highscoreToUpdate;
}

int ScoreManager::PlayerHighscoreUpdatePos()
{
	return Instance().highscoreUpdatePos;
}