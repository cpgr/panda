#ifndef SOLIDTEMPERATURECOUPLEDCONSTANT_H
#define SOLIDTEMPERATURECOUPLEDCONSTANT_H

#include "Kernel.h"

// Forward Declaration
class SolidTemperatureCoupledConstant;

template<>
InputParameters validParams<SolidTemperatureCoupledConstant>();

/**
 * Simple class to demonstrate off diagonal Jacobian contributions.
 */
class SolidTemperatureCoupledConstant : public Kernel
{
public:
  SolidTemperatureCoupledConstant(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const  MaterialProperty<Real> & _alpha;
  const  MaterialProperty<Real> & _tf;

};

#endif //SOLIDTEMPERATURECOUPLEDCONSTANT_H
