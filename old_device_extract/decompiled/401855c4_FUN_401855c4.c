// Function : FUN_401855c4
// Address  : 0x401855c4
// Size     : 38 bytes


undefined4 FUN_401855c4(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1[7] != 0) && (((*param_1 | param_1[1] | param_1[2]) & param_2) == param_2)) {
    uVar1 = 1;
  }
  return uVar1;
}

