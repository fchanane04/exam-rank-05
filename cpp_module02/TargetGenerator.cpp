#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

void TargetGenerator::learnTargetType(ATarget* target)
{
    this->targets.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}


void TargetGenerator::forgetTargetType(const std::string& type)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(type);
	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}


ATarget* TargetGenerator::createTarget(const std::string& type)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(type);
    if (it != targets.end())
	{
        return (it->second);
	}
    return (NULL);
}
