// Function : FUN_401441e4
// Address  : 0x401441e4
// Size     : 51 bytes


undefined4 FUN_401441e4(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = param_2 + 0x84;
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 0x10) == 0) break;
    if ((*(int *)(param_1 + 0x24) == *(int *)(param_2 + 0x10)) &&
       (iVar1 = (*(code *)&SUB_4008b33c)
                          (*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_2 + 0x14)),
       iVar1 == 0)) {
      return 1;
    }
    param_2 = *(int *)(param_2 + 0x3c);
  }
  return 0;
}

