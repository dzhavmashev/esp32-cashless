// Function : FUN_40135764
// Address  : 0x40135764
// Size     : 34 bytes


int FUN_40135764(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40131700(param_1,1);
  if ((iVar1 == 0) && (iVar1 = FUN_40131700(param_1 + 0xc,1), iVar1 == 0)) {
    iVar1 = FUN_40131700(param_1 + 0x18,0);
  }
  return iVar1;
}

