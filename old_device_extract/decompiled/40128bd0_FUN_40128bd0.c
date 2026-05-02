// Function : FUN_40128bd0
// Address  : 0x40128bd0
// Size     : 35 bytes


int FUN_40128bd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4013167c(param_3,param_1);
  iVar2 = -1;
  if (iVar1 == 0) {
    iVar1 = FUN_40131a34(param_3,param_2);
    iVar2 = -(uint)(iVar1 != 0);
  }
  return iVar2;
}

