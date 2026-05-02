// Function : FUN_40134f44
// Address  : 0x40134f44
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40134f44(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_4013d5d8(param_2,param_3,param_4);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 100) == 0) {
      iVar2 = FUN_401320e0(param_2,param_2,param_1 + 4);
      if (iVar2 == 0) {
LAB_40134f67:
        _DAT_3ffc78c0 = _DAT_3ffc78c0 + 1;
        iVar2 = iVar1;
      }
    }
    else if (((*param_2 < 0) && (iVar2 = FUN_40131ad8(param_2,0), iVar2 != 0)) ||
            (uVar3 = FUN_40131798(param_2), (uint)(*(int *)(param_1 + 0x58) << 1) < uVar3)) {
      iVar2 = -0x4f80;
    }
    else {
      iVar2 = (**(code **)(param_1 + 100))(param_2);
      param_1 = param_1 + 4;
      while (iVar2 == 0) {
        if ((-1 < *param_2) || (iVar2 = FUN_40131ad8(param_2,0), iVar2 == 0)) goto LAB_40134fd0;
        iVar2 = FUN_40131d18(param_2,param_2,param_1);
      }
    }
  }
LAB_40134f70:
  memw();
  return iVar2;
  while (iVar2 = FUN_40131bcc(param_2,param_2,param_1), iVar2 == 0) {
LAB_40134fd0:
    iVar2 = FUN_401860ec(param_2,param_1);
    if (iVar2 < 0) goto LAB_40134f67;
  }
  goto LAB_40134f70;
}

