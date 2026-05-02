// Function : FUN_4016b2d4
// Address  : 0x4016b2d4
// Size     : 591 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4016b2d4(int param_1,int param_2,byte param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  memw();
  if ((param_1 == 0) || (DAT_3ffc7e6d == '\x01')) {
    FUN_4018f734();
    return 0;
  }
  DAT_3ffc7e6f = 1;
  memw();
  DAT_3ffc7e6e = 1;
  memw();
  if (DAT_3ffc7e6d == '\0') {
    FUN_4016ac14();
    FUN_4016b224();
  }
  (*(code *)&SUB_400899d0)();
  _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfffffeff;
  memw();
  FUN_4018f628();
  if (DAT_3ffc7e6d == '\0') {
    bVar1 = false;
    if (param_3 < 2) {
      iVar3 = FUN_40186d94(1,param_2,param_1);
      if (iVar3 == 0) {
        bVar2 = (bool)((param_3 ^ 1) & 1);
        bVar1 = true;
      }
      else {
        bVar2 = true;
        param_3 = 2;
      }
    }
    else {
      bVar2 = true;
      iVar3 = 0;
    }
    FUN_4016a944(param_1);
    if (DAT_3ffca5eb == '\x01') {
      _DAT_3ffca42c = 0x138;
      memw();
    }
    else {
      _DAT_3ffca42c = 0x120;
      memw();
    }
    DAT_3ffc0738 = DAT_3ffca5c6;
    memw();
    if ((bool)(bVar1 & DAT_3ffc7e6d == '\0')) {
      FUN_4016ae7c(param_2);
      bVar1 = true;
    }
    uVar4 = _DAT_3ffca4c8;
    if (DAT_3ffc7e6d == '\0') {
      if (param_3 == 0) {
        uVar4 = 0x200008;
      }
      else {
        uVar4 = 8;
        if (param_3 == 1) {
          if ((_DAT_3ffca4c8 & 0x10) == 0) {
            uVar4 = _DAT_3ffca4c8 & 0xfffeddd7 | 8;
          }
          else {
            _DAT_3ffca4c8 = _DAT_3ffca4c8 & 0xfffeddd7;
            FUN_4016e5d8(param_2 + 0xc);
            uVar4 = _DAT_3ffca4c8;
          }
        }
      }
    }
  }
  else {
    bVar1 = param_3 < 2;
    iVar3 = 0;
    bVar2 = param_3 != 1;
    uVar4 = _DAT_3ffca4c8;
  }
  _DAT_3ffca4c8 = uVar4;
  FUN_4016f56c();
  FUN_4016a87c();
  if ((DAT_3ffc7e6d == '\0') && (bVar2 != false)) {
    FUN_4016af30(param_2);
    FUN_40186d94(0,param_2,param_1);
  }
  if (DAT_3ffc7e6d == '\x01') {
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x65,4,0,99);
    FUN_4016f888((int)DAT_3ffca519,10);
    (*(code *)&SUB_4008a288)(0);
  }
  else {
    if (bVar1) {
      FUN_4016f888((int)DAT_3ffca519,10);
    }
    if (DAT_3ffca606 != '\0') {
      FUN_4016f984(0);
    }
  }
  (**(code **)(_DAT_3ffc7e64 + 0x98))(99,0);
  if (DAT_3ffc7e6d == '\0') {
    DAT_3ffc7e8a = (*(code *)&SUB_40089f90)();
    memw();
    DAT_3ffc7e8b = DAT_3ffc7e8a;
  }
  DAT_3ffc7e6d = 1;
  memw();
  DAT_3ffc7e6e = 0;
  DAT_3ffc7e6f = 0;
  memw();
  (*(code *)&SUB_40089b34)();
  (*(code *)&SUB_400881f8)();
  if (DAT_3ffc7e69 != '\0') {
    uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff5c080);
    memw();
    _DAT_3ff5c080 = uVar4 | 0xc0;
    return iVar3;
  }
  return iVar3;
}

