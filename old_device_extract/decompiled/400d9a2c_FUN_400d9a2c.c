// Function : FUN_400d9a2c
// Address  : 0x400d9a2c
// Size     : 306 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d9a2c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400ec7a4(param_1," in SSL config",0);
  FUN_400f0d4c(auStack_34,param_2);
  uVar1 = FUN_400ecdc4(param_1,"efaults",auStack_34);
  FUN_400f0a50(auStack_34);
  uVar2 = FUN_400ecb18(param_1,"_broker",*(undefined4 *)(param_2 + 0x10));
  uVar3 = FUN_400eccc8(param_1,"tt_port",*(undefined1 *)(param_2 + 0x14));
  uVar4 = FUN_400ecb18(param_1,"qtt_tls",*(undefined4 *)(param_2 + 0x28));
  uVar5 = FUN_400ecb18(param_1,"epalive",*(undefined4 *)(param_2 + 0x2c));
  uVar4 = uVar2 & uVar5 & uVar1 & uVar3 & uVar4;
  if ((uVar4 & 1) != 0) {
    iVar6 = param_1 + 0x3c;
    FUN_400f0d18(iVar6,param_2);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x10);
    *(undefined1 *)(param_1 + 0x50) = *(undefined1 *)(param_2 + 0x14);
    FUN_400f0d18(param_1 + 0x54,param_2 + 0x18);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined1 *)(param_1 + 0x6c) = *(undefined1 *)(param_2 + 0x30);
    if ((*(byte *)(param_1 + 0x4b) & 0x80) == 0) {
      iVar6 = *(int *)(param_1 + 0x3c);
    }
    FUN_400f06a4(0x3ffc5490,"ailable",iVar6,*(undefined4 *)(param_1 + 0x4c));
    iVar6 = FUN_400d9a08(param_1);
    puVar7 = &DAT_3f401ac9;
    if (iVar6 == 0) {
      puVar7 = &DAT_3f401ace;
    }
    FUN_400f06a4(0x3ffc5490,"rt: %d\n",puVar7);
  }
  FUN_400ec888(param_1);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(uVar4 & 1);
  }
  return;
}

