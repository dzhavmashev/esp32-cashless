// Function : FUN_4010a0b8
// Address  : 0x4010a0b8
// Size     : 521 bytes


undefined1 FUN_4010a0b8(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  
  uVar4 = (uint)*(byte *)(param_1 * 0x128 + 0x3ffc5d6f);
  if (2 < uVar4) {
    (*(code *)&SUB_40094c54)("esponse",0x341,"","e/dns.c");
  }
  iVar7 = uVar4 * 0x18;
  if ((&DAT_3ffc5cec)[iVar7] == '\x06') {
    bVar1 = false;
    if ((((*(int *)(&DAT_3ffc5cd8 + iVar7) == 0) && (*(int *)(&DAT_3ffc5cdc + iVar7) == 0)) &&
        (*(int *)(&DAT_3ffc5ce0 + iVar7) == 0)) && (*(int *)(&DAT_3ffc5ce4 + iVar7) == 0)) {
      bVar1 = true;
    }
  }
  else {
    bVar1 = *(int *)(&DAT_3ffc5cd8 + iVar7) == 0;
  }
  if ((bVar1) && (*(char *)(param_1 * 0x128 + 0x3ffc5e75) == '\0')) {
    FUN_40109f58(param_1,0);
    (&DAT_3ffc5d6e)[param_1 * 0x128] = 0;
    memw();
    uVar2 = 0;
  }
  else {
    iVar7 = param_1 * 0x128;
    sVar3 = (*(code *)&SUB_4008c01c)(iVar7 + 0x3ffc5d74);
    iVar5 = FUN_4010bbc4(0x4a,sVar3 + 0x12,0x280);
    uVar2 = 0xff;
    if (iVar5 != 0) {
      (*(code *)&SUB_4008b530)(&uStack_2c,0,0xc);
      pcVar8 = &DAT_3ffc5d73 + iVar7;
      uStack_2c = FUN_40185288(*(undefined2 *)(&DAT_3ffc5d6c + iVar7));
      uStack_2a = 1;
      uStack_28 = 0x100;
      memw();
      memw();
      FUN_4010c020(iVar5,&uStack_2c,0xc);
      uVar4 = 0xc;
      do {
        pcVar9 = pcVar8 + 1;
        uVar6 = 0;
        for (pcVar8 = pcVar9; (*pcVar8 != '.' && (*pcVar8 != '\0')); pcVar8 = pcVar8 + 1) {
          uVar6 = uVar6 + 1 & 0xff;
        }
        if (0xfffe < uVar4 + uVar6) {
          FUN_4010bb10(iVar5);
          uVar2 = 0xfa;
          goto LAB_4010a13e;
        }
        uVar6 = uVar4 + uVar6 & 0xffff;
        memw();
        FUN_4010c180(iVar5,uVar4);
        FUN_4010c094(iVar5,pcVar9,(int)pcVar8 - (int)pcVar9 & 0xffff,uVar4 + 1 & 0xffff);
        uVar4 = uVar6 + 1 & 0xffff;
      } while (*pcVar8 != '\0');
      FUN_4010c180(iVar5,uVar4);
      param_1 = param_1 * 0x128;
      uStack_30 = 0x1c00;
      if (((&DAT_3ffc5e74)[param_1] & 0xfd) != 1) {
        uStack_30 = 0x100;
      }
      uStack_2e = 0x100;
      memw();
      memw();
      FUN_4010c094(iVar5,&uStack_30,4,uVar6 + 2 & 0xffff);
      if (*(char *)(param_1 + 0x3ffc5e75) == '\0') {
        uVar10 = 0x35;
        pcVar8 = &DAT_3ffc5cd8 + (uint)*(byte *)(param_1 + 0x3ffc5d6f) * 0x18;
      }
      else {
        uVar10 = 0x14e9;
        pcVar8 = "entry";
        if (((&DAT_3ffc5e74)[param_1] & 0xfd) != 1) {
          pcVar8 = "";
        }
      }
      uVar2 = FUN_40113c24(*(undefined4 *)(&DAT_3ffc61f4 + (uint)(byte)(&DAT_3ffc5d73)[param_1] * 4)
                           ,iVar5,pcVar8,uVar10);
      FUN_4010bb10(iVar5);
    }
  }
LAB_4010a13e:
  memw();
  return uVar2;
}

