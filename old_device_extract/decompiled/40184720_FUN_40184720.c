// Function : FUN_40184720
// Address  : 0x40184720
// Size     : 5 bytes


int FUN_40184720(int param_1,undefined1 *param_2,undefined1 *param_3,int *param_4)

{
  int iVar1;
  
  for (; param_2 != param_3; param_2 = param_2 + 1) {
    iVar1 = (**(code **)(*param_4 + 8))(param_4,*param_2);
    param_1 = param_1 + iVar1;
  }
  return param_1;
}

