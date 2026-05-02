// Function : FUN_40128b74
// Address  : 0x40128b74
// Size     : 40 bytes


int FUN_40128b74(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4013d5d8(param_4,param_1,param_2);
  iVar2 = -1;
  if (iVar1 == 0) {
    iVar1 = FUN_401320e0(param_4,param_4,param_3);
    iVar2 = -(uint)(iVar1 != 0);
  }
  return iVar2;
}

