//***********************************************************************************************************************************************************************************//
//ORGANIZATION:
//AUTHOR:
//SUMMARY:
//***********************************************************************************************************************************************************************************//
#include "NullOperationValidator.h"

using namespace Dominion::Compilation::Essay;
//***********************************************************************************************************************************************************************************//
//CNullUnaryOperationValidator
//***********************************************************************************************************************************************************************************//
CNullUnaryOperationValidator::CNullUnaryOperationValidator()
{
}

CNullUnaryOperationValidator::CNullUnaryOperationValidator(C_NULL_UNARY_OPERATION_VALIDATOR& that) :
  CObject(that)
{
}

CNullUnaryOperationValidator::CNullUnaryOperationValidator(C_NULL_UNARY_OPERATION_VALIDATOR&& that) :
  CObject(that)
{
}

CNullUnaryOperationValidator::~CNullUnaryOperationValidator()
{
}

CError CNullUnaryOperationValidator::Validate(C_OPERATION_SYNTAX& syntax, C_CONTEXT& context) const
{
  CError result;

  if (syntax.GetRightOperandID() == NONE_ID)
  {
    result.SetSource(EErrorSource::Producing);
    result.SetLiveLine(syntax.GetLiveLine());
    result.SetDescription(CWStringTemplate(L"operand of operation:'%x' is invalid").Format(COperationTypeEnum(syntax.GetOperationType()).ToString()));
  }

  return move(result);
}

C_NULL_UNARY_OPERATION_VALIDATOR& CNullUnaryOperationValidator::operator= (C_NULL_UNARY_OPERATION_VALIDATOR& that)
{
  CObject::operator=(that);

  return *this;
}
//***********************************************************************************************************************************************************************************//
//CNullBinaryOperationValidator
//***********************************************************************************************************************************************************************************//
CNullBinaryOperationValidator::CNullBinaryOperationValidator()
{
}

CNullBinaryOperationValidator::CNullBinaryOperationValidator(C_NULL_BINARY_OPERATION_VALIDATOR& that) :
  CObject(that)
{
}

CNullBinaryOperationValidator::CNullBinaryOperationValidator(C_NULL_BINARY_OPERATION_VALIDATOR&& that) :
  CObject(that)
{
}

CNullBinaryOperationValidator::~CNullBinaryOperationValidator()
{
}

CError CNullBinaryOperationValidator::Validate(C_OPERATION_SYNTAX& syntax, C_CONTEXT& context) const
{
  CError result;
  auto operationType = COperationTypeEnum(syntax.GetOperationType()).ToString();

  if (syntax.GetLeftOperandID() == NONE_ID)
  {
    result.SetSource(EErrorSource::Producing);
    result.SetLiveLine(syntax.GetLiveLine());
    result.SetDescription(CWStringTemplate(L"Left operand of operation:[%x] is invalid").Format(operationType));
  }

  if (syntax.GetRightOperandID() == NONE_ID)
  {
    result.SetSource(EErrorSource::Producing);
    result.SetLiveLine(syntax.GetLiveLine());
    result.SetDescription(CWStringTemplate(L"Right operand of operation:[%x] is invalid").Format(operationType));
  }

  return move(result);
}

C_NULL_BINARY_OPERATION_VALIDATOR& CNullBinaryOperationValidator::operator=(C_NULL_BINARY_OPERATION_VALIDATOR& that)
{
  CObject::operator=(that);

  return *this;
}

C_NULL_BINARY_OPERATION_VALIDATOR& CNullBinaryOperationValidator::operator=(C_NULL_BINARY_OPERATION_VALIDATOR&& that)
{
  CObject::operator=(that);

  return *this;
}
