#ifndef __BODY__
#define __BODY__

#include <vector>
#include "BodyPart.hpp"
#include "Types.hpp"

class Body
{
public:
	Body(int x, int y);
	~Body(void);
	void move(Direction direction, bool grow);
private:
	BodyPart *head;
};

#endif