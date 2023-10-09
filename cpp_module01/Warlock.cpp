#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
{
	this->name = name;
	this->title = title;
	std::cout<<name<<": This looks like another boring day."<<std::endl;
}

Warlock::~Warlock(void)
{
	std::cout<<name<<": My job here is done!"<<std::endl;
}

const std::string& Warlock::getName(void) const
{
	return (this->name);
}

const std::string& Warlock::getTitle(void) const
{
	return (this->title);
}

void Warlock::setTitle(const std::string &newTitle)
{
	this->title = newTitle;
}

void Warlock::introduce(void) const
{
	std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	this->spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

void Warlock::launchSpell(std::string spellName, ATarget& target)
{
	ASpell *launchIt;
	std::map<std::string, ASpell*>::const_iterator it = spells.find(spellName);
	if (it != spells.end())
	{
		launchIt = it->second;
		launchIt->launch(target);
	}
}
