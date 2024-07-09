#include "imp_value.hh"

ImpValue::ImpValue():type(NOTYPE) { }

ImpVType ImpValue::get_basic_type(string s) {
  ImpVType tt;
  if (s.compare("int")==0) tt = TINT;
  else if (s.compare("void")==0) tt = TVOID;
  else if (s.compare("bool")==0) tt = TBOOL;
  else tt = NOTYPE; 
  return tt;
}

void ImpValue::set_default_value(ImpVType tt) {
  type = tt;
  if (tt == TINT) {
    int_value = 0;
  } else if (tt == TBOOL) {
    bool_value = true;
  }
  return;
}

std::ostream& operator << ( std::ostream& outs, const ImpValue & v )
{
  if (v.type == TINT)
    outs << v.int_value;
  else if (v.type == TBOOL) {
    if (v.bool_value)
      outs << "true";
    else
      outs << "false";
  } else if (v.type == TVOID) {
    outs << "void";
  } else {
    outs << "NOTYPE";
  }
  return outs;
}


