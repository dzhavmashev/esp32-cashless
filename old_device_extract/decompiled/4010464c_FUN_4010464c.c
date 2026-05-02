// Function : FUN_4010464c
// Address  : 0x4010464c
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010464c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  (*(code *)&SUB_40094d80)(_DAT_3ffc8140);
  if ((param_1 == 0) || (param_2 == 0)) {
    _DAT_3ffc8140 = 0;
    _DAT_3ffc814c = 0;
  }
  else {
    _DAT_3ffc8140 = FUN_401052ac(param_1,param_2);
    uVar1 = 0xffffffff;
    if (_DAT_3ffc8140 == 0) goto LAB_40104681;
    memw();
    _DAT_3ffc814c = param_2;
  }
  memw();
  _DAT_3ffc80f0 = FUN_40159ff8();
  uVar1 = 0;
LAB_40104681:
  memw();
  return uVar1;
}

