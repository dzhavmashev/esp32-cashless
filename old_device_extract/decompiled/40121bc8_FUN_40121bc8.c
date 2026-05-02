// Function : FUN_40121bc8
// Address  : 0x40121bc8
// Size     : 145 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40121bc8(undefined4 param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = FUN_40185694();
  uVar3 = *param_2 & 0x1f;
  iVar4 = 0;
  if (uVar3 != 0) {
    iVar4 = 0x20 - uVar3;
  }
  uVar3 = *param_2 + iVar1 + iVar4;
  if (_DAT_3ffc7254 < uVar3) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc0cac,uVar2,0x3ffc0d6d);
    iVar4 = 0x101;
  }
  else {
    *param_2 = uVar3;
    memw();
    (*(code *)&SUB_4008b530)(param_1,0,0x2c);
    uVar3 = *param_2 >> 0xc;
    if ((*param_2 & 0xfff) != 0) {
      uVar3 = uVar3 + 1;
    }
    if (_DAT_3ffc7254 < uVar3 << 0xc) {
      (*(code *)&SUB_40094bc8)();
    }
    iVar4 = (*(code *)&SUB_40082300)(_DAT_3ffc56b8,_DAT_3ffc7250);
    if (iVar4 != 0) {
      uVar2 = (*(code *)&SUB_40094ae8)();
      (*(code *)&SUB_40007d54)(0x3ffc0c84,uVar2,0x3ffc0d6d,iVar4);
    }
  }
  return iVar4;
}

