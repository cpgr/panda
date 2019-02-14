

#include "SolidTemperatureDiffusion.h"

registerMooseObject("PandaApp", SolidTemperatureDiffusion);

template<>
InputParameters validParams<SolidTemperatureDiffusion>()
{
  InputParameters params = validParams<Diffusion>();
  return params;
}


SolidTemperatureDiffusion::SolidTemperatureDiffusion(const InputParameters & parameters) :
    Diffusion(parameters),

    _ks(getMaterialProperty<Real>("ks"))
{}

Real
SolidTemperatureDiffusion::computeQpResidual()
{

  return 1.0e-0*_ks[_qp]*Diffusion::computeQpResidual();

}

Real
SolidTemperatureDiffusion::computeQpJacobian()
{

  return 1.0e-0*_ks[_qp]*Diffusion::computeQpJacobian();
}
