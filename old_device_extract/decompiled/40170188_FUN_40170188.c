// Function : FUN_40170188
// Address  : 0x40170188
// Size     : 32 bytes


int FUN_40170188(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_40170108(*(undefined4 *)(param_1 + 4),param_2[1]);
  if ((iVar1 == 0) && (param_4 < 4)) {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2,param_1,param_3);
  }
  return iVar1;
}

