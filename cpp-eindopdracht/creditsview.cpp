#include "creditsview.h"
#include "gamecontext.h"

CreditsView::CreditsView(GameContext* context) : View(context)
{
}

std::ostream & CreditsView::display()
{
	return std::cout
		<< "This game was created by Tobi van Bronswijk and Rick van Berlo."
		<< std::endl
		<< "Thanks for playing!"
		<< std::endl;
}

bool CreditsView::handle_input(char c)
{
	back();
	return true;
}
