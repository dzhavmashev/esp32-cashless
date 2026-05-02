// Function : FUN_4013d8c8
// Address  : 0x4013d8c8
// Size     : 134 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013d8c8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,uint param_6,char param_7)

{
  int iVar1;
  int iVar2;
  
  if (param_7 == '\0') {
    FUN_401866ec(0x3ff02000,param_4,param_6);
    memw();
    _DAT_3ff0280c = (param_6 >> 4) - 1;
    memw();
    _DAT_3ff02800 = param_5;
  }
  memw();
  FUN_401866ec(0x3ff02600,param_2,param_6);
  FUN_401866ec(&DAT_3ff02200,param_3,param_6);
  memw();
  _DAT_3ff02814 = 1;
  memw();
  _DAT_3ff02810 = 1;
  *param_1 = 1;
  memw();
  iVar1 = FUN_40131574(param_1,param_6);
  if (iVar1 == 0) {
    FUN_4013d79c();
    FUN_4013d7b8(param_1,param_6);
    iVar2 = FUN_401860ec(param_1,param_4);
    if (-1 < iVar2) {
      iVar1 = FUN_40131d30(param_1,param_1,param_4);
    }
  }
  return iVar1;
}

