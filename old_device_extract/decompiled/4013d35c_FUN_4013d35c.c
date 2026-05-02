// Function : FUN_4013d35c
// Address  : 0x4013d35c
// Size     : 122 bytes


/* WARNING: Removing unreachable block (ram,0x4013d39e) */

int FUN_4013d35c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar2 = 0;
  uVar8 = *param_1;
  iVar7 = 0x1f;
  uVar3 = 2;
  uVar4 = 4;
  uVar5 = 0;
  iVar6 = 0;
  uVar1 = 1;
  do {
    memw();
    uVar10 = (*(code *)&SUB_4000d280)
                       (uVar8 * uVar1,
                        iVar6 * uVar8 + (int)((ulonglong)uVar8 * (ulonglong)uVar1 >> 0x20),uVar4,
                        uVar5);
    uVar9 = uVar1;
    if (CONCAT44(uVar2,uVar3) <= uVar10) {
      uVar9 = uVar1 + uVar3;
      iVar6 = (uint)(uVar9 < uVar1) + iVar6 + uVar2;
    }
    uVar1 = uVar3 >> 0x1f;
    uVar3 = uVar3 << 1;
    uVar2 = uVar1 | uVar2 << 1;
    uVar1 = uVar4 >> 0x1f;
    uVar4 = uVar4 << 1;
    iVar7 = iVar7 + -1;
    uVar5 = uVar1 | uVar5 << 1;
    uVar1 = uVar9;
  } while (iVar7 != 0);
  return -uVar9;
}

