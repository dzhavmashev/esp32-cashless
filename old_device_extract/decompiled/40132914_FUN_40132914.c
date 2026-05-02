// Function : FUN_40132914
// Address  : 0x40132914
// Size     : 83 bytes


int FUN_40132914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = *(undefined4 *)(param_1 + 4);
  uStack_24 = *(undefined4 *)(param_1 + 8);
  uStack_2c = 1;
  memw();
  iVar1 = FUN_40131ad8(&uStack_2c,0);
  iVar2 = -0xe;
  if (iVar1 != 0) {
    iVar1 = FUN_40131ad8(&uStack_2c,1);
    iVar2 = -0xe;
    if (iVar1 != 0) {
      iVar1 = FUN_40131ad8(&uStack_2c,2);
      if (iVar1 != 0) {
        iVar1 = FUN_40132144(&uStack_2c);
        if (iVar1 == 0) {
          iVar1 = FUN_401323d8(&uStack_2c,param_2,param_3,param_4);
          return iVar1;
        }
        if (iVar1 != 1) {
          return iVar1;
        }
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}

