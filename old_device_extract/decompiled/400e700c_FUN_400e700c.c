// Function : FUN_400e700c
// Address  : 0x400e700c
// Size     : 262 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e700c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  char *pcVar5;
  undefined4 ***local_4c [3];
  byte bStack_3d;
  undefined4 ***local_3c [3];
  byte bStack_2d;
  char cStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490,"ewlines");
  iVar1 = FUN_400e6a84(param_1);
  iVar3 = 0x3ffc5490;
  if (iVar1 != 0) goto LAB_400e7059;
  FUN_400f0780(0x3ffc5490,"tus ===");
  while( true ) {
    iVar3 = iStack_24;
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400e7059:
    FUN_400f0780(iVar3," stored");
    FUN_400e6c2c(local_4c,param_1);
    ppppuVar4 = local_4c;
    if ((bStack_3d & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_4c[0];
    }
    FUN_400f06a4(iVar3,"ailable",ppppuVar4);
    ppppuVar4 = local_3c;
    if ((bStack_2d & 0x80) == 0) {
      ppppuVar4 = (undefined4 ****)local_3c[0];
    }
    FUN_400f06a4(iVar3,"ct: %s\n",ppppuVar4);
    pcVar5 = "n error";
    if (cStack_2c == '\0') {
      pcVar5 = "ror";
    }
    FUN_400f06a4(iVar3,"er: %s\n",pcVar5);
    FUN_400f06a4(iVar3,"id: %s\n",uStack_28);
    uVar2 = FUN_400e6ab4(param_1);
    FUN_400f06a4(iVar3,"ry: %d\n",uVar2);
    uVar2 = FUN_400e6fe4(param_1);
    FUN_400f06a4(iVar3,"lt: %d\n",uVar2);
    FUN_400f0780(iVar3," bytes\n");
    FUN_400f0a50(local_3c);
    FUN_400f0a50(local_4c);
  }
  return;
}

