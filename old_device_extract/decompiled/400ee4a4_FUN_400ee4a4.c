// Function : FUN_400ee4a4
// Address  : 0x400ee4a4
// Size     : 319 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ee4a4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int extraout_a3;
  undefined4 ****ppppuVar3;
  int iVar4;
  char cStack_36;
  char cStack_35;
  undefined4 ***local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = -6;
  if (param_2 == 0) goto LAB_400ee506;
  iVar1 = (*(code *)&LAB_40184637_1)(param_1,0xfffffffa);
  iVar4 = -4;
  iVar2 = iVar4;
  if (iVar1 == 0) goto LAB_400ee506;
  if (*(int *)(param_1 + 0xb8) != 0) {
    if (*(int *)(param_1 + 0xb8) == 1) {
      param_4 = 0;
      iVar2 = 0;
      goto LAB_400ee4fa;
    }
    iVar2 = -9;
    goto LAB_400ee506;
  }
  iVar2 = FUN_400ee394(param_1,param_2,*(undefined4 *)(param_1 + 0x98));
  if (iVar2 < 0) goto LAB_400ee506;
LAB_400ee4e0:
  FUN_400eda0c(param_1,1);
  param_1 = iVar2;
LAB_400ee5be:
  do {
    iVar2 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
    while( true ) {
      FUN_400f0a50(local_34);
      iVar4 = extraout_a3;
LAB_400ee4fa:
      iVar4 = (*(code *)&LAB_40184637_1)(param_1,iVar4);
      if (iVar4 == 0) break;
      FUN_400f08c0(local_34,*(undefined4 *)(param_1 + 8),10);
      iVar4 = (*(code *)&LAB_40183a7b_1)(local_34);
      if (iVar4 == 0) goto LAB_400ee52a;
      FUN_400f17d0(local_34);
      ppppuVar3 = local_34;
      if ((bStack_25 & 0x80) == 0) {
        ppppuVar3 = (undefined4 ****)local_34[0];
      }
      iVar4 = func_0x4008cbe4(ppppuVar3,0,0x10);
      param_4 = param_4 + iVar4;
      if (iVar4 < 1) {
        if (*(int *)(param_1 + 0x98) < 1) {
          *(int *)(param_1 + 0x98) = param_4;
        }
        iVar4 = -10;
        if (*(int *)(param_1 + 0x98) != iVar2) goto LAB_400ee562;
        FUN_400f0a50(local_34,0xfffffff6);
        goto LAB_400ee4e0;
      }
      iVar4 = FUN_400ee394(param_1,param_2,iVar4);
      if (iVar4 < 0) goto LAB_400ee562;
      iVar2 = iVar2 + iVar4;
      iVar4 = (**(code **)(**(int **)(param_1 + 8) + 0x28))(*(int **)(param_1 + 8),&cStack_36,2);
      if (((iVar4 != 2) || (cStack_36 != '\r')) || (cStack_35 != '\n')) goto LAB_400ee52a;
      FUN_400f1ab4(0);
    }
    iVar2 = -5;
LAB_400ee506:
    param_1 = FUN_400ee484(param_1,iVar2);
  } while( true );
LAB_400ee52a:
  iVar4 = -0xb;
LAB_400ee562:
  param_1 = FUN_400ee484(param_1,iVar4);
  FUN_400f0a50(local_34);
  goto LAB_400ee5be;
}

