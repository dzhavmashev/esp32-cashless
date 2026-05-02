// Function : FUN_400e645c
// Address  : 0x400e645c
// Size     : 26 bytes


void FUN_400e645c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_24 [9];
  
  iVar1 = param_1;
  auStack_24[0] = param_2;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = FUN_40170584(param_1);
  }
  (**(code **)(param_1 + 0xc))(iVar1,auStack_24);
  return;
}

