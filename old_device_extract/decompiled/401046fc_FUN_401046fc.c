// Function : FUN_401046fc
// Address  : 0x401046fc
// Size     : 530 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401046fc(undefined4 param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_b0 [124];
  undefined1 uStack_34;
  undefined1 uStack_33;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  bVar2 = FUN_4015aab0();
  bVar2 = bVar2 ^ 1;
  if (((_DAT_3ffc80e0 == 0x400) &&
      (iVar3 = (*(code *)&SUB_4008b33c)(0x3ffc812a,param_2,6), iVar3 == 0)) &&
     (iVar3 = (*(code *)&SUB_4008b33c)(0x3ffc80b4,param_6,param_7), iVar3 != 0)) {
    bVar2 = 0;
  }
  _DAT_3ffc80d8 = 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  puVar4 = &DAT_3ffc81f0;
  _DAT_3ffc80dc = 1 << 0x20 - (0x20 - (param_4 & 0x1f));
  _DAT_3ffc8058 = 0;
  _DAT_3ffc8050 = 0;
  _DAT_3ffc8054 = 0;
  _DAT_3ffc8120 = 0;
  _DAT_3ffc804c = 1;
  memw();
  (*(code *)&SUB_4008b3d0)(0x3ffc8124,param_1,6);
  (*(code *)&SUB_4008b3d0)(0x3ffc812a,param_2,6);
  DAT_3ffc8234 = FUN_4015a054();
  memw();
  _DAT_3ffc81e0 = (uint)(_DAT_3ffc8130 == 1);
  memw();
  (*(code *)&LAB_40185247_1)(0x3ffc7ef0);
  iVar3 = 0;
  if ((bVar2 != 0) && (iVar3 = FUN_40106748(_DAT_3ffc80ac,param_2,0,0), iVar3 != 0)) {
    bVar2 = *(uint *)(iVar3 + 0x5c) == _DAT_3ffc80e0;
  }
  iVar8 = 0x3ffc7ef0;
  if (((_DAT_3ffc80e0 & 0x3cca1) != 0) && (puVar4 = &DAT_3ffc81f0, bVar2 != 0)) {
    iVar3 = param_2;
    FUN_401067e0(0x3ffc7ef0,0,param_2,0);
    FUN_401035b4(0x3ffc7ef0);
    puVar4 = &DAT_3ffc81f0;
    iVar8 = 0x3ffc7ef0;
    goto LAB_40104808;
  }
  do {
    if (iVar3 != 0) {
      puVar1 = (undefined4 *)(iVar3 + 0x54);
      iVar3 = iVar3 + 0x14;
      FUN_401064a8(*(undefined4 *)(iVar8 + 0x1bc),0,iVar3,*puVar1);
    }
LAB_40104808:
    puVar4[0x47] = 0;
    memw();
    memw();
    iVar5 = FUN_4015a9c8();
    if (iVar5 == 0) {
      DAT_3ffc8235 = 0;
      DAT_3ffc8236 = 0;
      memw();
      *(undefined4 *)(iVar8 + 500) = 1;
LAB_40104895:
      memw();
      FUN_401043e0(0x3ffc823c);
      iVar3 = *(int *)(iVar8 + 0x220);
      iVar5 = FUN_40104a08(iVar8,*(undefined4 *)(iVar8 + 0x21c));
      if (iVar5 < 0) goto LAB_4010484e;
      iVar3 = 0x14;
      *(int *)(iVar8 + 0x220) = iVar5;
      memw();
      iVar5 = FUN_40104dcc(iVar8,auStack_b0);
      if ((iVar5 < 0) || (iVar3 = iVar5, iVar7 = FUN_401046a8(iVar8,auStack_b0), iVar7 < 0))
      goto LAB_4010484e;
      FUN_401053bc(param_2,auStack_b0,iVar5,1);
      (*(code *)&SUB_4008b530)(0x3ffc80b4,0,0x20);
      (*(code *)&SUB_4008b3d0)(0x3ffc80b4,param_6,param_7);
      *(int *)(iVar8 + 0x1e4) = param_7;
      memw();
      iVar3 = param_7;
      FUN_40104358(param_5,param_6);
      puVar4 = (undefined1 *)0x0;
    }
    else {
      uVar6 = FUN_4015a9dc();
      FUN_40146ec4(0,auStack_b0);
      puVar4[0x45] = uStack_34;
      puVar4[0x46] = uStack_33;
      memw();
      memw();
      iVar5 = FUN_40184f98(uVar6);
      *(int *)(iVar8 + 500) = iVar5;
      if (iVar5 != 1) goto LAB_40104895;
LAB_4010484e:
      puVar4 = (undefined1 *)0xffffffff;
    }
    iVar8 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
  } while( true );
}

