// Function : FUN_40128ef0
// Address  : 0x40128ef0
// Size     : 40 bytes


int FUN_40128ef0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  param_2 = param_2 + 0xc;
  iVar1 = FUN_40131ad8(param_2,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = FUN_40131d30(param_2,param_1 + 4,param_2);
    iVar2 = -(uint)(iVar2 != 0);
  }
  return iVar2;
}

