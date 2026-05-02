// Function : FUN_40162278
// Address  : 0x40162278
// Size     : 95 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162278(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  if (DAT_3ffca1e5 != '\0') {
    _DAT_3ffca204 = (param_1 & 0xffff) << 10;
    if ((param_1 & 0xffff) == 0) {
      _DAT_3ffca204 = 0x19000;
    }
    else {
      memw();
    }
    memw();
    uStack_30 = param_3;
    uStack_2c = param_4;
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar1 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0x1b8))(_DAT_3ffca204 / 100);
    }
    local_40 = uStack_30;
    uStack_3c = uStack_2c;
    memw();
    FUN_4018b38c(param_2,&local_40,0);
  }
  return;
}

