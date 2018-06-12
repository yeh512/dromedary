#include "dromedaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<dromedaryApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

dromedaryApp::dromedaryApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  dromedaryApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  dromedaryApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  dromedaryApp::registerExecFlags(_factory);
}

dromedaryApp::~dromedaryApp() {}

void
dromedaryApp::registerApps()
{
  registerApp(dromedaryApp);
}

void
dromedaryApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"dromedaryApp"});
}

void
dromedaryApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"dromedaryApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
dromedaryApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
dromedaryApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
dromedaryApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
dromedaryApp__registerApps()
{
  dromedaryApp::registerApps();
}

extern "C" void
dromedaryApp__registerObjects(Factory & factory)
{
  dromedaryApp::registerObjects(factory);
}

extern "C" void
dromedaryApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  dromedaryApp::associateSyntax(syntax, action_factory);
}

extern "C" void
dromedaryApp__registerExecFlags(Factory & factory)
{
  dromedaryApp::registerExecFlags(factory);
}
