#include "SolidTemperatureTimeDerivative.h"

#include "Material.h"

registerMooseObject("PandaApp", SolidTemperatureTimeDerivative);

template<>
InputParameters validParams<SolidTemperatureTimeDerivative>()
{
  InputParameters params = validParams<TimeDerivative>();

  return params;
}

SolidTemperatureTimeDerivative::SolidTemperatureTimeDerivative(const InputParameters & parameters) :
    TimeDerivative(parameters),

    _porosity(getMaterialProperty<Real>("porosity")),
    _solid_density(getMaterialProperty<Real>("solid_density")),
    _cps(getMaterialProperty<Real>("cps"))
{}

Real
SolidTemperatureTimeDerivative::computeQpResidual()
{
  return 1.0e-0*(1.0-_porosity[_qp])*_solid_density[_qp]*_cps[_qp]*TimeDerivative::computeQpResidual();
}

Real
SolidTemperatureTimeDerivative::computeQpJacobian()
{
  return 1.0e-0*(1.0-_porosity[_qp])*_solid_density[_qp]*_cps[_qp]*TimeDerivative::computeQpJacobian();
}
