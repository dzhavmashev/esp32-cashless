// Function : FUN_400faed4
// Address  : 0x400faed4
// Size     : 35 bytes


undefined4 FUN_400faed4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0x1107;
    }
    if (param_2 == iVar1) break;
    iVar1 = *(int *)(iVar1 + 8);
  }
  FUN_40184994(param_1 + 4);
  return 0;
}

