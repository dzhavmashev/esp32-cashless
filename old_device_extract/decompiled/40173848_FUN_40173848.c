// Function : FUN_40173848
// Address  : 0x40173848
// Size     : 342 bytes


undefined8 FUN_40173848(uint param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  uVar5 = param_2 >> 0x14 & 0x7ff;
  uVar6 = uVar5 - 0x3ff;
  iVar1 = (int)param_2 >> 0x1f;
  if ((int)uVar6 < 0x14) {
    if ((int)uVar6 < 0) {
      if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
        return CONCAT44(param_2,param_1);
      }
      uVar5 = param_2 & 0xfffff | param_1;
      uVar3 = *(undefined4 *)(&DAT_3f425078 + iVar1 * -8);
      uVar4 = *(undefined4 *)(&DAT_3f42507c + iVar1 * -8);
      uVar8 = (*(code *)&SUB_40002590)
                        (uVar3,uVar4,param_1,
                         (-uVar5 | uVar5) >> 0xc & 0x80000 | param_2 & 0xfffe0000);
      memw();
      memw();
      memw();
      memw();
      uVar8 = (*(code *)&SUB_400026e4)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar4);
      return CONCAT44((uint)((ulonglong)uVar8 >> 0x20) & 0x7fffffff | iVar1 * -0x80000000,(int)uVar8
                     );
    }
    uVar7 = 0xfffff >> (uVar6 & 0x1f);
    if ((param_2 & uVar7) == 0 && param_1 == 0) {
      return CONCAT44(param_2,param_1);
    }
    uVar7 = uVar7 >> 1;
    bVar2 = param_1 != 0;
    param_1 = 0;
    if (bVar2 || (param_2 & uVar7) != 0) {
      param_1 = 0x80000000;
      if (uVar5 != 0x412) {
        param_1 = 0;
      }
      param_2 = (uVar7 ^ 0xffffffff) & param_2 | 0x40000 >> (uVar6 & 0x1f);
    }
  }
  else {
    if (0x33 < (int)uVar6) {
      if (uVar6 != 0x400) {
        return CONCAT44(param_2,param_1);
      }
      uVar8 = (*(code *)&SUB_40002590)(param_1,param_2,param_1,param_2);
      return uVar8;
    }
    uVar6 = 0xffffffff >> (uVar5 - 0x413 & 0x1f);
    if ((param_1 & uVar6) == 0) {
      return CONCAT44(param_2,param_1);
    }
    uVar6 = uVar6 >> 1;
    if ((param_1 & uVar6) != 0) {
      param_1 = (uVar6 ^ 0xffffffff) & param_1 | 0x40000000 >> (uVar5 - 0x413 & 0x1f);
    }
  }
  uVar3 = *(undefined4 *)(&DAT_3f425078 + iVar1 * -8);
  uVar4 = *(undefined4 *)(&DAT_3f42507c + iVar1 * -8);
  uVar8 = (*(code *)&SUB_40002590)(uVar3,uVar4,param_1,param_2);
  memw();
  memw();
  memw();
  memw();
  uVar8 = (*(code *)&SUB_400026e4)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar3,uVar4);
  return uVar8;
}

