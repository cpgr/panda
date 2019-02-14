#include "PandaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<PandaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

PandaApp::PandaApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PandaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PandaApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  PandaApp::registerExecFlags(_factory);
}

PandaApp::~PandaApp() {}

void
PandaApp::registerApps()
{
  registerApp(PandaApp);
}

void
PandaApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"PandaApp"});
}

void
PandaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"PandaApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
PandaApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
PandaApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
PandaApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
PandaApp__registerApps()
{
  PandaApp::registerApps();
}

extern "C" void
PandaApp__registerObjects(Factory & factory)
{
  PandaApp::registerObjects(factory);
}

extern "C" void
PandaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  PandaApp::associateSyntax(syntax, action_factory);
}

extern "C" void
PandaApp__registerExecFlags(Factory & factory)
{
  PandaApp::registerExecFlags(factory);
}
