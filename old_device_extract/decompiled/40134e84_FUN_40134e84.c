// Function : FUN_40134e84
// Address  : 0x40134e84
// Size     : 55 bytes


int FUN_40134e84(int param_1,int param_2,byte param_3)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  param_2 = param_2 + 0xc;
  iVar1 = FUN_40131d30(auStack_2c,param_1 + 4,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40131ad8(param_2,0);
    iVar1 = FUN_4013365c(param_2,auStack_2c,param_3 & iVar1 != 0);
  }
  FUN_40131548(auStack_2c);
  return iVar1;
}

