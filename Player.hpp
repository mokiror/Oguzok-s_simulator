#pragma once
#include "Animation.hpp"

class Player
{
public:
	Player(sf::RenderWindow& window, sf::Vector2f myPosition = sf::Vector2f(90, 365),
		std::string const& texture = "C:/Users/Ћ≈–ј/Desktop/oguzokk.jpg", float time = 0.5,
		sf::Vector2i spriteSize = sf::Vector2i(100,100), int frame = 6, int step =100): window(window), position(myPosition){

		SpritePlayer.setPosition(position.x, position.y);

		//анимаци€
		auto& idleForward = AnimPlayer.CreateAnimation("idleForward", texture, sf::seconds(time), true);
		idleForward.AddFrames(sf::Vector2i(0, 0), spriteSize, frame, 1);
		auto& idleBack = AnimPlayer.CreateAnimation("idleBack", texture, sf::seconds(time), true);
		idleBack.AddFrames(sf::Vector2i(0, 0), spriteSize, frame, 1);
	
		koor.maxX = static_cast<float>(window.getSize().x);
		koor.maxY = static_cast<float>(window.getSize().y);
	}


	//измен€ют шаг игрока
	void SetStepX(float x);
	void SetStepY(float y);
	 
	//задает шаг и направление
	void Move(char diraction, float step = 1.0f);

	//перемещ€ет объект
	void Update(sf::Time const& timmme);

	//границы перемещени€
	void SetKoordinatesPlayer(float x, float y, float maxx, float maxy);

	

	int counter = 0;
	//мЄртв или нет
	void ForDead(bool playerDead) {
		
		dead = playerDead;
		counter += 1;
	}

	//возвращает текущий статус игрока
	bool getDead() const{
		return dead;
	}

	sf::Sprite& getPlayer() {
		return SpritePlayer;
	}

private:
	struct Koordinats
	{
		//переменные задающие границы объекта
		float numX;
		float numY;
		float maxX;
		float maxY;
	};

	//анимированное отображение персонажа
	sf::RenderWindow& window;
	sf::Sprite SpritePlayer;
	Animation AnimPlayer = Animation(SpritePlayer);



	//перемещение огузка
	float stepX = 0.0f;
	float stepY = 0.0f;

	Koordinats koor{ 0 };
	sf::Vector2f position; //начальные координаты
	sf::Time timeUpdate;
	bool dead = false;


};

