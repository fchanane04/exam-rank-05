#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*> spells;
        SpellBook(const SpellBook& src);
        SpellBook& operator=(const SpellBook& src);
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell* spell);
        void forgetSpell(const std::string& spellName);
        ASpell* createSpell(const std::string& spellName);
};

#endif