// Function : FUN_400d3a14
// Address  : 0x400d3a14
// Size     : 27 bytes


void FUN_400d3a14(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 auStack_24 [36];
  
  iVar1 = param_1;
  auStack_24[0] = param_2;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = FUN_40170584(param_1);
  }
  (**(code **)(param_1 + 0xc))(iVar1,auStack_24);
  return;
}

