#pragma once
#include <iostream>
#include <iomanip>

class GameContext;
class View
{
protected:
	GameContext* context;

	///<summary>
	///Pop the view from the view stack.
	///</summary>
	///<returns><c>true</c> if the action is successfull</returns>
	bool back();


	///<summary>
	///Handles the input from <c>cin</c>.
	///</summary>
	///<returns><c>true</c> if input handled correctly, otherwise <c>false</c>.</returns>
	virtual bool handle_input(char c) = 0;
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
	virtual bool handle_input();

	virtual ~View();
};