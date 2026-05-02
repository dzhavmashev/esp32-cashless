// Function : FUN_4014cf74
// Address  : 0x4014cf74
// Size     : 179 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014cf74(int *param_1,char param_2,char param_3)

{
  uint uVar1;
  undefined1 uVar2;
  short sVar3;
  
  sVar3 = _DAT_3ffc8a60;
  if ((*(int *)(*param_1 + 0x14c) != 0) && (sVar3 = 0, *(int *)(*param_1 + 0x14c) == 1)) {
    sVar3 = _DAT_3ffc8a62;
  }
  uVar2 = 0;
  uVar1 = param_1[3] & 0xfff7ffff;
  param_1[3] = uVar1;
  if (sVar3 == 0x400) {
    if (param_2 == '\0' && param_3 == '\0') {
      param_1[3] = uVar1 | 0x80000;
      memw();
      uVar2 = 0;
      goto LAB_4014d01c;
    }
  }
  else if (sVar3 != 0xc00) {
    if ((sVar3 == 0) && (uVar2 = 0, param_3 == '\0')) {
      param_1[3] = uVar1 | 0x80000;
      memw();
    }
    goto LAB_4014d01c;
  }
  if (param_2 != '\0') {
    uVar2 = 1;
    param_1[3] = uVar1 | 0x80000;
  }
LAB_4014d01c:
  *(undefined1 *)((int)param_1 + 0x2f7) = uVar2;
  memw();
  memw();
  return;
}

