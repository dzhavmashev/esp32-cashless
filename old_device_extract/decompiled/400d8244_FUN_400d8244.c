// Function : FUN_400d8244
// Address  : 0x400d8244
// Size     : 446 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d8244(int param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint in_t0;
  byte abStack_b8 [4];
  byte bStack_b4;
  int aiStack_34 [2];
  undefined1 *puStack_2c;
  undefined *puStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"machine");
  FUN_400d7d34(param_1,0);
  FUN_400e7714(*(undefined4 *)(param_1 + 0x18));
  FUN_400e7730(*(undefined4 *)(param_1 + 0x18),3);
  FUN_400d909c(*(undefined4 *)(param_1 + 8));
  FUN_400e712c(*(undefined4 *)(param_1 + 0x1c));
  FUN_400d9b74(abStack_b8,*(undefined4 *)(param_1 + 8));
  iVar1 = 0x3ffc5490;
  uVar2 = (uint)abStack_b8[0];
  if (((uVar2 != 2 & bStack_b4) != 0) && (1 < (uVar2 - 4 & 0xff))) {
    FUN_400e6370(0x3ffc4cec,0x1b,0xe);
    puStack_28 = &DAT_400d6d34;
    puStack_2c = (undefined1 *)0x40183cd4;
    aiStack_34[0] = param_1;
    FUN_400d7570(0x3ffc4d38,aiStack_34);
    (*(code *)&LAB_40183a17_1)(aiStack_34);
    puStack_28 = (undefined *)0x400d6d5c;
    puStack_2c = (undefined1 *)0x40183cec;
    aiStack_34[0] = param_1;
    FUN_400d7570(0x3ffc4d48,aiStack_34);
    (*(code *)&LAB_40183a17_1)(aiStack_34);
    puStack_28 = (undefined *)0x400d8d60;
    puStack_2c = &LAB_40183d04;
    aiStack_34[0] = param_1;
    FUN_400d74fc(0x3ffc4d18,aiStack_34);
    (*(code *)&LAB_40183a17_1)(aiStack_34);
    puStack_28 = (undefined *)0x400d8e14;
    puStack_2c = &LAB_40183d1c;
    aiStack_34[0] = param_1;
    FUN_400d74fc(0x3ffc4d28,aiStack_34);
    (*(code *)&LAB_40183a17_1)(aiStack_34);
    iVar1 = 0x3ffc5490;
    pcVar3 = "ization";
    *(undefined1 *)(param_1 + 0x2c) = 1;
    goto LAB_400d8375;
  }
  while( true ) {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    pcVar3 = "in use)";
    if ((uVar2 != 4) && (pcVar3 = "instead", uVar2 != 5)) {
      pcVar3 = "atively";
    }
LAB_400d8375:
    uVar2 = in_t0;
    FUN_400f0780(iVar1,pcVar3);
    FUN_400e65a8(0x3ffc4d58,0x21);
    FUN_400f0780(iVar1,"ned off");
    FUN_400f1960(0x13,3);
    FUN_400f1a40(0x13,1);
    FUN_400f0780(iVar1,"ecovery");
    FUN_400d6e2c(param_1);
    FUN_400d8184(param_1);
    FUN_400f0780(iVar1," power)");
    iVar1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    param_1 = 1;
    in_t0 = uVar2;
  }
  return;
}

