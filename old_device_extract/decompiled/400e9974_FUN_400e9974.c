// Function : FUN_400e9974
// Address  : 0x400e9974
// Size     : 40 bytes


int FUN_400e9974(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (((char)param_1[8] != '\0') && (iVar1 = FUN_400eaa88(param_1[0xb],param_2,param_3), iVar1 < 0))
  {
    (**(code **)(*param_1 + 0x3c))(param_1);
    iVar1 = 0;
  }
  return iVar1;
}

