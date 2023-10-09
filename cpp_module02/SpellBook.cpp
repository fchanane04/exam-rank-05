#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell* spell)
{
    this->spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
	{
        return (it->second);
	}
    return (NULL);
}