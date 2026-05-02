// Function : FUN_40185a28
// Address  : 0x40185a28
// Size     : 23 bytes


undefined4 FUN_40185a28(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *param_1;
  }
  else if (param_2 == 4) {
    uVar1 = param_1[1];
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

