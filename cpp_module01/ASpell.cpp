#include "ASpell.hpp"

ASpell::ASpell(void)
{}

ASpell::ASpell(const std::string& name, const std::string& effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(const ASpell& src)
{
	*this = src;
}

ASpell& ASpell::operator=(const ASpell& src)
{
	this->name = src.name;
	this->effects = src.effects;
	return (*this);
}

ASpell::~ASpell()
{}

const std::string& ASpell::getName() const
{
	return (this->name);
}

const std::string& ASpell::getEffects() const
{
	return (this->effects);
}

void ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
