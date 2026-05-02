// Function : FUN_400dae70
// Address  : 0x400dae70
// Size     : 244 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dae70(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  iVar4 = param_1 + 0x7e4;
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400da468(iVar4);
  iVar3 = 0x3ffc5490;
  if (iVar1 == 0) goto LAB_400daeb5;
  FUN_400f0780(0x3ffc5490,"ificate");
  param_1 = 0;
  while( true ) {
    iVar4 = iStack_24;
    iVar3 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400daeb5:
    FUN_400f0be8(auStack_34,"LS: %s\n");
    uVar2 = FUN_400f10c0(auStack_34,iVar4);
    uVar2 = FUN_400f10f0(uVar2,"evices/");
    FUN_400f0d4c(local_44,uVar2);
    FUN_400f0a50(auStack_34);
    ppppuVar5 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar5 = (undefined4 ****)local_44[0];
    }
    FUN_400f06a4(iVar3," empty!",ppppuVar5);
    ppppuVar5 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar5 = (undefined4 ****)local_44[0];
    }
    iVar4 = FUN_400dae18(param_1,ppppuVar5,1);
    if (iVar4 == 0) {
      ppppuVar5 = local_44;
      if (-1 < (char)bStack_35) {
        ppppuVar5 = (undefined4 ****)local_44[0];
      }
      FUN_400f06a4(iVar3,"d: %u)\n",ppppuVar5);
    }
    else {
      ppppuVar5 = local_44;
      if (-1 < (char)bStack_35) {
        ppppuVar5 = (undefined4 ****)local_44[0];
      }
      FUN_400f06a4(iVar3,"ic: %s\n",ppppuVar5,iVar4);
    }
    param_1 = (uint)(iVar4 != 0);
    FUN_400f0a50(local_44);
  }
  return;
}

