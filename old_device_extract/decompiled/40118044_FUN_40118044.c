// Function : FUN_40118044
// Address  : 0x40118044
// Size     : 376 bytes


bool FUN_40118044(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 auStack_24 [9];
  
  iVar5 = 8;
  pbVar4 = param_1;
  while( true ) {
    uVar8 = (uint)*pbVar4;
    bVar7 = 0;
    if (uVar8 == 0) break;
    if (uVar8 == 0x3a) {
      iVar5 = iVar5 + -1;
    }
    else {
      if (uVar8 == 0x2e) {
        if ((iVar5 != 5) && (iVar5 != 2)) {
          return false;
        }
        iVar5 = iVar5 + -1;
        bVar7 = 1;
        break;
      }
      bVar7 = *(byte *)(uVar8 + 0x3ff96355) & 0x44;
      if ((*(byte *)(uVar8 + 0x3ff96355) & 0x44) == 0) break;
    }
    pbVar4 = pbVar4 + 1;
  }
  uVar11 = 0;
  uVar8 = 0;
  iVar6 = 0;
  for (; uVar9 = (uint)*param_1, uVar9 != 0; param_1 = param_1 + 1) {
    if (uVar9 == 0x3a) {
      if (param_2 != (undefined4 *)0x0) {
        puVar10 = param_2 + iVar6;
        if ((uVar8 & 1) == 0) {
          *puVar10 = uVar11 << 0x10;
          memw();
        }
        else {
          iVar6 = iVar6 + 1;
          *puVar10 = *puVar10 | uVar11;
        }
      }
      uVar9 = uVar8 + 1;
      if ((uVar8 == 5) && (bVar7 != 0)) {
        memw();
        iVar12 = FUN_40116d58(param_1 + 1,auStack_24);
        if (iVar12 != 0) {
          if (param_2 == (undefined4 *)0x0) {
            return true;
          }
          uVar3 = FUN_40109eec(auStack_24[0]);
          uVar8 = 7;
          param_2[3] = uVar3;
          goto LAB_40118108;
        }
      }
      else if (7 < uVar9) {
        return false;
      }
      uVar11 = 0;
      if (param_1[1] == 0x3a) {
        if (param_1[2] == 0x3a) {
          return false;
        }
        while (uVar9 != iVar5 + uVar8 + 1) {
          if ((uVar9 & 1) == 0) {
            if (param_2 != (undefined4 *)0x0) {
              param_2[iVar6] = 0;
              memw();
            }
          }
          else {
            iVar6 = iVar6 + 1;
          }
          uVar9 = uVar9 + 1;
          if (7 < uVar9) {
            return false;
          }
        }
        uVar11 = 0;
        param_1 = param_1 + 1;
        iVar5 = 0;
      }
    }
    else {
      bVar1 = *(byte *)(uVar9 + 0x3ff96355);
      if ((bVar1 & 0x44) == 0) break;
      iVar12 = uVar9 - 0x30;
      if (((bVar1 & 4) == 0) && (iVar12 = uVar9 - 0x37, (bVar1 & 3) == 2)) {
        iVar12 = uVar9 - 0x57;
      }
      uVar11 = uVar11 * 0x10 + iVar12;
      uVar9 = uVar8;
    }
    uVar8 = uVar9;
  }
  if (param_2 != (undefined4 *)0x0) {
    if ((uVar8 & 1) == 0) {
      uVar11 = uVar11 << 0x10;
    }
    else {
      uVar11 = param_2[iVar6] | uVar11;
    }
    param_2[iVar6] = uVar11;
    memw();
LAB_40118108:
    puVar2 = param_2;
    do {
      memw();
      uVar3 = FUN_40109eec(*puVar2);
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
    } while (puVar2 != param_2 + 4);
    *(undefined1 *)(param_2 + 4) = 0;
    memw();
  }
  memw();
  return uVar8 == 7;
}

