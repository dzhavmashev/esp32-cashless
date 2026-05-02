// Function : FUN_401736ac
// Address  : 0x401736ac
// Size     : 357 bytes


undefined8 FUN_401736ac(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  
  if ((param_2 & 0x7ff00000) == 0x7ff00000) {
    uVar8 = (*(code *)&SUB_4006358c)(param_1,param_2,param_1,param_2);
    uVar8 = (*(code *)&SUB_40002590)(param_1,param_2,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
    return uVar8;
  }
  if ((int)param_2 < 1) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != 0) {
      uVar8 = (*(code *)&SUB_400026e4)(param_1,param_2,param_1,param_2);
      uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar8 = (*(code *)&SUB_40002954)((int)uVar8,uVar3,(int)uVar8,uVar3);
      return uVar8;
    }
  }
  else {
    iVar1 = (int)param_2 >> 0x14;
    if (iVar1 != 0) goto LAB_4017374b;
  }
  uVar5 = 0;
  iVar1 = 0;
  uVar7 = param_1;
  while (param_2 == 0) {
    iVar1 = iVar1 + -0x15;
    param_2 = uVar7 >> 0xb;
    uVar7 = uVar7 << 0x15;
  }
  for (; (param_2 & 0x100000) == 0; param_2 = param_2 << 1) {
    uVar5 = uVar5 + 1;
  }
  param_1 = uVar7 << 0x20 - (0x20 - (uVar5 & 0x1f));
  param_2 = uVar7 >> (-uVar5 & 0x1f) | param_2;
  iVar1 = iVar1 - (uVar5 - 1);
LAB_4017374b:
  uVar7 = param_2 & 0xfffff | 0x100000;
  if ((iVar1 - 0x3ffU & 1) != 0) {
    uVar7 = uVar7 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 << 1;
  }
  uVar5 = uVar7 * 2 - ((int)param_1 >> 0x1f);
  uVar7 = 0;
  iVar2 = 0;
  if (0x1fffff < uVar5) {
    iVar2 = 0x400000;
    uVar5 = uVar5 - 0x200000;
    uVar7 = 0x200000;
  }
  iVar6 = uVar5 * 2 - ((int)(param_1 << 1) >> 0x1f);
  param_1 = param_1 * 4;
  uVar5 = 0;
  iVar4 = iVar6 - iVar2;
  if ((iVar2 < iVar6) || ((iVar4 == 0 && (0x80000014 < param_1)))) {
    if (param_1 < 0x80000015) {
      iVar4 = iVar4 + -1;
    }
    param_1 = param_1 + 0x7fffffeb;
    uVar5 = 0x80000000;
    iVar6 = iVar4;
  }
  if ((iVar6 * 2 != (int)param_1 >> 0x1f || (param_1 & 0x7fffffff) != 0) && (uVar5 == 0xffffffff)) {
    uVar7 = uVar7 + 1;
    uVar5 = 0;
  }
  uVar5 = uVar5 >> 1;
  if ((uVar7 & 1) != 0) {
    uVar5 = uVar5 | 0x80000000;
  }
  return CONCAT44(((int)(iVar1 - 0x3ffU) >> 1) * 0x100000 + ((int)uVar7 >> 1) + 0x3fe00000,uVar5);
}

