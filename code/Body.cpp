
#include "Body.hpp"
#include "BodyPart.hpp"
#include "Types.hpp"

Body::Body(int x, int y)
{
	this->head = new BodyPart(x, y, nullptr);
}

Body::~Body(void)
{
	BodyPart* nextPart = nullptr;
	do
	{
		nextPart = this->head->next_part();
		delete this->head;
		this->head = nextPart;
	} while (this->head->is_tail());
}

void Body::move(Direction direction, bool grow)
{
	this->head->move(direction, grow);
}
