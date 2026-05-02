// Function : FUN_40104dcc
// Address  : 0x40104dcc
// Size     : 55 bytes


undefined4 FUN_40104dcc(int param_1,undefined1 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((*(uint *)(param_1 + 0x1f0) & 0xc00) != 0) && (*(int *)(param_1 + 0x200) - 1U < 2)) &&
     (uVar1 = 0xffffffff, 2 < param_3)) {
    *param_2 = 0xf4;
    uVar1 = 3;
    param_2[1] = 1;
    param_2[2] = 0x20;
    memw();
  }
  memw();
  return uVar1;
}

