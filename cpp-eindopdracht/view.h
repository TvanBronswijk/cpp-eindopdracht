#pragma once
#include <iostream>

class GameContext;
class View
{
protected:
	GameContext* context;
	void back();
public:
	View(GameContext* context);

	///<summary>
	///Prints the <c>View</c>s text to <c>cout</c>.
	///</summary>
	///<returns>The <c>cout</c> stream.</returns>
	virtual std::ostream& display() = 0;

	///<summary>
	///Handles the input from <c>cin</c>.
	///</summary>
	///<returns><c>true</c> if input handled correctly, otherwise <c>false</c>.</returns>
	virtual bool handle_input() = 0;

	virtual ~View();
};