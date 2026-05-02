// Function : FUN_401042ac
// Address  : 0x401042ac
// Size     : 81 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401042ac(undefined4 param_1,char param_2)

{
  _DAT_3ffc8130 = param_1;
  if (param_2 == '\x04') {
    _DAT_3ffc80e0 = 1;
  }
  else if (param_2 == '\n') {
    _DAT_3ffc80e0 = 0x80;
  }
  else if (param_2 == '\b') {
    _DAT_3ffc80e0 = 0x100;
  }
  else if (param_2 == '\t') {
    _DAT_3ffc80e0 = 0x400;
  }
  else if (param_2 == '\v') {
    _DAT_3ffc80e0 = 0x1000;
  }
  else if (param_2 == '\r') {
    _DAT_3ffc80e0 = 0x20000;
  }
  else {
    _DAT_3ffc80e0 = 2;
  }
  memw();
  return;
}

