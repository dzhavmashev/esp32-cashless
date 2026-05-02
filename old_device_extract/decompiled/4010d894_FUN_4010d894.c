// Function : FUN_4010d894
// Address  : 0x4010d894
// Size     : 363 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_4010d894(int param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 != 0) goto LAB_4010d8ac;
  pcVar6 = "ld_addr";
  uVar4 = 0x15e;
  pcVar5 = "_listen";
  while( true ) {
    while( true ) {
      (*(code *)&SUB_40094c54)(" LISTEN",uVar4,pcVar5,pcVar6);
LAB_4010d8ac:
      iVar3 = *(int *)(param_1 + 0x3c);
      if (((param_2 != 0) && ((iVar3 == 4 || (iVar3 == 7)))) &&
         ((*(int *)(param_1 + 0xa4) != 0 || (*(short *)(param_1 + 0x54) != 0x1680)))) break;
      if (iVar3 != 1) {
        if (iVar3 != 0) {
          if (iVar3 != 2) {
            uVar1 = FUN_4010caf4(param_1);
            return uVar1;
          }
          FUN_4010d33c(&DAT_3ffc840c,param_1);
          DAT_3ffc8408 = 1;
          memw();
          memw();
          goto LAB_4010d981;
        }
        if (*(short *)(param_1 + 0x42) == 0) goto LAB_4010d981;
        iVar3 = _DAT_3ffc8410;
        if (_DAT_3ffc8410 != param_1) goto LAB_4010d990;
        _DAT_3ffc8410 = *(int *)(param_1 + 0x34);
        goto LAB_4010d97d;
      }
      pcVar5 = "_free";
      iVar3 = 1;
      do {
        iVar2 = **(int **)(pcVar5 + 4);
        while (iVar2 != 0) {
          if (param_1 == *(int *)(iVar2 + 0xa8)) {
            *(undefined4 *)(iVar2 + 0xa8) = 0;
          }
          iVar2 = *(int *)(iVar2 + 0x34);
          memw();
        }
        iVar3 = iVar3 + 1;
        pcVar5 = pcVar5 + 4;
      } while (iVar3 != 4);
      FUN_4010d33c(&DAT_3ffc841c,param_1);
      if (*(int *)(param_1 + 0x3c) != 1) {
        FUN_4010b078(3,param_1);
        return 0;
      }
      pcVar6 = "XCLOSED";
      uVar4 = 0xdf;
      pcVar5 = "own_fin";
      param_2 = 0;
    }
    param_2 = (uint)*(ushort *)(param_1 + 0x46);
    if ((*(ushort *)(param_1 + 0x46) & 0x10) != 0) break;
    pcVar6 = "lid pcb";
    uVar4 = 0x164;
    pcVar5 = "_listen";
  }
  memw();
  FUN_40110c08(param_1,*(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x50),param_1,
               param_1 + 0x18,*(undefined2 *)(param_1 + 0x42),*(undefined2 *)(param_1 + 0x44));
  FUN_4010d2e0(param_1);
  iVar3 = _DAT_3ffc840c;
  if (_DAT_3ffc840c == param_1) {
    _DAT_3ffc840c = *(int *)(param_1 + 0x34);
  }
  else {
    do {
      iVar2 = iVar3;
      if (iVar2 == 0) goto LAB_4010d91a;
      iVar3 = *(int *)(iVar2 + 0x34);
    } while (*(int *)(iVar2 + 0x34) != param_1);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(param_1 + 0x34);
    memw();
  }
LAB_4010d91a:
  iVar3 = _DAT_3ffc8420;
  DAT_3ffc8408 = 1;
  memw();
  *(undefined4 *)(param_1 + 0x34) = 0;
  if (iVar3 == param_1) {
    memw();
    FUN_4010ffac();
    return 0;
  }
  goto LAB_4010d981;
  while (iVar3 = *(int *)(iVar2 + 0x34), *(int *)(iVar2 + 0x34) != param_1) {
LAB_4010d990:
    iVar2 = iVar3;
    if (iVar2 == 0) goto LAB_4010d97d;
  }
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(param_1 + 0x34);
  memw();
LAB_4010d97d:
  *(undefined4 *)(param_1 + 0x34) = 0;
LAB_4010d981:
  memw();
  FUN_4010ca80(param_1);
  return 0;
}

