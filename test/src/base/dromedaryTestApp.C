//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "dromedaryTestApp.h"
#include "dromedaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<dromedaryTestApp>()
{
  InputParameters params = validParams<dromedaryApp>();
  return params;
}

dromedaryTestApp::dromedaryTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  dromedaryApp::registerObjectDepends(_factory);
  dromedaryApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  dromedaryApp::associateSyntaxDepends(_syntax, _action_factory);
  dromedaryApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  dromedaryApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    dromedaryTestApp::registerObjects(_factory);
    dromedaryTestApp::associateSyntax(_syntax, _action_factory);
    dromedaryTestApp::registerExecFlags(_factory);
  }
}

dromedaryTestApp::~dromedaryTestApp() {}

void
dromedaryTestApp::registerApps()
{
  registerApp(dromedaryApp);
  registerApp(dromedaryTestApp);
}

void
dromedaryTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
dromedaryTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
dromedaryTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
dromedaryTestApp__registerApps()
{
  dromedaryTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
dromedaryTestApp__registerObjects(Factory & factory)
{
  dromedaryTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
dromedaryTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  dromedaryTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
dromedaryTestApp__registerExecFlags(Factory & factory)
{
  dromedaryTestApp::registerExecFlags(factory);
}
