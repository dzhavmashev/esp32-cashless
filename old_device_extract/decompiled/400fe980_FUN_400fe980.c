// Function : FUN_400fe980
// Address  : 0x400fe980
// Size     : 241 bytes


int FUN_400fe980(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int aiStack_24 [9];
  
  if (((int)param_4 < (int)param_3 || 0x40 < param_4) || (0x40 < param_3)) {
LAB_400fea14:
    iVar1 = 0x102;
  }
  else {
    aiStack_24[0] = -1;
    memw();
    iVar1 = FUN_400fe884(&DAT_3f42161d,0xffffffff,param_1,param_2,aiStack_24);
    if (iVar1 == 0) {
      (*(code *)&SUB_40086460)(0x3ffc5800);
      iVar2 = param_3 * 3 + 0x3ffbdd4c;
      uVar4 = param_3;
      iVar6 = iVar2;
LAB_400fe9d7:
      if ((int)uVar4 < (int)param_4) {
        if (*(char *)(iVar6 + 1) == -1) goto LAB_400fea50;
        puVar3 = (undefined4 *)(uVar4 * 4 + 0x3ffc5808);
        (*(code *)&SUB_40094d80)(*puVar3);
        *puVar3 = 0;
        while ((int)param_3 < (int)uVar4) {
          if (*(char *)(iVar2 + 1) == aiStack_24[0]) {
            (*(code *)&SUB_4008b530)(param_3 * 3 + 0x3ffbdd4c,0,3);
            *(undefined1 *)(iVar2 + 1) = 0xff;
            *(undefined1 *)(iVar2 + 2) = 0xff;
            memw();
          }
          param_3 = param_3 + 1;
          iVar2 = iVar2 + 3;
          memw();
        }
        memw();
        (*(code *)&SUB_400864a0)(0x3ffc5800);
        goto LAB_400fea14;
      }
      (*(code *)&SUB_400864a0)(0x3ffc5800);
    }
  }
  return iVar1;
LAB_400fea50:
  pbVar5 = (byte *)(uVar4 * 3 + 0x3ffbdd4c);
  *pbVar5 = *pbVar5 | 1;
  *(char *)(iVar6 + 2) = (char)uVar4;
  uVar4 = uVar4 + 1;
  *(undefined1 *)(iVar6 + 1) = (undefined1)aiStack_24[0];
  memw();
  iVar6 = iVar6 + 3;
  memw();
  goto LAB_400fe9d7;
}

