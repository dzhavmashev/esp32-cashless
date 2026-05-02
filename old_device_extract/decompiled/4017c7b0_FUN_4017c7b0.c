// Function : FUN_4017c7b0
// Address  : 0x4017c7b0
// Size     : 164 bytes


ulonglong FUN_4017c7b0(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = *(int *)(param_1 + 0x10);
  puVar7 = (uint *)(param_1 + 0x14);
  puVar6 = puVar7 + iVar8 + -1;
  uVar5 = *puVar6;
  iVar1 = FUN_4017c2f8(uVar5);
  *param_2 = 0x20 - iVar1;
  if (iVar1 < 0xb) {
    uVar2 = uVar5 >> (0xbU - iVar1 & 0x1f);
    uVar3 = 0;
    if (puVar7 < puVar6) {
      uVar3 = puVar7[iVar8 + -2];
    }
    uVar5 = uVar5 << 0x20 - (0x20 - (iVar1 + 0x15U & 0x1f));
    uVar3 = uVar3 >> (0xbU - iVar1 & 0x1f);
  }
  else {
    uVar3 = 0;
    if (puVar7 < puVar6) {
      puVar6 = puVar7 + iVar8 + -2;
      uVar3 = *puVar6;
    }
    uVar9 = iVar1 - 0xb;
    if (uVar9 == 0) goto LAB_4017c84e;
    uVar2 = uVar5 << 0x20 - (0x20 - (uVar9 & 0x1f)) | uVar3 >> (0x20 - uVar9 & 0x1f);
    uVar4 = 0;
    if (puVar7 < puVar6) {
      uVar4 = puVar6[-1];
    }
    uVar5 = uVar3 << 0x20 - (0x20 - (uVar9 & 0x1f));
    uVar3 = uVar4 >> (0x20 - uVar9 & 0x1f);
  }
  uVar3 = uVar5 | uVar3;
  uVar5 = uVar2;
LAB_4017c84e:
  return CONCAT44(uVar5,uVar3) | 0x3ff0000000000000;
}

