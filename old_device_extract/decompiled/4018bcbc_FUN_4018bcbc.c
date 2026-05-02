// Function : FUN_4018bcbc
// Address  : 0x4018bcbc
// Size     : 119 bytes


/* WARNING: Removing unreachable block (ram,0x4018bcfe) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018bcbc(int param_1)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  
  bVar1 = *(byte *)(param_1 + 0x182);
  sVar2 = *(short *)(param_1 + 0x184);
  iVar5 = *(int *)(param_1 + 0x28);
  uVar9 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  iVar7 = *(int *)(param_1 + 0x5c);
  uVar4 = *(uint *)(param_1 + 0x58);
  while ((CONCAT44(iVar7,uVar4) <= uVar9 ||
         ((uVar8 = uVar4 - (int)uVar9, iVar7 - (int)(uVar9 >> 0x20) == (uint)(uVar4 < uVar8) &&
          (uVar8 < 5000))))) {
    uVar8 = uVar4 + *(int *)(param_1 + 0x2c);
    iVar7 = (uint)(uVar8 < uVar4) + iVar7;
    uVar4 = uVar8;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x188);
  pcVar6 = *(code **)(_DAT_3ffc1a34 + 0xf8);
  iVar7 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  (*pcVar6)(uVar3,(uVar4 - ((uint)bVar1 * 0x20 * (int)sVar2 + iVar5)) - iVar7,0);
  return;
}

