#include "kind.h"

#include <iostream>

namespace alfc {

std::ostream& operator<<(std::ostream& o, Kind k)
{
  switch (k)
  {
    case Kind::NONE: o << "NONE"; break;
    case Kind::TYPE: o << "TYPE"; break;
    case Kind::FUNCTION_TYPE: o << "FUNCTION_TYPE"; break;
    case Kind::PROOF_TYPE: o << "PROOF_TYPE"; break;
    case Kind::ABSTRACT_TYPE: o << "ABSTRACT_TYPE"; break;
    case Kind::BOOL_TYPE: o << "BOOL_TYPE"; break;
    case Kind::QUOTE_TYPE: o << "QUOTE_TYPE"; break;
    // terms
    case Kind::APPLY: o << "APPLY"; break;
    case Kind::LAMBDA: o << "LAMBDA"; break;
    case Kind::PARAM: o << "PARAM"; break;
    case Kind::CONST: o << "CONST"; break;
    case Kind::PROGRAM_CONST: o << "PROGRAM_CONST"; break;
    case Kind::PROOF_RULE: o << "PROOF_RULE"; break;
    case Kind::VARIABLE: o << "VARIABLE"; break;
    case Kind::ORACLE: o << "ORACLE"; break;
    case Kind::TUPLE: o << "TUPLE"; break;
    case Kind::NIL: o << "NIL"; break;
    case Kind::PROGRAM: o << "PROGRAM"; break;
    case Kind::COLLECT: o << "COLLECT"; break;
    // literals
    case Kind::BOOLEAN: o << "BOOLEAN"; break;
    case Kind::NUMERAL: o << "NUMERAL"; break;
    case Kind::DECIMAL: o << "DECIMAL"; break;
    case Kind::HEXADECIMAL: o << "HEXADECIMAL"; break;
    case Kind::BINARY: o << "BINARY"; break;
    case Kind::STRING: o << "STRING"; break;
    // operations on literals
    case Kind::EVAL_IS_EQ: o << "EVAL_IS_EQ"; break;
    case Kind::EVAL_IF_THEN_ELSE: o << "EVAL_IF_THEN_ELSE"; break;
    case Kind::EVAL_REQUIRES: o << "EVAL_REQUIRES"; break;
    case Kind::EVAL_HASH: o << "EVAL_HASH"; break;
    // lists
    case Kind::EVAL_TO_LIST: o << "EVAL_TO_LIST"; break;
    case Kind::EVAL_FROM_LIST: o << "EVAL_FROM_LIST"; break;
    case Kind::EVAL_CONS: o << "EVAL_CONS"; break;
    case Kind::EVAL_APPEND: o << "EVAL_APPEND"; break;
    // boolean
    case Kind::EVAL_NOT: o << "EVAL_NOT"; break;
    case Kind::EVAL_AND: o << "EVAL_AND"; break;
    case Kind::EVAL_OR: o << "EVAL_OR"; break;
    // arithmetic
    case Kind::EVAL_ADD: o << "EVAL_ADD"; break;
    case Kind::EVAL_NEG: o << "EVAL_NEG"; break;
    case Kind::EVAL_MUL: o << "EVAL_MUL"; break;
    case Kind::EVAL_INT_DIV: o << "EVAL_INT_DIV"; break;
    case Kind::EVAL_RAT_DIV: o << "EVAL_RAT_DIV"; break;
    case Kind::EVAL_IS_NEG: o << "EVAL_IS_NEG"; break;
    case Kind::EVAL_IS_ZERO: o << "EVAL_IS_ZERO"; break;
    // strings
    case Kind::EVAL_LENGTH: o << "EVAL_LENGTH"; break;
    case Kind::EVAL_CONCAT: o << "EVAL_CONCAT"; break;
    case Kind::EVAL_EXTRACT: o << "EVAL_EXTRACT"; break;
    // conversions
    case Kind::EVAL_TO_INT: o << "EVAL_TO_INT"; break;
    case Kind::EVAL_TO_RAT: o << "EVAL_TO_RAT"; break;
    case Kind::EVAL_TO_BV: o << "EVAL_TO_BV"; break;
    case Kind::EVAL_TO_STRING: o << "EVAL_TO_STRING"; break;
    default: o << "UnknownKind(" << unsigned(k) << ")"; break;
  }
  return o;
}

std::string kindToTerm(Kind k)
{
  std::stringstream ss;
  switch (k)
  {
    case Kind::TYPE: ss << "Type"; break;
    case Kind::FUNCTION_TYPE: ss << "->"; break;
    case Kind::PROOF_TYPE: ss << "Proof"; break;
    case Kind::ABSTRACT_TYPE: ss << "?"; break;
    case Kind::BOOL_TYPE: ss << "Bool"; break;
    case Kind::QUOTE_TYPE: ss << "Quote"; break;
    case Kind::NIL: ss << "alf.nil"; break;
    // terms
    case Kind::APPLY: ss << "@"; break;
    case Kind::LAMBDA: ss << "lambda"; break;
    case Kind::PROGRAM: ss << "program"; break;
    // operations on literals
    default:
      if (isLiteralOp(k))
      {
        ss << "alf.";
        switch (k)
        {
        case Kind::EVAL_IS_EQ: ss << "is_eq"; break;
        case Kind::EVAL_IF_THEN_ELSE: ss << "ite"; break;
        case Kind::EVAL_REQUIRES: ss << "requires"; break;
        case Kind::EVAL_HASH: ss << "hash"; break;
        // lists
        case Kind::EVAL_TO_LIST: ss << "to_list"; break;
        case Kind::EVAL_FROM_LIST: ss << "from_list"; break;
        case Kind::EVAL_CONS: ss << "cons"; break;
        case Kind::EVAL_APPEND: ss << "append"; break;
        // boolean
        case Kind::EVAL_NOT: ss << "not"; break;
        case Kind::EVAL_AND: ss << "and"; break;
        case Kind::EVAL_OR: ss << "or"; break;
        // arithmetic
        case Kind::EVAL_ADD: ss << "add";break;
        case Kind::EVAL_NEG: ss << "neg";break;
        case Kind::EVAL_MUL: ss << "mul";break;
        case Kind::EVAL_INT_DIV: ss << "zdiv";break;
        case Kind::EVAL_RAT_DIV: ss << "qdiv";break;
        case Kind::EVAL_IS_NEG: ss << "is_neg";break;
        case Kind::EVAL_IS_ZERO: ss << "is_zero";break;
        // strings
        case Kind::EVAL_LENGTH: ss << "len"; break;
        case Kind::EVAL_CONCAT: ss << "concat"; break;
        case Kind::EVAL_EXTRACT: ss << "extract"; break;
        // conversions
        case Kind::EVAL_TO_INT: ss << "to_z";break;
        case Kind::EVAL_TO_RAT: ss << "to_q";break;
        case Kind::EVAL_TO_BV: ss << "to_bv";break;
        case Kind::EVAL_TO_STRING: ss << "to_str";break;
        default:ss << "[" << k << "]";break;
        }
      }
      else
      {
        ss << "[" << k << "]";
      }
      break;
  }
  return ss.str();
}

bool isSymbol(Kind k)
{
  switch(k)
  {
    case Kind::PARAM:
    case Kind::CONST:
    case Kind::PROGRAM_CONST:
    case Kind::PROOF_RULE:
    case Kind::VARIABLE:
    case Kind::ORACLE: return true; break;
    default: break;
  }
  return false;
}
bool isLiteral(Kind k)
{
  switch(k)
  {
    case Kind::BOOLEAN:
    case Kind::NUMERAL:
    case Kind::DECIMAL:
    case Kind::HEXADECIMAL:
    case Kind::BINARY:
    case Kind::STRING: return true; break;
    default: break;
  }
  return false;
}
bool isLiteralOp(Kind k)
{
  switch(k)
  {
    case Kind::EVAL_IS_EQ:
    case Kind::EVAL_IF_THEN_ELSE:
    case Kind::EVAL_REQUIRES:
    case Kind::EVAL_HASH:
    // lists
    case Kind::EVAL_TO_LIST:
    case Kind::EVAL_FROM_LIST:
    case Kind::EVAL_CONS:
    case Kind::EVAL_APPEND:
    // boolean
    case Kind::EVAL_NOT:
    case Kind::EVAL_AND:
    case Kind::EVAL_OR:
    // arithmetic
    case Kind::EVAL_ADD:
    case Kind::EVAL_NEG:
    case Kind::EVAL_MUL:
    case Kind::EVAL_INT_DIV:
    case Kind::EVAL_RAT_DIV:
    case Kind::EVAL_IS_NEG:
    case Kind::EVAL_IS_ZERO:
    case Kind::EVAL_LENGTH:
    case Kind::EVAL_CONCAT:
    case Kind::EVAL_EXTRACT:
    case Kind::EVAL_TO_INT:
    case Kind::EVAL_TO_RAT:
    case Kind::EVAL_TO_BV:
    case Kind::EVAL_TO_STRING:return true; break;
    default: break;
  }
  return false;
}

}  // namespace alfc
