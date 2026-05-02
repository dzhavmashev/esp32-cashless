// Function : FUN_4014646c
// Address  : 0x4014646c
// Size     : 119 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014646c(undefined4 param_1)

{
  int iVar1;
  
  if (_DAT_3ffc1a38 == 0) {
    _DAT_3ffc1a38 = (**(code **)(_DAT_3ffc1a34 + 0x20))();
    if (_DAT_3ffc1a38 != 0) goto LAB_40146478;
    memw();
LAB_401464e1:
    iVar1 = 0x101;
  }
  else {
LAB_40146478:
    if (_DAT_3ffc799c == 0) {
      _DAT_3ffc799c = (**(code **)(_DAT_3ffc1a34 + 0x4c))();
      if (_DAT_3ffc799c == 0) {
        memw();
        FUN_40147fe4(1,1,2,0x3f436417);
        goto LAB_401464e1;
      }
    }
    iVar1 = FUN_4014f06c(param_1);
    if (((iVar1 == 0) && (iVar1 = FUN_40168994(), iVar1 == 0)) &&
       (iVar1 = FUN_401600b8(), iVar1 == 0)) {
      iVar1 = FUN_40150404();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  FUN_40146438();
  return iVar1;
}

