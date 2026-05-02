// Function : FUN_400e5cb4
// Address  : 0x400e5cb4
// Size     : 512 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e5cb4(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined8 uStack_268;
  undefined1 auStack_260 [16];
  undefined1 auStack_250 [24];
  undefined1 auStack_238 [532];
  int iStack_24;
  
  memw();
  pbVar3 = (byte *)(param_1 + 0x200);
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(char *)(param_1 + 0x202) == '\0') {
    *(undefined1 *)(param_1 + 0x202) = 1;
    if (*(int *)(param_1 + 0x1e8) != 0) {
      uStack_268._0_4_ = *(undefined4 *)(param_1 + 8);
      (**(code **)(param_1 + 0x1ec))(param_1 + 0x1e0,&uStack_268,param_1 + 0xc);
    }
    FUN_40183bd4(auStack_250);
    FUN_400e6d7c(auStack_260,*(undefined4 *)(param_1 + 0xf8));
    uStack_268._0_4_ = FUN_400d4db0(auStack_238,"trieved",auStack_250);
    uStack_268._4_4_ = auStack_250;
    FUN_40183db8(auStack_260,(undefined4)uStack_268,auStack_250);
    FUN_400f0a50(auStack_260);
    uStack_268._0_4_ = FUN_400d4db0(auStack_238,"rotocol version",auStack_250);
    uStack_268._4_4_ = auStack_250;
    FUN_40183db8(param_1 + 0x3c,(undefined4)uStack_268,auStack_250);
    FUN_400e4a88(auStack_260,*(undefined4 *)(param_1 + 8));
    uStack_268._0_4_ = FUN_400d4db0(auStack_238,"onds...",auStack_250);
    uStack_268._4_4_ = auStack_250;
    FUN_40183db8(auStack_260,(undefined4)uStack_268,auStack_250);
    FUN_400f0a50(auStack_260);
    uStack_268._0_4_ = FUN_400d4db0(auStack_238,"or_code",auStack_250);
    uStack_268._4_4_ = auStack_250;
    FUN_40183db8(param_1 + 0xc,(undefined4)uStack_268,auStack_250);
    bVar1 = *pbVar3;
    iVar2 = FUN_400d4db0(auStack_238,"message",auStack_250);
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) & 0x80 | 6;
      *(bool *)iVar2 = bVar1 < 3;
    }
    FUN_400f0be8(auStack_260,"ossible");
    uStack_268 = FUN_401841b0(auStack_250);
    FUN_400e58d4(param_1,auStack_260,&uStack_268);
    FUN_400f0a50(auStack_260);
    if ((*pbVar3 < 3) && (*(int *)(param_1 + 4) == 3)) {
      *pbVar3 = *pbVar3 + 1;
      FUN_400f06a4(0x3ffc5490,"a_error",5000);
    }
  }
  if (2 < (byte)(*pbVar3 - 1)) goto LAB_400e5e94;
  if (*(int *)(param_1 + 4) != 3) goto LAB_400e5e94;
  iVar2 = FUN_400f1a9c();
  if (4999 < (uint)(iVar2 - *(int *)(param_1 + 0x1f8))) {
    FUN_400e4b9c(param_1,3);
  }
  while( true ) {
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400e5e94:
    FUN_400f0780(0x3ffc5490,"%d/%d)\n");
    FUN_400e4b9c(param_1,0);
    *pbVar3 = 0;
  }
  return;
}

