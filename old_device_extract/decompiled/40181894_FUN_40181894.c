// Function : FUN_40181894
// Address  : 0x40181894
// Size     : 36 bytes


undefined4 FUN_40181894(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_3 + 8) == 0) {
    *(undefined4 *)(param_3 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_4008a9b8)(param_1,param_2,param_3);
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined4 *)(param_3 + 4) = 0;
  }
  return uVar1;
}

