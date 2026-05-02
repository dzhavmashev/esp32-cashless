// Function : FUN_40161a3c
// Address  : 0x40161a3c
// Size     : 69 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40161a3c(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  uVar2 = 1;
  if (iVar1 != 0) {
    if ((param_2 < _DAT_3ffca244) || ((_DAT_3ffca244 == param_2 && (param_1 < _DAT_3ffca240)))) {
      if (_DAT_3ffca244 - param_2 != (uint)(_DAT_3ffca240 < _DAT_3ffca240 - param_1)) {
        return 1;
      }
      if (param_3 <= _DAT_3ffca240 - param_1) {
        return 1;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

