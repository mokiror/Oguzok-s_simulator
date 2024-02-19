#pragma once
#include "Animation.hpp"

class Player
{
public:
	Player(sf::RenderWindow& window, sf::Vector2f myPosition = sf::Vector2f(90, 365),
		std::string const& texture = "C:/Users/����/Desktop/oguzokk.jpg", float time = 0.5,
		sf::Vector2i spriteSize = sf::Vector2i(100,100), int frame = 6, int step =100): window(window), position(myPosition){

		SpritePlayer.setPosition(position.x, position.y);

		//��������
		auto& idleForward = AnimPlayer.CreateAnimation("idleForward", texture, sf::seconds(time), true);
		idleForward.AddFrames(sf::Vector2i(0, 0), spriteSize, frame, 1);
		auto& idleBack = AnimPlayer.CreateAnimation("idleBack", texture, sf::seconds(time), true);
		idleBack.AddFrames(sf::Vector2i(0, 0), spriteSize, frame, 1);
	
		koor.maxX = static_cast<float>(window.getSize().x);
		koor.maxY = static_cast<float>(window.getSize().y);
	}


	//�������� ��� ������
	void SetStepX(float x);
	void SetStepY(float y);
	 
	//������ ��� � �����������
	void Move(char diraction, float step = 1.0f);

	//���������� ������
	void Update(sf::Time const& timmme);

	//������� �����������
	void SetKoordinatesPlayer(float x, float y, float maxx, float maxy);

	

	int counter = 0;
	//���� ��� ���
	void ForDead(bool playerDead) {
		
		dead = playerDead;
		counter += 1;
	}

	//���������� ������� ������ ������
	bool getDead() const{
		return dead;
	}

	sf::Sprite& getPlayer() {
		return SpritePlayer;
	}

private:
	struct Koordinats
	{
		//���������� �������� ������� �������
		float numX;
		float numY;
		float maxX;
		float maxY;
	};

	//������������� ����������� ���������
	sf::RenderWindow& window;
	sf::Sprite SpritePlayer;
	Animation AnimPlayer = Animation(SpritePlayer);



	//����������� ������
	float stepX = 0.0f;
	float stepY = 0.0f;

	Koordinats koor{ 0 };
	sf::Vector2f position; //��������� ����������
	sf::Time timeUpdate;
	bool dead = false;


};

