// Function : FUN_40131980
// Address  : 0x40131980
// Size     : 176 bytes


int FUN_40131980(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = FUN_40131798(param_1);
  uVar6 = iVar1 + param_2;
  uVar2 = param_2 >> 5;
  if ((uVar6 <= (uint)(*(int *)(param_1 + 4) << 5)) ||
     (iVar1 = FUN_40131574(param_1,(uint)((uVar6 & 0x1f) != 0) + (uVar6 >> 5)), iVar1 == 0)) {
    if (0x1f < param_2) {
      uVar6 = *(uint *)(param_1 + 4);
      iVar1 = (uVar6 - uVar2) * 4;
      while( true ) {
        iVar1 = iVar1 + -4;
        iVar3 = uVar6 * 4;
        if (uVar6 <= uVar2) break;
        uVar6 = uVar6 - 1;
        *(undefined4 *)(*(int *)(param_1 + 8) + iVar3 + -4) =
             *(undefined4 *)(*(int *)(param_1 + 8) + iVar1);
        memw();
      }
      while (iVar3 = iVar3 + -4, iVar3 != -4) {
        *(undefined4 *)(*(int *)(param_1 + 8) + iVar3) = 0;
        memw();
      }
    }
    if ((param_2 & 0x1f) != 0) {
      uVar6 = 0;
      for (; uVar2 < *(uint *)(param_1 + 4); uVar2 = uVar2 + 1) {
        puVar4 = (uint *)(*(int *)(param_1 + 8) + uVar2 * 4);
        uVar7 = *puVar4;
        uVar5 = uVar7 << 0x20 - (0x20 - (param_2 & 0x1f)) | uVar6;
        uVar6 = uVar7 >> (0x20 - (param_2 & 0x1f) & 0x1f);
        *puVar4 = uVar5;
      }
      memw();
    }
    iVar1 = 0;
  }
  return iVar1;
}

