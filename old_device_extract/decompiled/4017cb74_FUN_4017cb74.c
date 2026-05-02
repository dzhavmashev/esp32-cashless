// Function : FUN_4017cb74
// Address  : 0x4017cb74
// Size     : 359 bytes


/* WARNING: Removing unreachable block (ram,0x4017cc44) */

undefined8 FUN_4017cb74(undefined4 *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ulonglong uVar12;
  
  pbVar2 = param_2;
  do {
    pbVar8 = pbVar2;
    uVar6 = (uint)*pbVar8;
    pbVar2 = pbVar8 + 1;
    bVar7 = *(byte *)(uVar6 + 0x3ff96355) & 8;
  } while ((*(byte *)(uVar6 + 0x3ff96355) & 8) != 0);
  if (uVar6 == 0x2d) {
    uVar6 = (uint)*pbVar2;
    bVar7 = 1;
    pbVar2 = pbVar8 + 2;
  }
  else if (uVar6 == 0x2b) {
    uVar6 = (uint)*pbVar2;
    pbVar2 = pbVar8 + 2;
  }
  if ((param_4 & 0xffffffef) == 0) {
    if (uVar6 == 0x30) {
      if ((*pbVar2 & 0xdf) == 0x58) {
        uVar6 = (uint)pbVar2[1];
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
  iVar5 = (int)param_4 >> 0x1f;
  uVar12 = (*(code *)&SUB_4000cff8)(0xffffffff,0xffffffff,param_4,iVar5);
  iVar3 = (*(code *)&SUB_4000d280)(0xffffffff,0xffffffff,param_4,iVar5);
  iVar10 = 0;
  iVar9 = 0;
  uVar4 = 0;
  do {
    uVar11 = uVar6 - 0x30;
    if (9 < uVar11) {
      if (uVar6 - 0x41 < 0x1a) {
        uVar11 = uVar6 - 0x37;
      }
      else {
        if (0x19 < uVar6 - 0x61) break;
        uVar11 = uVar6 - 0x57;
      }
    }
    if ((int)param_4 <= (int)uVar11) break;
    if ((iVar10 < 0) || (uVar12 < CONCAT44(iVar9,uVar4))) {
      iVar10 = -1;
    }
    else if ((uVar12 != CONCAT44(iVar9,uVar4)) || (iVar10 = -1, (int)uVar11 <= iVar3)) {
      iVar10 = iVar5 * uVar4;
      uVar1 = (ulonglong)uVar4;
      uVar4 = uVar11 + param_4 * uVar4;
      iVar9 = (uint)(uVar4 < uVar11) +
              ((int)uVar11 >> 0x1f) + iVar10 + param_4 * iVar9 + (int)(param_4 * uVar1 >> 0x20);
      iVar10 = 1;
    }
    uVar6 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while( true );
  if (iVar10 == -1) {
    *param_1 = 0x22;
    uVar4 = 0xffffffff;
    iVar9 = -1;
    if (param_3 == (undefined4 *)0x0) goto LAB_4017cce0;
LAB_4017ccc6:
    param_2 = pbVar2 + -1;
  }
  else {
    if (bVar7 != 0) {
      uVar4 = -uVar4;
      iVar9 = -(uint)(uVar4 != 0) - iVar9;
    }
    if (param_3 == (undefined4 *)0x0) goto LAB_4017cce0;
    if (iVar10 != 0) goto LAB_4017ccc6;
  }
  *param_3 = param_2;
LAB_4017cce0:
  return CONCAT44(iVar9,uVar4);
}

