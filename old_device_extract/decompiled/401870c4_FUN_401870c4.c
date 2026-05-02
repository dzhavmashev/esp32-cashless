// Function : FUN_401870c4
// Address  : 0x401870c4
// Size     : 38 bytes


uint FUN_401870c4(int *param_1)

{
  uint uVar1;
  byte abStack_21 [33];
  
  abStack_21[0] = 0;
  uVar1 = (**(code **)(*param_1 + 0x38))(param_1,abStack_21,1);
  if (-1 < (int)uVar1) {
    if (uVar1 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (uint)abStack_21[0];
    }
  }
  return uVar1;
}

