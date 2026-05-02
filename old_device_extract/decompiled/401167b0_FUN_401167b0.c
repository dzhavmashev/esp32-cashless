// Function : FUN_401167b0
// Address  : 0x401167b0
// Size     : 38 bytes


int FUN_401167b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) ||
     (((*param_1 == 0 || (iVar1 = FUN_401166e8(param_1,param_2), iVar2 = 0, iVar1 != 0)) &&
      (iVar2 = FUN_40116720(param_1,param_2), iVar2 == 0)))) {
    iVar2 = FUN_40116748(param_2);
  }
  return iVar2;
}

