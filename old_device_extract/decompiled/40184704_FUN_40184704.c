// Function : FUN_40184704
// Address  : 0x40184704
// Size     : 28 bytes


int FUN_40184704(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = param_2 + param_3;
  iVar1 = 0;
  for (; param_2 != puVar3; param_2 = param_2 + 1) {
    iVar2 = (**(code **)(*param_1 + 8))(param_1,*param_2);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}

