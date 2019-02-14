#include "SolidTemperatureCoupledConstant.h"

registerMooseObject("PandaApp", SolidTemperatureCoupledConstant);

template<>
InputParameters validParams<SolidTemperatureCoupledConstant>()
{
  InputParameters params = validParams<Kernel>();

  return params;
}

SolidTemperatureCoupledConstant::SolidTemperatureCoupledConstant(const InputParameters & parameters) :
    Kernel(parameters),

    _alpha(getMaterialProperty<Real>("alpha")),
    _tf(getMaterialProperty<Real>("tf"))

{
}

Real
SolidTemperatureCoupledConstant::computeQpResidual()
{
  return 1.0e-0*_alpha[_qp]* (_u[_qp]-_tf[_qp])*_test[_i][_qp];
}

Real
SolidTemperatureCoupledConstant::computeQpJacobian()
{
  return 1.0e-0*_alpha[_qp]* _phi[_j][_qp] *_test[_i][_qp];
}

Real
SolidTemperatureCoupledConstant::computeQpOffDiagJacobian(unsigned int jvar)
{
  
//  if (jvar == _v_var)
//    return -_alpha[_qp]*_phi[_j][_qp]*_test[_i][_qp];
  return 0.0;
}

