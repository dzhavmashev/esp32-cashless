// Function : FUN_4010151c
// Address  : 0x4010151c
// Size     : 49 bytes


undefined4 FUN_4010151c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar1 = 0x5001;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = *param_2;
    *(undefined4 *)(param_1 + 0x28) = param_2[1];
    uVar1 = param_2[3];
    *(undefined4 *)(param_1 + 0x2c) = param_2[2];
    *(undefined4 *)(param_1 + 0x30) = uVar1;
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

