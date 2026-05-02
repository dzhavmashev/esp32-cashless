// Function : FUN_40134ebc
// Address  : 0x40134ebc
// Size     : 60 bytes


int FUN_40134ebc(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_40131d30(param_2,param_3,param_4);
  iVar2 = iVar1;
  while (((iVar2 == 0 && (iVar2 = iVar1, *param_2 < 0)) &&
         (iVar3 = FUN_40131ad8(param_2,0), iVar3 != 0))) {
    iVar2 = FUN_40131d18(param_2,param_2,param_1 + 4);
  }
  return iVar2;
}

