//***********************************************************************************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//***********************************************************************************************************************************************************************************//
#include "ChainSyntax.h"

using namespace Dominion::Compilation::Essay;
//***********************************************************************************************************************************************************************************//
//CChainSyntax
//***********************************************************************************************************************************************************************************//
CChainSyntax::CChainSyntax() :
  CReducibleSyntax(ESyntaxType::Chain),
  _currentID(NONE_ID),
  _nextID(NONE_ID)
{
}

CChainSyntax::CChainSyntax(C_CHAIN_SYNTAX& that) :
  CReducibleSyntax(that),
  _currentID(that._currentID),
  _nextID(that._nextID)
{
}

CChainSyntax::CChainSyntax(C_CHAIN_SYNTAX&& that) :
  CReducibleSyntax(that),
  _currentID(move(that._currentID)),
  _nextID(move(that._nextID))
{
}

CChainSyntax::CChainSyntax(int32_t liveLine, C_NAMESPACE& liveNamespace, int32_t currentID, int32_t nextID) :
  CReducibleSyntax(ESyntaxType::Chain, liveLine, liveNamespace),
  _currentID(currentID),
  _nextID(nextID)
{
}

CChainSyntax::~CChainSyntax()
{
}

vector<int32_t> CChainSyntax::Pick(IContextual<ESyntaxType, CReducibleSyntax>* context) const throw()
{
  vector<int32_t> result;

  result.push_back(GetCurrentID());

  if (GetNextID() != NONE_ID)
  {
    auto sub = context->GetSyntax(GetNextID())->Pick(context);

    result.insert(result.end(), sub.begin(), sub.end());
  }

  return move(result);
}

C_CHAIN_SYNTAX& CChainSyntax::operator=(C_CHAIN_SYNTAX& that)
{
  CReducibleSyntax::operator=(that);

  _currentID = that._currentID;
  _nextID = that._nextID;

  return *this;
}

C_CHAIN_SYNTAX& CChainSyntax::operator=(C_CHAIN_SYNTAX&& that)
{
  CReducibleSyntax::operator=(that);

  _currentID = move(that._currentID);
  _nextID = move(that._nextID);

  return *this;
}
