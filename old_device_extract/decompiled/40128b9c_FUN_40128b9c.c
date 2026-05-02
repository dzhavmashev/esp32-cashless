// Function : FUN_40128b9c
// Address  : 0x40128b9c
// Size     : 52 bytes


int FUN_40128b9c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40128a18();
  iVar2 = -1;
  if (iVar1 != 0) {
    FUN_4013167c(iVar1,param_1);
    iVar2 = FUN_40128b74(param_1,iVar1,param_2,param_3);
    FUN_40128a7c(iVar1,0);
    iVar2 = -(uint)(iVar2 != 0);
  }
  return iVar2;
}

