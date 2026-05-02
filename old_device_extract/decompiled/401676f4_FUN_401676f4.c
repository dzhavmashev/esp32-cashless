// Function : FUN_401676f4
// Address  : 0x401676f4
// Size     : 178 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401676f4(int param_1,char param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_1 == 0) {
    puVar2 = (uint *)&DAT_3ff73c40;
    memw();
    uVar1 = _DAT_3ff73c40 & 0xfffffffb;
    if (param_2 != '\0') {
      uVar1 = _DAT_3ff73c40 | 4;
    }
  }
  else {
    if (param_1 != 1) {
      return;
    }
    memw();
    _DAT_3ff73104 = _DAT_3ff73104 & 0xffff;
    memw();
    if (param_2 != '\0') {
      memw();
      memw();
      _DAT_3ff73104 = param_3 | _DAT_3ff73104;
      memw();
      memw();
      _DAT_3ff730f8 = param_3 | _DAT_3ff730f8;
      memw();
      memw();
      _DAT_3ff730fc = param_3 | _DAT_3ff730fc;
      memw();
      return;
    }
    memw();
    memw();
    puVar2 = (uint *)&DAT_3ff730fc;
    memw();
    _DAT_3ff730fc = (param_3 ^ 0xffffffff) & _DAT_3ff730fc;
    memw();
    memw();
    _DAT_3ff730f8 = _DAT_3ff730f8 & (param_3 ^ 0xffffffff) | 0x5000000;
    memw();
    memw();
    uVar1 = _DAT_3ff730fc | 0x5000000;
  }
  memw();
  *puVar2 = uVar1;
  memw();
  return;
}

