// Function : FUN_40174600
// Address  : 0x40174600
// Size     : 372 bytes


/* WARNING: Removing unreachable block (ram,0x401746dc) */

undefined8 FUN_40174600(undefined4 *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  ulonglong uVar14;
  
  pbVar2 = param_2;
  do {
    pbVar6 = pbVar2;
    uVar8 = (uint)*pbVar6;
    pbVar2 = pbVar6 + 1;
    bVar13 = *(byte *)(uVar8 + 0x3ff96355) & 8;
  } while ((*(byte *)(uVar8 + 0x3ff96355) & 8) != 0);
  if (uVar8 == 0x2d) {
    uVar8 = (uint)*pbVar2;
    bVar13 = 1;
    pbVar2 = pbVar6 + 2;
  }
  else if (uVar8 == 0x2b) {
    uVar8 = (uint)*pbVar2;
    pbVar2 = pbVar6 + 2;
  }
  if ((param_4 & 0xffffffef) == 0) {
    if (uVar8 == 0x30) {
      if ((*pbVar2 & 0xdf) == 0x58) {
        uVar8 = (uint)pbVar2[1];
        param_4 = 0x10;
        pbVar2 = pbVar2 + 2;
      }
      else if (param_4 == 0) {
        param_4 = 8;
      }
    }
    else if (param_4 == 0) {
      param_4 = 10;
    }
  }
  uVar5 = 0;
  iVar7 = -0x80000000;
  if (bVar13 == 0) {
    uVar5 = 0xffffffff;
    iVar7 = 0x7fffffff;
  }
  iVar9 = (int)param_4 >> 0x1f;
  iVar3 = (*(code *)&SUB_4000d280)(uVar5,iVar7,param_4,iVar9);
  uVar14 = (*(code *)&SUB_4000cff8)(uVar5,iVar7,param_4,iVar9);
  iVar11 = 0;
  iVar10 = 0;
  uVar4 = 0;
  do {
    uVar12 = uVar8 - 0x30;
    if (9 < uVar12) {
      if (uVar8 - 0x41 < 0x1a) {
        uVar12 = uVar8 - 0x37;
      }
      else {
        if (0x19 < uVar8 - 0x61) break;
        uVar12 = uVar8 - 0x57;
      }
    }
    if ((int)param_4 <= (int)uVar12) break;
    if ((iVar11 < 0) || (uVar14 < CONCAT44(iVar10,uVar4))) {
      iVar11 = -1;
    }
    else if ((uVar14 != CONCAT44(iVar10,uVar4)) || (iVar11 = -1, (int)uVar12 <= iVar3)) {
      iVar11 = iVar9 * uVar4;
      uVar1 = (ulonglong)uVar4;
      uVar4 = uVar12 + param_4 * uVar4;
      iVar10 = (uint)(uVar4 < uVar12) +
               ((int)uVar12 >> 0x1f) + iVar11 + param_4 * iVar10 + (int)(param_4 * uVar1 >> 0x20);
      iVar11 = 1;
    }
    uVar8 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while( true );
  if (iVar11 == -1) {
    *param_1 = 0x22;
    uVar4 = uVar5;
    iVar10 = iVar7;
    if (param_3 == (undefined4 *)0x0) goto LAB_40174778;
LAB_4017475e:
    param_2 = pbVar2 + -1;
  }
  else {
    if (bVar13 != 0) {
      uVar4 = -uVar4;
      iVar10 = -(uint)(uVar4 != 0) - iVar10;
    }
    uVar5 = uVar4;
    iVar7 = iVar10;
    if (param_3 == (undefined4 *)0x0) goto LAB_40174778;
    if (iVar11 != 0) goto LAB_4017475e;
  }
  *param_3 = param_2;
  uVar5 = uVar4;
  iVar7 = iVar10;
LAB_40174778:
  return CONCAT44(iVar7,uVar5);
}

