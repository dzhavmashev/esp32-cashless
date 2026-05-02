// Function : FUN_40124328
// Address  : 0x40124328
// Size     : 41 bytes


undefined4 FUN_40124328(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x30;
  while( true ) {
    if (*(int *)(param_1 + 8) == 0) {
      return 0;
    }
    iVar1 = (*(code *)&SUB_4008b33c)(param_2,param_1,8);
    if (iVar1 == 0) break;
    param_1 = param_1 + 0xc;
    if (param_1 == iVar2) {
      return 0;
    }
  }
  return 1;
}

