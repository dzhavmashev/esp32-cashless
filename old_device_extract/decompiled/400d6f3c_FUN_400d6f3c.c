// Function : FUN_400d6f3c
// Address  : 0x400d6f3c
// Size     : 130 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d6f3c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_34 [2];
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490," bytes\n");
  uVar2 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  FUN_400d9fc4(*(undefined4 *)(param_1 + 0xc));
  uStack_28 = 0x400d8480;
  puStack_2c = &LAB_40183d34;
  aiStack_34[0] = param_1;
  FUN_400da380(*(undefined4 *)(param_1 + 0xc),aiStack_34);
  (*(code *)&LAB_40183a17_1)(aiStack_34);
  FUN_400e7730(*(undefined4 *)(param_1 + 0x18),3);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    (*(code *)&LAB_40183a17_1)(aiStack_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

