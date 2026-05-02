// Function : FUN_401140b4
// Address  : 0x401140b4
// Size     : 259 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401140b4(int param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  
  iVar6 = *(int *)(param_1 + 200);
  *(undefined4 *)(iVar6 + 0x40) = 0;
  *(undefined4 *)(iVar6 + 0x44) = 0;
  if (DAT_3ffc842b != '\0') {
    *(undefined4 *)(iVar6 + 0x48) = _DAT_3ffc8444;
  }
  uVar7 = _DAT_3ffc8448;
  if (DAT_3ffc842c == '\0') {
    uVar7 = *(uint *)(iVar6 + 0x48) >> 1;
  }
  *(uint *)(iVar6 + 0x4c) = uVar7;
  if ((DAT_3ffc8430 != '\0') && (_DAT_3ffc8458 < *(ushort *)(param_1 + 0xe0))) {
    *(short *)(param_1 + 0xe0) = (short)_DAT_3ffc8458;
    memw();
  }
  uVar7 = _DAT_3ffc844c;
  if (DAT_3ffc842d == '\0') {
    uVar7 = (uint)(*(int *)(iVar6 + 0x48) * 7) >> 3;
  }
  *(uint *)(iVar6 + 0x50) = uVar7;
  cVar2 = DAT_3ffc842e;
  *(undefined4 *)(iVar6 + 0x3c) = *(undefined4 *)(param_2 + 0x10);
  if (cVar2 != '\0') {
    memw();
    uVar3 = FUN_40109eec(_DAT_3ffc8450);
    *(undefined4 *)(iVar6 + 0x40) = uVar3;
  }
  *(bool *)(iVar6 + 7) = cVar2 != '\0';
  memw();
  if (DAT_3ffc842f != '\0') {
    memw();
    uVar3 = FUN_40109eec(_DAT_3ffc8454);
    *(undefined4 *)(iVar6 + 0x44) = uVar3;
  }
  bVar1 = DAT_3ffc8434 != '\0';
  if (bVar1) {
    memw();
    uStack_3c = FUN_40109eec(_DAT_3ffc8468);
  }
  memw();
  FUN_4011dad8(bVar1,&uStack_3c);
  puVar4 = &DAT_3ffc8428;
  puVar5 = &DAT_3ffc8438;
  iVar6 = 0;
  do {
    if (puVar4[9] == '\0') {
      return;
    }
    if (iVar6 != 2) {
      uStack_38 = FUN_40109eec(*(undefined4 *)(puVar5 + 0x24));
      uStack_24 = 0;
      uStack_2c = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      uStack_28 = 0;
      memw();
      memw();
      FUN_4010a9fc(iVar6,&uStack_38);
    }
    iVar6 = iVar6 + 1;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 4;
  } while (iVar6 != 3);
  return;
}

