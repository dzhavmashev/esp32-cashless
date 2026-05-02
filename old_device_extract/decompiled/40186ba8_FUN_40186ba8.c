// Function : FUN_40186ba8
// Address  : 0x40186ba8
// Size     : 76 bytes


char FUN_40186ba8(byte param_1)

{
  if (param_1 == 5) {
    return '\n';
  }
  if (param_1 < 6) {
    if (param_1 == 1) {
      return '\n';
    }
    if (param_1 == 0) {
      return '\v';
    }
    if (param_1 == 2) {
      return '\t';
    }
  }
  else {
    if (param_1 == 0x1f) {
      return '\0';
    }
    if (param_1 < 0x20) {
      if (param_1 == 6) {
        return '\t';
      }
    }
    else {
      if (param_1 == 0x29) {
        return '\r';
      }
      if (param_1 == 0x2a) {
        return '\f';
      }
    }
  }
  return '\x18' - param_1;
}

