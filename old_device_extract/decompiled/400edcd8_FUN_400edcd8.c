// Function : FUN_400edcd8
// Address  : 0x400edcd8
// Size     : 222 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400edcd8(int param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 ****ppppuVar5;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined1 *)(param_1 + 0x9c) = 0;
    FUN_400eda70(param_1);
  }
  *(undefined4 *)(param_1 + 8) = param_2;
  iVar2 = FUN_400f13f0(param_3,0x3a);
  if (-1 < iVar2) {
    FUN_400f1520(local_44,param_3,0,iVar2);
    iVar2 = FUN_400f11c0(local_44,"n");
    if ((iVar2 == 0) && (iVar3 = FUN_400f11c0(local_44,"r"), iVar2 = 0, iVar3 == 0))
    goto LAB_400edd5b;
    iVar2 = FUN_400f11c0(local_44,"r");
    uVar4 = 0x50;
    if (iVar2 != 0) {
      uVar4 = 0x1bb;
    }
    *(undefined2 *)(param_1 + 0x1c) = uVar4;
    uVar1 = FUN_400f11c0(local_44,"r");
    while( true ) {
      *(undefined1 *)(param_1 + 0x29) = uVar1;
      FUN_400f0d4c(auStack_34,param_3);
      ppppuVar5 = local_44;
      if ((bStack_35 & 0x80) == 0) {
        ppppuVar5 = (undefined4 ****)local_44[0];
      }
      iVar2 = FUN_400eda84(param_1,auStack_34,ppppuVar5);
      FUN_400f0a50(auStack_34);
LAB_400edd5b:
      FUN_400f0a50(local_44);
      param_1 = iVar2;
LAB_400edd64:
      param_3 = iStack_24;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) break;
      uVar1 = func_0x40082ecc();
    }
    return;
  }
  param_1 = 0;
  goto LAB_400edd64;
}

