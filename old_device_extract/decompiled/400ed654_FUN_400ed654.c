// Function : FUN_400ed654
// Address  : 0x400ed654
// Size     : 31 bytes


void FUN_400ed654(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  iVar1 = param_1;
  uStack_28 = param_3;
  auStack_24[0] = param_2;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = FUN_40170584(param_1);
  }
  (**(code **)(param_1 + 0xc))(iVar1,auStack_24,&uStack_28);
  return;
}

