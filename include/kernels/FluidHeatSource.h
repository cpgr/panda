
#ifndef FLUIDHEATSOURCE_H
#define FLUIDHEATSOURCE_H

#include "Kernel.h"

// Forward Declaration
class FluidHeatSource;

template<>
InputParameters validParams<FluidHeatSource>();

/**
 * Simple class to demonstrate off diagonal Jacobian contributions.
 */
class FluidHeatSource : public Kernel
{
public:
  FluidHeatSource(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  virtual Real computeQpOffDiagJacobian(unsigned int jvar) override;

  const  MaterialProperty<Real> & _alpha;

  unsigned int _v_var;
  const VariableValue & _v;
};

#endif //FLUIDHEATSOURCE_H
