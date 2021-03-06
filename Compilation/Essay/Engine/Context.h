//*******************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//*******************************************************************************************************************//
#pragma once

#include "Dominion/Compilation/Essay/Engine/Dependence.h"
#include "Dominion/Compilation/Essay/Engine/SyntaxType.h"

BEGIN_DOMINION_COMPILATION_ESSAY
typedef function<wstring(WSTRING&)> FToContextKey;
//*****************************************************************************************************************//
//CContext
//
//*****************************************************************************************************************//
CLASS_DECLARATION(CContext, C_CONTEXT);
class LIBRARY_EXPORT CContext : public CObject
{
public:
  static wstring DEFAULT_TO_KEY(WSTRING& input);

public:
  CLASS_INHERITOR(CObject, CContext);

public:
  CContext();
  CContext(FToContextKey ToKey);
  CContext(C_CONTEXT& that);
  CContext(C_CONTEXT&& that);
  virtual ~CContext();

public:
  void DefineVariable(EAccessType access,
                      C_NAMESPACE& liveNamespace, WSTRING& name,
                      int32_t initialValueID);
  void DefineFunction(EAccessType access,
                      C_NAMESPACE& liveNamespace,
                      WSTRING& name,
                      int32_t parameterChainID,
                      int32_t blockID);
  bool HasDefinedIdentifier(WSTRING& fullName, EIdentifierType identifierType) const;
  bool HasDefinedIdentifier(C_NAMESPACE& liveNamespace,
                            WSTRING& name,
                            EIdentifierType identifierType) const;
  bool ExistSyntax(int32_t syntaxID) const;
  shared_ptr<CAbstractSyntaxTree<ESyntaxType>> GetSyntax(int32_t id) const;
  int32_t AppendSyntax(CAbstractSyntaxTree<ESyntaxType>* syntax);
  CVariable GetVariable(WSTRING& identifier) const;
  CVariable GetVariable(C_IDENTIFIER& identifier) const;
  bool SetVariableValue(WSTRING& identifier, int valueID);
  bool SetVariableValue(C_IDENTIFIER& identifier, int valueID);

public:
  CLASS_PROPERTY(map<wstring _COMMA CVariable>, _variableMap, VariableMap);
  CLASS_PROPERTY(map<wstring _COMMA CFunction>, _functionMap, FunctionMap);
  CLASS_PROPERTY(vector<shared_ptr<CAbstractSyntaxTree<ESyntaxType>>>, _syntaxes, Syntaxes);
  CLASS_PROPERTY(int32_t, _entryID, EntryID);

  FToContextKey ToKey();

public:
  C_CONTEXT& operator=(C_CONTEXT& that);

private:
  map<wstring, CVariable> _variableMap;
  map<wstring, CFunction> _functionMap;
  vector<shared_ptr<CAbstractSyntaxTree<ESyntaxType>>> _syntaxes;
  FToContextKey _ToKey;
  int32_t _entryID;
};

END_DOMINION_COMPILATION_ESSAY
