// Function : FUN_40101ff8
// Address  : 0x40101ff8
// Size     : 92 bytes


int FUN_40101ff8(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_2c [44];
  
  FUN_40138f64(auStack_2c);
  iVar1 = FUN_40138f28(param_1);
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = FUN_4013905c(auStack_2c,iVar1,0);
    if ((iVar2 == 0) && (iVar2 = FUN_40139114(auStack_2c), iVar2 == 0)) {
      for (iVar1 = 0; iVar1 != param_2; iVar1 = iVar1 + 1) {
        iVar2 = FUN_40139174(auStack_2c,*(undefined4 *)(param_3 + iVar1 * 4),
                             *(undefined4 *)(param_4 + iVar1 * 4));
        if (iVar2 != 0) goto LAB_40102030;
      }
      iVar2 = FUN_401391c4(auStack_2c,param_5);
    }
LAB_40102030:
    FUN_40138f78(auStack_2c);
  }
  return iVar2;
}

