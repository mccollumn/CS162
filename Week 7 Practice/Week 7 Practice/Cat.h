#pragma once

class Cat
{
public:
	Cat();
	~Cat();
	void feed(int foodWeightLbs);
private:
	int weightLbs;
	bool alive;
	int* testPtr;
};

