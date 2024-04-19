#ifndef __BODY_PART__
#define __BODY_PART__

#include "Types.hpp"

class BodyPart
{
public:
	BodyPart(int x, int y, BodyPart* next);
	~BodyPart();
	inline bool is_tail(void) { return (this->next != nullptr); }
	inline BodyPart *next_part(void) { return this->next; }
	void move(Direction direction, bool grow);
	void move(int x, int y, bool grow);
private:
	unsigned int x;
	unsigned int y;
	BodyPart* next;
};

#endif