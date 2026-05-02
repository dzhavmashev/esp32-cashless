// Function : FUN_400d9908
// Address  : 0x400d9908
// Size     : 251 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d9908(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  undefined4 ***local_34 [3];
  byte bStack_25;
  undefined4 ***pppuStack_24;
  
  memw();
  memw();
  pppuStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e6a84(0x3ffc4d78);
  iVar2 = param_2 + 0x54;
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"ificate");
    FUN_400f0d70(iVar2,&DAT_3f42161d);
  }
  else {
    FUN_400e6d7c(local_34,0x3ffc4d78);
    iVar1 = (*(code *)&LAB_40183a7b_1)(local_34);
    if (iVar1 == 0) {
      FUN_400f0780(0x3ffc5490,"ificate");
      FUN_400f0d70(iVar2,&DAT_3f42161d);
    }
    else {
      FUN_400f0d18(iVar2,local_34);
      ppppuVar3 = local_34;
      if ((bStack_25 & 0x80) == 0) {
        ppppuVar3 = (undefined4 ****)local_34[0];
      }
      FUN_400f06a4(0x3ffc5490,"uration",ppppuVar3);
    }
    FUN_400f0a50(local_34);
  }
  FUN_400f0d4c(param_1,param_2 + 0x3c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x4c);
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)(param_2 + 0x50);
  FUN_400f0d4c(param_1 + 0x18,iVar2);
  ppppuVar3 = (undefined4 ****)pppuStack_24;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_2 + 100);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_2 + 0x68);
  *(undefined1 *)(param_1 + 0x30) = *(undefined1 *)(param_2 + 0x6c);
  memw();
  memw();
  if ((undefined4 ****)pppuStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    do {
      FUN_400f0a50(ppppuVar3);
      thunk_FUN_401710d8(param_1);
      ppppuVar3 = local_34;
    } while( true );
  }
  return;
}

