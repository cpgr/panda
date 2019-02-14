#include "SolidTemperatureSource.h"

registerMooseObject("PandaApp", SolidTemperatureSource);

template<>
InputParameters validParams<SolidTemperatureSource>()
{
  InputParameters params = validParams<Kernel>();
  return params;
}

SolidTemperatureSource::SolidTemperatureSource(const InputParameters & parameters) :
    Kernel(parameters),

    _source_rate(getMaterialProperty<Real>("source_rate"))
{}

Real
SolidTemperatureSource::computeQpResidual()
{
  return -1.0e-0*_source_rate[_qp]*_test[_i][_qp];

}

Real
SolidTemperatureSource::computeQpJacobian()
{
  return 0.0;
}

