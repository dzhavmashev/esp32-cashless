// Function : FUN_400e6fe4
// Address  : 0x400e6fe4
// Size     : 40 bytes


int FUN_400e6fe4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (*(code *)&LAB_40183a7b_1)(param_1 + 8);
  iVar2 = (*(code *)&LAB_40183a7b_1)(param_1 + 0x18);
  iVar3 = (*(code *)&LAB_40183a7b_1)(param_1 + 0x28);
  return iVar1 + iVar2 + iVar3;
}

