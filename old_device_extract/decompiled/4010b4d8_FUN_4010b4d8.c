// Function : FUN_4010b4d8
// Address  : 0x4010b4d8
// Size     : 145 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010b4d8(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    if (param_1[1] != 0) {
      FUN_4010b08c(param_1 + 1,0);
    }
    if ((*(byte *)((int)param_1 + 0xeb) & 0x20) != 0) {
      FUN_401162b8(param_1);
    }
    iVar2 = 0;
    do {
      if ((*(byte *)((int)param_1 + iVar2 + 0x94) & 0x10) != 0) {
        FUN_4010b08c(param_1 + iVar2 * 6 + 0x13,0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 3);
    FUN_401184fc(param_1);
    if ((*(byte *)((int)param_1 + 0xeb) & 1) != 0) {
      FUN_4010b4ac(param_1);
    }
    FUN_40114fd8(param_1);
    if (_DAT_3ffc8400 == param_1) {
      _DAT_3ffc8400 = (int *)0x0;
    }
    piVar1 = _DAT_3ffc83fc;
    if (_DAT_3ffc83fc == param_1) {
      _DAT_3ffc83fc = (int *)*param_1;
    }
    else {
      do {
        piVar3 = piVar1;
        if (piVar3 == (int *)0x0) goto LAB_4010b550;
        piVar1 = (int *)*piVar3;
      } while ((int *)*piVar3 != param_1);
      *piVar3 = *param_1;
      memw();
    }
  }
LAB_4010b550:
  memw();
  return;
}

