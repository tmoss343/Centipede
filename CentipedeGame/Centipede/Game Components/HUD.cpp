#include "GeneralIncludes.h"
#include "TEAL\Tools.h"
#include <sstream>

HUD* HUD::instance;

HUD::HUD()
{
	attractorHighscoreInfo = new HighscoreInformation();
	FileReader::OpenFileReadByLine("resources/HighScoreDisplayInfo.txt", attractorHighscoreInfo);

	attractorHighscoreInfoLength = 0;
}

void HUD::Update()
{
}

void HUD::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = player1Symbols.begin(); it != player1Symbols.end(); it++)
		it->Draw();

	for (it = player2Symbols.begin(); it != player2Symbols.end(); it++)
		it->Draw();
	for (it = highscoreSymbols.begin(); it != highscoreSymbols.end(); it++)
		it->Draw();
	for (it = playerLivesSymbols.begin(); it != playerLivesSymbols.end(); it++)
		it->Draw();
	for (it = attractorHighscoreInfoSymbols.begin(); it != attractorHighscoreInfoSymbols.end(); it++)
		it->Draw();
}

void HUD::SetScore(int score, bool who)
{
	Instance().strScore = Tools::ToString(score);
	Instance().DisplayScore(who);
}

void HUD::SetHighscore(int score)
{
	Instance().strScore = Tools::ToString(score);
	Instance().DisplayHighscore();
}

void HUD::DisplayScore(bool who)
{
	if(who)
	{
		//Removes previous list from the player 1 score. As to not diplay the score along with the previous score. 
		for (int i=0; i < player1ScoreLength; i++)
		{
			player1Symbols.pop_front();
		}
		nextPos = sf::Vector2f(16*3, 0);
		for (int i=strScore.length()-1; i >= 0; i--)
		{
			player1Symbols.push_front(  ScoreFont.GetGlyph((char)strScore.at(i), nextPos) );
			nextPos.x -= 16;
		}
		player1ScoreLength = strScore.length();
	}
	else
	{
		//Removes previous list from the player 2 score. As to not diplay the score along with the previous score. 
		for (int i=0; i < player2ScoreLength; i++)
		{
			player2Symbols.pop_front();
		}
		nextPos = sf::Vector2f(16*25, 0);
		for (int i=0; i < strScore.length(); i++)
		{
			player2Symbols.push_back(  ScoreFont.GetGlyph((char)strScore.at(i), nextPos) );
			nextPos.x += 16;
		}
		player2ScoreLength = strScore.length();
	}
}

void HUD::DisplayHighscore()
{
	//Removes previous list from the higscore score. As to not diplay the score along with the previous score. 
	for (int i=0; i < highscoreLength; i++)
	{
		highscoreSymbols.pop_front();
	}
	nextPos = sf::Vector2f(16*13, 0);
	for (int i=0; i < strScore.length(); i++)
	{
		highscoreSymbols.push_back( ScoreFont.GetGlyph((char)strScore.at(i), nextPos) );
		nextPos.x += 16;
	}
	highscoreLength = strScore.length();
}

void HUD::DisplayHighscoresAttractorMode()
{
	//Removes previous list from the higscore score. As to not diplay the score along with the previous score. 
	for (int i=0; i < attractorHighscoreInfoLength; i++)
	{
		attractorHighscoreInfoSymbols.pop_front();
	}
	nextPos = sf::Vector2f(16*6, 16*4);
	for (int i=0; i < attractorHighscoreInfo->pointInFileRead; i++)
	{
		nextPos.x = 16*6;
		for(int j=0; j < attractorHighscoreInfo->highscoresInformationByLine[i].length(); j++)
		{
			char tmp = attractorHighscoreInfo->highscoresInformationByLine[i].at(j);
			attractorHighscoreInfoSymbols.push_front( ScoreFont.GetGlyph((char)attractorHighscoreInfo->highscoresInformationByLine[i].at(j), nextPos) ); 
			nextPos.x += 16;
		}
		nextPos.y += 16;
		attractorHighscoreInfoLength += attractorHighscoreInfo->highscoresInformationByLine[i].length();
	}
	ScoreManager::ReReadScore();
}

bool HUD::IsInstanceOfGlyph(int i, int j)
{
	return Instance().CheckIfAtGlyph(i, j);
}

bool HUD::CheckIfAtGlyph(int i, int j)
{
	std::list<Glyph>::iterator it;
	for (it = attractorHighscoreInfoSymbols.begin(); it != attractorHighscoreInfoSymbols.end(); it++)
	{
		if(i == (int) ( (it->GetPosition().x + HalfSpriteSize) / 16.0) && j == (int) ( (it->GetPosition().y - HalfSpriteSize) / 16.0) && it->GetCellIndex() != 16)
			return true;
	}
	return false;
}

void HUD::DestructHighscoreAttractorMode()
{
	while(!Instance().attractorHighscoreInfoSymbols.empty())
	{
		Instance().attractorHighscoreInfoSymbols.pop_back();
	}
	Instance().attractorHighscoreInfoLength = 0;
}

void HUD::SetLives(int amount, bool who)
{
	if(who)
	{
		//Removes previous list from the higscore score. As to not diplay the score along with the previous score. 
		while(!Instance().playerLivesSymbols.empty())
		{
			Instance().playerLivesSymbols.pop_front();
		}
		Instance().nextPos = sf::Vector2f(16*4, 0);
		for (int i=0; i < amount; i++)
		{
			Instance().playerLivesSymbols.push_back(  Instance().BlasterFont.GetGlyph((char)Instance().strScore.at(0), Instance().nextPos) );
			Instance().nextPos.x += 16;
		}
	}
	else
	{
		//Removes previous list from the higscore score. As to not diplay the score along with the previous score. 
		while(!Instance().playerLivesSymbols.empty())
		{
			Instance().playerLivesSymbols.pop_front();
		}
		Instance().nextPos = sf::Vector2f(16*24, 0);
		for (int i=0; i < amount; i++)
		{
			Instance().playerLivesSymbols.push_back(  Instance().BlasterFont.GetGlyph((char)Instance().strScore.at(0), Instance().nextPos) );
			Instance().nextPos.x -= 16;
		}
	}
}

void HUD::SetUpHighscoresAttractorMode()
{
	Instance().DisplayHighscoresAttractorMode();
}

void HUD::UpdateTheHighscoreFile(int score, std::string name)
{
	Instance().UpdateHighscoreFile(score, name);
}

void HUD::UpdateHighscoreFile(int score, std::string name)
{
	std::string highScoreToAdd = "    " + std::to_string((long double) score) + " " + name;
	attractorHighscoreInfo->highscoresInformationByLine[ScoreManager::PlayerHighscoreUpdatePos()] = highScoreToAdd;

	std::ofstream highscoreOutput;
	highscoreOutput.open("resources/HighScoreDisplayInfo.txt");
	//highscoreOutput << "   HIGH SCORES   " << std::endl;
	for(int i = 0; i < 13; i++)
	{
		highscoreOutput << attractorHighscoreInfo->highscoresInformationByLine[i] << std::endl;
	}
	//highscoreOutput << "   CREDITS 2     "<< std::endl << "BONUS EVERY 12000";
}