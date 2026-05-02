// Function : FUN_40102058
// Address  : 0x40102058
// Size     : 95 bytes


int FUN_40102058(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                int param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2c [44];
  
  FUN_40138f64(auStack_2c);
  iVar1 = FUN_40138f28(param_1);
  iVar2 = -1;
  if (((iVar1 != 0) && (iVar2 = FUN_4013905c(auStack_2c,iVar1,1), iVar2 == 0)) &&
     (iVar2 = FUN_40139270(auStack_2c,param_2,param_3), iVar2 == 0)) {
    for (iVar1 = 0; iVar1 != param_4; iVar1 = iVar1 + 1) {
      iVar2 = FUN_4013935c(auStack_2c,*(undefined4 *)(param_5 + iVar1 * 4),
                           *(undefined4 *)(param_6 + iVar1 * 4));
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = FUN_4013937c(auStack_2c,param_7);
    FUN_40138f78(auStack_2c);
  }
  return iVar2;
}

