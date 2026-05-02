// Function : FUN_400d6e9c
// Address  : 0x400d6e9c
// Size     : 127 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d6e9c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 ****ppppuVar4;
  undefined4 ***local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400d6e8c(local_34,param_1);
  ppppuVar4 = local_34;
  if ((bStack_25 & 0x80) == 0) {
    ppppuVar4 = (undefined4 ****)local_34[0];
  }
  uVar2 = FUN_400f1a9c();
  uVar3 = FUN_400efe4c(0x3ffc53f4);
  FUN_400f06a4(0x3ffc5490,"ALIZING",ppppuVar4,uVar2 / 1000,uVar3);
  FUN_400f0a50(local_34);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(local_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

