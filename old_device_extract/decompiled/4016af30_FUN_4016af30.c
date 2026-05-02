// Function : FUN_4016af30
// Address  : 0x4016af30
// Size     : 372 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016af30(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  undefined1 *puVar10;
  int iVar11;
  uint local_30;
  
  local_30 = 0xc;
  iVar5 = 0x55;
  if (DAT_3ffc7e91 != '\0') {
    iVar5 = 0xe;
  }
  iVar2 = 0;
  do {
    if (DAT_3ffc7e91 == '\0') {
      iVar11 = (iVar2 + 1) * 0xc;
      uVar6 = iVar2 * 3 & 0xff;
    }
    else if (iVar2 < 0xd) {
      iVar11 = (local_30 + 1) * 0xc;
      uVar6 = local_30 * 3 & 0xff;
    }
    else {
      uVar6 = 0xfc;
      iVar11 = 0x3fc;
    }
    iVar2 = iVar2 + 1;
    uVar3 = uVar6 + 3;
    puVar10 = (undefined1 *)(param_1 + iVar11);
    do {
      uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
      _DAT_3ff4e0c4 = uVar4 & 0xffffff00 | uVar6;
      memw();
      uVar1 = (*(code *)&SUB_40084594)(0x3ff4e0c0);
      *puVar10 = uVar1;
      memw();
      uVar6 = uVar6 + 1 & 0xff;
      puVar10 = puVar10 + 4;
    } while (uVar6 != (uVar3 & 0xff));
    local_30 = local_30 + 5 & 0xff;
  } while (iVar2 != iVar5);
  puVar10 = (undefined1 *)(param_1 + 0x40c);
  puVar8 = (undefined4 *)&DAT_3ffca4c8;
  do {
    *puVar10 = (char)*puVar8;
    memw();
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 4;
  } while (puVar8 != (undefined4 *)0x3ffca58c);
  puVar10 = (undefined1 *)(param_1 + 0x4d0);
  puVar9 = (uint *)&DAT_3ffca440;
  do {
    uVar6 = 0;
    iVar5 = 4;
    puVar7 = puVar10;
    do {
      uVar3 = uVar6 & 0x1f;
      uVar6 = uVar6 + 8;
      *puVar7 = (char)(*puVar9 >> uVar3);
      memw();
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 4;
  } while (puVar9 != (uint *)&DAT_3ffca4c8);
  puVar10 = (undefined1 *)(param_1 + 0x558);
  puVar9 = (uint *)&DAT_3ffca430;
  do {
    uVar6 = 0;
    iVar5 = 4;
    puVar7 = puVar10;
    do {
      uVar3 = uVar6 & 0x1f;
      uVar6 = uVar6 + 8;
      *puVar7 = (char)(*puVar9 >> uVar3);
      memw();
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 4;
  } while (puVar9 != (uint *)&DAT_3ffca440);
  return;
}

