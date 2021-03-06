//*******************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//*******************************************************************************************************************//
#include "Context.h"
#include "TransactSQLSyntax.h"

using namespace Dominion::Compilation::TransactSQL;;
//*******************************************************************************************************************//
//CContext
//*******************************************************************************************************************//
CContext::CContext() :
  _entryID(NONE_ID),
  _ToVariableKey(nullptr)
{
}

CContext::CContext(C_CONTEXT& that) :
  CObject(that),
  _definedVariableMap(that._definedVariableMap),
  _syntaxVector(that._syntaxVector),
  _entryID(that._entryID),
  _ToVariableKey(that._ToVariableKey)
{
}

CContext::CContext(C_CONTEXT&& that) :
  CObject(that),
  _definedVariableMap(move(that._definedVariableMap)),
  _syntaxVector(move(that._syntaxVector)),
  _entryID(move(that._entryID)),
  _ToVariableKey(move(that._ToVariableKey))
{
}

CContext::CContext(FToVariableKey ToVariableKey) :
  _entryID(NONE_ID),
  _ToVariableKey(ToVariableKey)
{
}

CContext::~CContext()
{
  _definedVariableMap.clear();
  _syntaxVector.clear();
}

FToVariableKey CContext::ToVariableKey()
{
  return _ToVariableKey;
}

void CContext::DefineLocalVariable(WSTRING& name, int32_t initialValue)
{
  _definedVariableMap[_ToVariableKey(name)] = CSQLVariable(name, initialValue);
}

bool CContext::ExistSyntax(int32_t ID) const
{
  return ID != NONE_ID && ID < _syntaxVector.size();
}

bool CContext::DefinedLocalVariable(WSTRING& name) const
{
  return _definedVariableMap.find(_ToVariableKey(name)) != _definedVariableMap.end();
}

shared_ptr<CTransactSQLSyntax> CContext::GetSyntax(int32_t syntaxID) const
{
  if (ExistSyntax(syntaxID))
  {
    return _syntaxVector[syntaxID];
  }
  else
  {
    return shared_ptr<CTransactSQLSyntax>(nullptr);
  }
}

int32_t CContext::AppendAST(CTransactSQLSyntax* ast)
{
  _syntaxVector.push_back(shared_ptr<CTransactSQLSyntax>(ast));

  return _syntaxVector.size() - 1;
}

C_CONTEXT& CContext::operator=(C_CONTEXT& that)
{
  CObject::operator=(that);

  _definedVariableMap = that._definedVariableMap;
  _syntaxVector = that._syntaxVector;
  _entryID = that._entryID;
  _ToVariableKey = that._ToVariableKey;

  return *this;
}
