// Function : FUN_400da510
// Address  : 0x400da510
// Size     : 217 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_400da510(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 ****ppppuVar4;
  char *pcVar5;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  iVar2 = FUN_400da4f0(param_1);
  if (iVar2 != 0) goto LAB_400da555;
  FUN_400f0780(0x3ffc5490,"ully");
  bVar1 = false;
  while( true ) {
    param_1 = piStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400da555:
    FUN_400f0be8(auStack_34,"LS: %s\n");
    uVar3 = FUN_400f10c0(auStack_34,param_1 + 0x1f9);
    uVar3 = FUN_400f10f0(uVar3,"nnected");
    FUN_400f0d4c(local_44,uVar3);
    FUN_400f0a50(auStack_34);
    ppppuVar4 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_44[0];
    }
    if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
      param_2 = (int *)*param_2;
    }
    iVar2 = FUN_400eb39c(param_1,ppppuVar4,1,1,param_2);
    ppppuVar4 = local_44;
    if ((bStack_35 & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_44[0];
    }
    pcVar5 = "ssfully";
    if (iVar2 == 0) {
      pcVar5 = "al key, failed";
    }
    FUN_400f06a4(0x3ffc5490,"/status",ppppuVar4,pcVar5);
    bVar1 = iVar2 != 0;
    FUN_400f0a50(local_44);
  }
  return bVar1;
}

