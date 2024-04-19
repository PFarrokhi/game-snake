
#include "BodyPart.hpp"
#include "Types.hpp"

BodyPart::BodyPart(int x, int y, BodyPart* next)
	: x(x), y(y), next(next)
{

}

BodyPart::~BodyPart()
{
	if (this->is_tail())
		delete this->next;
}

void BodyPart::move(Direction direction, bool grow)
{
	if (not this->is_tail())
		this->next->move(this->x, this->y, grow);
	else if(grow)
		this->next = new BodyPart(x, y, nullptr);

	switch (direction)
	{
	case Direction::up:
		this->x++;
	case Direction::down:
		this->x--;
	case Direction::right:
		this->y++;
	case Direction::left:
		this->y--;
	}
}

void BodyPart::move(int x, int y, bool grow)
{
	if (not this->is_tail())
		this->next->move(this->x, this->y, grow);
	else if (grow)
		this->next = new BodyPart(x, y, nullptr);

	this->x = x;
	this->y = y;
}