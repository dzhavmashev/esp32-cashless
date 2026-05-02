// Function : FUN_400eadb0
// Address  : 0x400eadb0
// Size     : 27 bytes


void FUN_400eadb0(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 auStack_24 [18];
  
  iVar1 = param_1;
  auStack_24[0] = param_2;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = FUN_40170584(param_1);
  }
  (**(code **)(param_1 + 0xc))(iVar1,auStack_24);
  return;
}

