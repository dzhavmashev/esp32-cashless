// Function : FUN_4014a350
// Address  : 0x4014a350
// Size     : 494 bytes


undefined1 * FUN_4014a350(undefined1 *param_1,int *param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  ushort uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  
  if ((param_2 != (int *)0x0) && (iVar2 = *param_2, iVar2 != 0)) {
    uVar8 = *(ushort *)(iVar2 + 0x160) & 0xfffd;
    uVar12 = *(uint *)(iVar2 + 0x158);
    if ((uVar12 & 0x1000000) != 0) {
      uVar8 = *(ushort *)(iVar2 + 0x160) | 2;
    }
    iVar6 = 0;
    bVar10 = 0;
    if (*(int *)(iVar2 + 0x14c) == 0) {
      uVar9 = *(ushort *)(iVar2 + 0x15c);
      bVar5 = *(byte *)((int)param_2 + 0x15e);
      uVar3 = uVar9 & 3;
      uVar11 = bVar5 & 3;
      bVar10 = (uVar11 < uVar3) * (char)uVar11 + (uVar11 >= uVar3) * (char)uVar3;
      iVar6 = (int)(uVar9 & 0x1c) >> 2;
      if ((uVar9 >> 2 & 0x1c) < (bVar5 >> 2 & 0x1c)) {
        iVar6 = (int)(bVar5 & 0x1c) >> 2;
      }
    }
    uVar9 = uVar8 | 0x20;
    if ((uVar12 & 0x4000000) == 0) {
      uVar9 = uVar8 & 0xffdf;
    }
    if (((uVar12 & 0x8000000) == 0) || (uVar8 = uVar9 | 0x40, (uVar9 & 2) == 0)) {
      uVar8 = uVar9 & 0xffbf;
    }
    *param_1 = (char)uVar8;
    puVar4 = param_1 + 3;
    param_1[1] = (char)(uVar8 >> 8);
    param_1[2] = (byte)(iVar6 << 2) | bVar10;
    memw();
    memw();
    (*(code *)&SUB_4008b530)(puVar4,0,0x17);
    uVar12 = 0;
    iVar6 = *param_2;
    while ((int)uVar12 < (int)((uint)*(byte *)(iVar6 + 0x166) << 3)) {
      iVar7 = (int)uVar12 >> 3;
      uVar3 = uVar12 & 7;
      uVar12 = uVar12 + 1;
      puVar4[iVar7] = (byte)(1 << 0x20 - (0x20 - uVar3)) | puVar4[iVar7];
      memw();
    }
    if (((*(uint *)(iVar6 + 0x158) & 0x1000000) != 0) &&
       ((*(uint *)(iVar6 + 0x160) & 0x400000) != 0)) {
      param_1[7] = param_1[7] | 1;
      memw();
    }
    if ((*(uint *)(iVar6 + 0x160) & 0x200000) != 0) {
      if (1 < *(byte *)(iVar6 + 0x166)) {
        param_1[7] = param_1[7] | 2;
        memw();
        memw();
      }
      if (2 < *(byte *)(iVar6 + 0x166)) {
        param_1[7] = param_1[7] | 0x80;
        memw();
        memw();
      }
      if (3 < *(byte *)(iVar6 + 0x167)) {
        param_1[9] = param_1[9] | 0x20;
        memw();
        memw();
      }
    }
    if (*(char *)(iVar6 + 0x166) == *(char *)(iVar6 + 0x167)) {
      bVar10 = 1;
      memw();
    }
    else {
      bVar5 = (*(char *)(iVar6 + 0x167) + -1) * '\x04';
      bVar10 = bVar5 | 3;
      if ((*(uint *)(iVar6 + 0x160) & 0x800000) != 0) {
        bVar10 = bVar5 | 0x13;
      }
    }
    param_1[0xf] = bVar10;
    memw();
    uVar1 = *(undefined2 *)(iVar2 + 0x164);
    param_1[0x13] = (char)uVar1;
    param_1[0x14] = (char)((ushort)uVar1 >> 8);
    memw();
    memw();
    return param_1 + 0x1a;
  }
  FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x821);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

