// Function : FUN_4013572c
// Address  : 0x4013572c
// Size     : 36 bytes


int FUN_4013572c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_4013167c(param_1,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_4013167c(param_1 + 0xc,param_2 + 0xc), iVar1 == 0)) {
    iVar1 = FUN_4013167c(param_1 + 0x18,param_2 + 0x18);
  }
  return iVar1;
}

