// Function : FUN_401052f0
// Address  : 0x401052f0
// Size     : 42 bytes


void FUN_401052f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_401052d0(param_2);
  if ((iVar1 != 0) && (param_1 != 0)) {
    iVar2 = *(int *)(iVar1 + 4);
    *(int *)(iVar1 + 4) = param_2 + iVar2;
    memw();
    (*(code *)&SUB_4008b3d0)(*(int *)(iVar1 + 8) + iVar2,param_1,param_2);
  }
  return;
}

