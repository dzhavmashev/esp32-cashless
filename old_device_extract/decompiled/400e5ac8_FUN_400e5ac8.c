// Function : FUN_400e5ac8
// Address  : 0x400e5ac8
// Size     : 491 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e5ac8(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined8 uStack_268;
  undefined1 auStack_260 [16];
  undefined1 auStack_250 [24];
  undefined1 auStack_238 [532];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"re_size");
  if (*(int *)(param_1 + 0x1d8) != 0) {
    uStack_268._0_4_ = CONCAT31(uStack_268._1_3_,1);
    (**(code **)(param_1 + 0x1dc))(param_1 + 0x1d0,&uStack_268,param_1 + 0x3c);
  }
  FUN_40183bd4(auStack_250);
  puVar1 = (undefined1 *)FUN_400d4db0(auStack_238,"lient: ");
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[8] = puVar1[8] & 0x80 | 6;
    *puVar1 = 1;
  }
  FUN_400e6d7c(auStack_260,*(undefined4 *)(param_1 + 0xf8));
  uStack_268._0_4_ = FUN_400d4db0(auStack_238,"trieved",auStack_250);
  uStack_268._4_4_ = auStack_250;
  FUN_40183db8(auStack_260,(undefined4)uStack_268,auStack_250);
  FUN_400f0a50(auStack_260);
  uStack_268._0_4_ = FUN_400d4db0(auStack_238,"rotocol version",auStack_250);
  uStack_268._4_4_ = auStack_250;
  FUN_40183db8(param_1 + 0x3c,(undefined4)uStack_268,auStack_250);
  uStack_268._0_4_ = FUN_400d4db0(auStack_238,"ware...",auStack_250);
  uStack_268._4_4_ = auStack_250;
  FUN_40183db8(param_1 + 0x1c,(undefined4)uStack_268,auStack_250);
  iVar2 = FUN_400f1a9c();
  iVar4 = *(int *)(param_1 + 0x1f8);
  puVar3 = (uint *)FUN_400d4db0(auStack_238,"version",auStack_250);
  if (puVar3 != (uint *)0x0) {
    *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x80 | 8;
    *puVar3 = (uint)(iVar2 - iVar4) / 1000;
    puVar3[1] = 0;
  }
  puVar1 = (undefined1 *)FUN_400d4db0(auStack_238,"seconds");
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[8] = puVar1[8] & 0x80 | 6;
    *puVar1 = 1;
  }
  FUN_400f0be8(auStack_260,"equired");
  uStack_268 = FUN_401841b0(auStack_250);
  FUN_400e58d4(param_1,auStack_260,&uStack_268);
  FUN_400f0a50(auStack_260);
  FUN_400e53ac(param_1);
  FUN_400f0780(0x3ffc5490,"_result");
  FUN_400e4b9c(param_1,6);
  iVar2 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(&stack0x3ffc56e8);
    thunk_FUN_401710d8(iVar2);
  }
  return;
}

