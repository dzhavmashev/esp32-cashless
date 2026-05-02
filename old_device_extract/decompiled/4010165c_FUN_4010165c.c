// Function : FUN_4010165c
// Address  : 0x4010165c
// Size     : 178 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010165c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = _DAT_3ffc5864;
  if (*(int *)(param_1 + 0x10) == 1) {
    iVar3 = *(int *)(param_1 + 0xc);
    iVar1 = FUN_401006b0(_DAT_3ffc5864);
    if (iVar1 == 0) {
      _DAT_3ffc5864 = 0;
    }
    else {
      _DAT_3ffc5864 = iVar2;
      if (iVar2 != 0) {
        memw();
        iVar1 = FUN_40184ebc(iVar2);
        if ((iVar1 != 0) && (*(int *)(iVar3 + 0x58) < *(int *)(iVar2 + 0x58))) goto LAB_401016b0;
      }
    }
    memw();
    iVar2 = FUN_40184ebc(iVar3);
    if (iVar2 == 0) {
      return 0;
    }
    uVar4 = *(undefined4 *)(iVar3 + 0x10);
    _DAT_3ffc5864 = iVar3;
  }
  else {
    _DAT_3ffc5864 = 0;
    memw();
    FUN_40100598();
    iVar2 = 0;
    while (iVar2 = FUN_40100690(iVar2), iVar2 != 0) {
      iVar3 = FUN_40184ebc(iVar2);
      iVar1 = _DAT_3ffc5864;
      if ((iVar3 != 0) &&
         (((_DAT_3ffc5864 == 0 || (iVar3 = FUN_40184ebc(_DAT_3ffc5864), iVar3 == 0)) ||
          (*(int *)(iVar1 + 0x58) < *(int *)(iVar2 + 0x58))))) {
        memw();
        _DAT_3ffc5864 = iVar2;
      }
    }
    FUN_401005b0();
    iVar2 = _DAT_3ffc5864;
    if (_DAT_3ffc5864 == 0) {
      return 0;
    }
    iVar1 = FUN_40184ebc(_DAT_3ffc5864);
    if (iVar1 == 0) {
      return 0;
    }
LAB_401016b0:
    uVar4 = *(undefined4 *)(iVar2 + 0x10);
  }
  memw();
  FUN_4010b470(uVar4);
  return 0;
}

