#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> targets;
        TargetGenerator(const TargetGenerator& src);
        TargetGenerator& operator=(const TargetGenerator& src);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& type);
        ATarget* createTarget(const std::string& type);
};

#endif