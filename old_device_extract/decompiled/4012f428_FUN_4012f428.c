// Function : FUN_4012f428
// Address  : 0x4012f428
// Size     : 366 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4012f428(int *param_1,byte *param_2,byte *param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte bStack_8a;
  byte bStack_89;
  uint uStack_88;
  byte abStack_84 [48];
  byte abStack_54 [48];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  abStack_54[1] = 0xff;
  abStack_54[0] = 0xff;
  memw();
  iVar4 = param_1[0x11];
  uStack_88 = 0;
  if ((iVar4 == 0) || (piVar6 = *(int **)(iVar4 + 0x1e4), piVar6 == (int *)0x0)) {
    piVar6 = *(int **)(*param_1 + 0xa0);
    uVar5 = 0xffff8b80;
    if (piVar6 == (int *)0x0) goto LAB_4012f4e4;
  }
  iVar7 = *piVar6;
  uVar5 = 0xffff8b80;
  if (iVar7 != 0) {
    memw();
    uVar2 = FUN_40185bb8(param_1);
    iVar7 = FUN_40186508(iVar7 + 0xcc);
    uVar10 = iVar7 + 7U >> 3;
    pbVar8 = param_2;
    if (param_1[5] != 0) {
      pbVar8 = param_2 + 2;
      uVar5 = 0xffff8400;
      if (((param_3 < pbVar8) || ((uint)*param_2 != (iVar7 + 7U >> 0xb & 0xff))) ||
         ((uint)param_2[1] != (uVar10 & 0xff))) goto LAB_4012f4e4;
    }
    uVar5 = 0xffff8400;
    if (param_3 == pbVar8 + uVar10) {
      memw();
      iVar7 = FUN_401864ec(uVar2,1);
      uVar5 = 0xffff8a00;
      if (iVar7 != 0) {
        memw();
        uVar5 = FUN_40139c80(uVar2,pbVar8,uVar10,abStack_54,&uStack_88,0x30,
                             *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
      }
    }
  }
LAB_4012f4e4:
  FUN_401858e4(*(undefined1 *)param_1[0x11],((undefined1 *)param_1[0x11])[1],
               *(undefined1 *)(*param_1 + 5),&bStack_8a);
  bVar1 = FUN_40186328((uint)(byte)(abStack_54[0] ^ bStack_8a | abStack_54[1] ^ bStack_89) |
                       uStack_88 ^ 0x30 | uVar5);
  iVar7 = (**(code **)(*param_1 + 0x4c))(*(undefined4 *)(*param_1 + 0x50),abStack_84,0x30);
  if (iVar7 == 0) {
    *(undefined4 *)(param_1[0x11] + 0x10) = 0x30;
    uVar5 = 0;
    do {
      pbVar8 = abStack_54 + uVar5;
      pbVar9 = abStack_84 + uVar5;
      iVar3 = param_4 + uVar5;
      uVar5 = uVar5 + 1;
      *(byte *)(iVar4 + iVar3 + 0x4b0) = (bVar1 ^ 0xff) & *pbVar8 | bVar1 & *pbVar9;
      memw();
    } while (uVar5 < *(uint *)(param_1[0x11] + 0x10));
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    memw();
    (*(code *)&SUB_40082ec4)();
  }
  return iVar7;
}

