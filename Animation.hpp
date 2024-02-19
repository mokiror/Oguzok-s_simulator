#pragma once

#include "Manager.hpp"

class Animation
{
public:
	struct ForAnimation
	{
		std::string forName; //��� �������� 
		std::string forTextureName; //���� � ��������
		std::vector<sf::IntRect> forFrames; //������ ���������
		sf::Time forDuration; //����� ������������ 
		bool forLooping; //����������� ���������� ������������

		ForAnimation(std::string const& name, std::string const& textureName,
			sf::Time const& duration, bool looping): forName(name), forTextureName(textureName),
			forDuration(duration), forLooping(looping){}

		void AddFrames(sf::Vector2i const& startFrom,
			sf::Vector2i const& frameSize, unsigned int frames, unsigned int traccia) { //�����������
			
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

	explicit Animation(sf::Sprite& sprite); //����������� �������� ������ �� ������

	//�������� ��������
	Animation::ForAnimation& CreateAnimation(std::string const& name,
		std::string const& textureName, sf::Time const& duration,
		bool loop = false);

	//����� ����������� �����
	void Update(sf::Time const& data);

	//������ �������.
	bool SwitchAnimation(std::string const& name);

	std::string GetNameOfAnimation() const;

	//���������� ��������
	void restart();

	bool theEnd() const {
		return endOfAnimation;
	}

private:
	//���� �������� �� ����� 
	Animation::ForAnimation* FindAnimation(std::string const& name);

	//������ �������� ����� ���������
	void SwitchAnimation(Animation::ForAnimation* animationnn);

	sf::Sprite& forSprite;
	sf::Time forCurrentTime; //��� �������� ���� ����� �������
	std::list<Animation::ForAnimation> forAnim;
	Animation::ForAnimation* forCurrentAnim;
	bool endOfAnimation = false;
};

