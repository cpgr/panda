

#include "SphereTfFunction.h"

registerMooseObject("PandaApp", SphereTfFunction);

template<>
InputParameters validParams<SphereTfFunction>()
{
  InputParameters params = validParams<Function>();
  return params;
}

SphereTfFunction::SphereTfFunction(const InputParameters & parameters) :
    Function(parameters)
{
}

Real
SphereTfFunction::value(Real t,const Point & p)
{

//  if (t <= 10)
//    return -10*t+500.0;
//  else return 400.0;

    return 750.0-45.455*p(1);

}
