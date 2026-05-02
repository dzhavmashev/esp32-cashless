// Function : FUN_4013d32c
// Address  : 0x4013d32c
// Size     : 45 bytes


int FUN_4013d32c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  iVar1 = FUN_4013173c(auStack_2c,param_3 << 6,1);
  if (iVar1 == 0) {
    iVar1 = FUN_401320e0(param_1,auStack_2c,param_2);
  }
  FUN_40131548(auStack_2c);
  return iVar1;
}

