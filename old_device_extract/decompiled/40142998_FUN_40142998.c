// Function : FUN_40142998
// Address  : 0x40142998
// Size     : 54 bytes


int FUN_40142998(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40132c5c(param_2,param_4,1);
  iVar2 = -0xd;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 0x10)) {
    FUN_40132c98(param_1);
    iVar2 = FUN_40133068(param_1,iVar1);
    if (iVar2 == 0) {
      iVar2 = FUN_40132cb4(param_1,param_3,param_4,1);
    }
  }
  return iVar2;
}

