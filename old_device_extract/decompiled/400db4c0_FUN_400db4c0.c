// Function : FUN_400db4c0
// Address  : 0x400db4c0
// Size     : 255 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400db4c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 ****ppppuVar3;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400da4f0(param_1);
  if (iVar1 != 0) {
    FUN_400f0be8(auStack_34,"LS: %s\n");
    uVar2 = FUN_400f10c0(auStack_34,param_1 + 0x7e4);
    uVar2 = FUN_400f10f0(uVar2,"nnected");
    FUN_400f0d4c(local_44,uVar2);
    FUN_400f0a50(auStack_34);
    ppppuVar3 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar3 = (undefined4 ****)local_44[0];
    }
    FUN_400eb39c(param_1,ppppuVar3,1,1,"d - %s\n");
    FUN_400f0780(0x3ffc5490,"ceful\"}");
    FUN_400ead50(param_1,0);
    FUN_400db344(param_1 + 0x830);
    FUN_400f0be8(auStack_34," status");
    FUN_400da604(param_1,0,auStack_34);
    FUN_400f0a50(auStack_34);
    FUN_400f0780(0x3ffc5490,"nnected");
    FUN_400f0a50(local_44);
  }
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      thunk_FUN_401710d8(iVar1);
      FUN_400f0a50(auStack_34);
      FUN_400f0a50(local_44);
    } while( true );
  }
  return;
}

