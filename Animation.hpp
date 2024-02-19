#pragma once

#include "Manager.hpp"

class Animation
{
public:
	struct ForAnimation
	{
		std::string forName; //имя анимации 
		std::string forTextureName; //путь к текстуре
		std::vector<sf::IntRect> forFrames; //послед координат
		sf::Time forDuration; //время проигрывания 
		bool forLooping; //выключатель цыкличного проигрывания

		ForAnimation(std::string const& name, std::string const& textureName,
			sf::Time const& duration, bool looping): forName(name), forTextureName(textureName),
			forDuration(duration), forLooping(looping){}

		void AddFrames(sf::Vector2i const& startFrom,
			sf::Vector2i const& frameSize, unsigned int frames, unsigned int traccia) { //горизонтали
			
			sf::Vector2i current = startFrom;
			for (unsigned int i = 0; i < traccia; i++)
			{
				for (unsigned int j = 0; j < frames; j++) {
					forFrames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
					current.x += frameSize.x;
				}
				current.y += frameSize.y;
				current.y = startFrom.x;
			}
		}


	};

	explicit Animation(sf::Sprite& sprite); //конструктор получает ссылку на объект

	//создание анимации
	Animation::ForAnimation& CreateAnimation(std::string const& name,
		std::string const& textureName, sf::Time const& duration,
		bool loop = false);

	//выбор правильного кадра
	void Update(sf::Time const& data);

	//меняет анимаци.
	bool SwitchAnimation(std::string const& name);

	std::string GetNameOfAnimation() const;

	//перезапуск анимации
	void restart();

	bool theEnd() const {
		return endOfAnimation;
	}

private:
	//ищет анимацию по имени 
	Animation::ForAnimation* FindAnimation(std::string const& name);

	//меняет анимацию через указатель
	void SwitchAnimation(Animation::ForAnimation* animationnn);

	sf::Sprite& forSprite;
	sf::Time forCurrentTime; //для создания пауз между кадрами
	std::list<Animation::ForAnimation> forAnim;
	Animation::ForAnimation* forCurrentAnim;
	bool endOfAnimation = false;
};

