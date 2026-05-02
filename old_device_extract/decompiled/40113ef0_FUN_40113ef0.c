// Function : FUN_40113ef0
// Address  : 0x40113ef0
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40113ef0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = _DAT_3ffc8424;
    if (_DAT_3ffc8424 == param_1) {
      _DAT_3ffc8424 = *(int *)(param_1 + 0x34);
    }
    else {
      do {
        iVar1 = iVar2;
        if ((iVar1 == 0) || (iVar2 = *(int *)(iVar1 + 0x34), iVar2 == 0)) goto LAB_40113f05;
      } while (iVar2 != param_1);
      *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_1 + 0x34);
      memw();
    }
LAB_40113f05:
    memw();
    FUN_4010b078(1);
  }
  return;
}

